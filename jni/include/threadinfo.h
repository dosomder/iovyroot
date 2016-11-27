#ifndef THREADINFO_H
#define THREADINFO_H

//64bit structs according to sources from Z5 Lollipop 32.0.A.6.200
//32bit structs according to sources from Z3C Lollipop 23.4.A.1.200

#if (__LP64__)
#define KERNEL_START 0xffffffc000000000
#define THREAD_SIZE 16384
#else
#define KERNEL_START 0xc0000000
#define THREAD_SIZE 8192
#endif

typedef unsigned int u32;
struct task_struct;
struct thread_info;

struct list_head {
        struct list_head *next, *prev;
};

static inline struct thread_info* get_thread_info(unsigned long sp)
{
	return (struct thread_info*)(sp & ~(THREAD_SIZE - 1));
}

static inline struct thread_info* current_thread_info()
{
	unsigned long sp;
	asm ("mov %[sp], sp" : [sp] "=r" (sp));
	return get_thread_info(sp);
}

static inline int is_cpu_timer_valid(struct list_head* cpu_timer)
{
	if (cpu_timer->next != cpu_timer->prev)
		return 0;

	if ((unsigned long)cpu_timer->next < KERNEL_START)
		return 0;

	return 1;
}

typedef struct {
	int counter;
} atomic_t;

typedef struct kernel_cap_struct {
	__u32 cap[2];
} kernel_cap_t;

struct task_security_struct {
	u32 osid;		/* SID prior to last execve */
	u32 sid;		/* current SID */
	u32 exec_sid;		/* exec SID */
	u32 create_sid;		/* fscreate SID */
	u32 keycreate_sid;	/* keycreate SID */
	u32 sockcreate_sid;	/* fscreate SID */
};

struct task_struct_partial
{
	/* ... */
	struct list_head cpu_timers[3];
	struct cred *real_cred;
	struct cred *cred;
	struct cred *replacement_session_keyring;
	char comm[16];
	/* ... */
};

struct cred {
	atomic_t	usage;
	uid_t		uid;		/* real UID of the task */
	gid_t		gid;		/* real GID of the task */
	uid_t		suid;		/* saved UID of the task */
	gid_t		sgid;		/* saved GID of the task */
	uid_t		euid;		/* effective UID of the task */
	gid_t		egid;		/* effective GID of the task */
	uid_t		fsuid;		/* UID for VFS ops */
	gid_t		fsgid;		/* GID for VFS ops */
	unsigned	securebits;	/* SUID-less security management */
	kernel_cap_t	cap_inheritable; /* caps our children can inherit */
	kernel_cap_t	cap_permitted;	/* caps we're permitted */
	kernel_cap_t	cap_effective;	/* caps we can actually use */
	kernel_cap_t	cap_bset;	/* capability bounding set */
	unsigned char	jit_keyring;	/* default keyring to attach requested
					 * keys to */
#if (__LP64__)
	void	*session_keyring; /* keyring inherited over fork */
	void	*process_keyring; /* keyring private to this process */
	void	*thread_keyring; /* keyring private to this thread */
	void	*request_key_auth; /* assumed request_key authority */
#else
	void	*thread_keyring; /* keyring private to this thread */
	void	*request_key_auth; /* assumed request_key authority */
	void	*tgcred; /* thread-group shared credentials */
#endif
	struct task_security_struct	*security;	/* subjective LSM security */
	/* ... */
};

#if (__LP64__)
struct thread_info {
        unsigned long           flags;          /* low level flags */
        unsigned long           addr_limit;     /* address limit */
        struct task_struct      *task;          /* main task structure */
        /* ... */
};
#else
struct thread_info
{
	unsigned long flags;
	int preempt_count;
	unsigned long addr_limit;
	struct task_struct *task;
	/* ... */
};
#endif

#endif /* THREADINFO_H */
