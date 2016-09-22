#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <inttypes.h>

#include "offsets.h"

#define ARRAYELEMS(a) (sizeof(a) / sizeof(a[0]))

#if (__LP64__)

struct offsets offsets[] = {
    /********************** Nokia **********************/
    //N1 A5CNB19
    { 
        "N1", "Linux version 3.10.62-x86_64_moor (sam@topaz4) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Wed Nov 25 09:29:02 CST 2015",
        (void*)0xffffffff8236c240, (void*)CAPABLE_OFFSET(0xffffffff82f44be0),
        (void*)0xffffffff838d650c, (void*)0xffffffff82f45158, (void*)0xffffffff838d64f0
    },
    //N1 A5FMB19
    { 
        "N1", "Linux version 3.10.62-x86_64_moor (sam@topaz4) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Wed Nov 25 10:05:47 CST 2015",
        (void*)0xffffffff8236c240, (void*)CAPABLE_OFFSET(0xffffffff82f44be0),
        (void*)0xffffffff838d650c, (void*)0xffffffff82f45158, (void*)0xffffffff838d64f0
    },
};

#endif /* (__LP64__) */

#define DEVNAME_LEN 64
#define KERNELVER_LEN 256

static char* get_devname(char* name)
{
	FILE* f;
	char* line;
	static const char* devstr = "ro.product.model=";
	size_t bufsize = 1024;

	if(!name)
		return NULL;

	if(!(f = fopen("/system/build.prop", "r")))
	{
		perror("fopen()");
		return NULL;
	}

	line = malloc(bufsize);
	if (!line) {
		name = NULL;
		goto err_mem_alloc;
	}

	while(getline(&line, &bufsize, f) > 0)
	{
		if(strncmp(line, devstr, strlen(devstr)) == 0)
		{
			strncpy(name, strchr(line, '=') + 1, DEVNAME_LEN - 1);
			if(name[strlen(name) - 1] == '\n')
				name[strlen(name) - 1] = 0;
			goto end;
		}
	}
	name = NULL;

end:
	free(line);
err_mem_alloc:
	fclose(f);
	return name;
}

static char* get_kernelver(char* str)
{
	FILE* f;

	if(!str)
		return NULL;

	if(!(f = fopen("/proc/version", "r")))
	{
		perror("fopen()");
		return NULL;
	}

	if(fread(str, 1, KERNELVER_LEN - 1, f) > 0)
	{
		if(str[strlen(str) - 1] == '\n')
			str[strlen(str) - 1] = 0;
		goto end;
	}

	str = NULL;
end:
	fclose(f);
	return str;
}

struct offsets* get_offsets()
{
	char* devname = calloc(1, DEVNAME_LEN);
	char* kernelver = calloc(1, KERNELVER_LEN);
	unsigned int i;
	struct offsets* o = NULL;

	if(!get_devname(devname))
		goto end;
	if(!get_kernelver(kernelver))
		goto end;

	for(i = 0; i < ARRAYELEMS(offsets); i++)
	{
		if(strcmp(devname, offsets[i].devname))
			continue;
		if(strcmp(kernelver, offsets[i].kernelver))
			continue;
		o = &offsets[i];
		break;
	}

end:
	if(o == NULL) {
		printf("Error: Device not supported\n");
		printf("Device name: %s\n", devname);
		printf("Kernel version: %s\n", kernelver);
	}
	free(devname);
	free(kernelver);
	return o;
}
