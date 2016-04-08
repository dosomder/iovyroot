#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <inttypes.h>

#include "offsets.h"

#define ARRAYELEMS(a) (sizeof(a) / sizeof(a[0]))

#if (__LP64__)

struct offsets offsets[] = {
	//LG G Flex 2, 5.1.1 LMY47S
	{ "LG-H955", "Linux version 3.10.49-perf-g524d659 (lgmobile@si-rd10-bx56) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Wed Dec 9 11:56:36 KST 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc001963938) },
	  (void*)0xffffffc000336ce4, (void*)0xffffffc0003037c8, (void*)0xffffffc00189b9c0, (void*)0xffffffc00189b7c8, (void*)0xffffffc001649320, (void*)0xffffffc001898324 },

	/********************** SONY **********************/
	//M5 30.0.A.1.23
	{ "E5603", "Linux version 3.10.61+ (hudsonslave@cnbjlx20340) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Fri Jul 24 17:37:23 CST 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011d5d90) },
	  (void*)0xffffffc0001de6fc, (void*)0xffffffc0001a5e6c, NULL, NULL, (void*)0xffffffc000ed0ee0, (void*)0xffffffc0011ceeec },
	//M5 30.1.A.1.33
	{ "E5603", "Linux version 3.10.72+ (hudsonslave@cnbjlx20401) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Thu Dec 31 17:39:24 CST 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011a7208 + 8) },
	  (void*)0xffffffc0001e06fc, (void*)0xffffffc0001a8100, NULL, NULL, (void*)0xffffffc000ec53f8, (void*)0xffffffc00119fcec },
	//M5 30.0.A.1.23
	{ "E5606", "Linux version 3.10.61+ (hudsonslave@cnbjlx20340) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Fri Jul 24 17:37:23 CST 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011d5d90) },
	  (void*)0xffffffc0001de6fc, (void*)0xffffffc0001a5e6c, NULL, NULL, (void*)0xffffffc000ed0ee0, (void*)0xffffffc0011ceeec },
	//M5 30.1.A.1.33
	{ "E5606", "Linux version 3.10.72+ (hudsonslave@cnbjlx20401) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Thu Dec 31 17:39:24 CST 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011a7208 + 8) },
	  (void*)0xffffffc0001e06fc, (void*)0xffffffc0001a8100, NULL, NULL, (void*)0xffffffc000ec53f8, (void*)0xffffffc00119fcec },
	//M5 Dual 30.0.B.1.23
	{ "E5633", "Linux version 3.10.61+ (hudsonslave@cnbjlx20100) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Fri Jul 24 17:39:51 CST 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc001224d90) },
	  (void*)0xffffffc0001de6fc, (void*)0xffffffc0001a5e6c, NULL, NULL, (void*)0xffffffc000ef8ee0, (void*)0xffffffc00121deec },
	//M5 Dual 30.1.B.1.33
	{ "E5633", "Linux version 3.10.72+ (hudsonslave@cnbjlx21095) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Thu Dec 31 17:04:22 CST 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011f5208 + 8) }, //Xperia M5 uses a different file_operations
	  (void*)0xffffffc0001e06fc, (void*)0xffffffc0001a8100, NULL, NULL, (void*)0xffffffc000eed3f8, (void*)0xffffffc0011edcec },
	//M5 Dual 30.0.B.1.23
	{ "E5643", "Linux version 3.10.61+ (hudsonslave@cnbjlx20100) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Fri Jul 24 17:39:51 CST 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc001224d90) },
	  (void*)0xffffffc0001de6fc, (void*)0xffffffc0001a5e6c, NULL, NULL, (void*)0xffffffc000ef8ee0, (void*)0xffffffc00121deec },
	//M5 Dual 30.1.B.1.33
	{ "E5643", "Linux version 3.10.72+ (hudsonslave@cnbjlx21095) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Thu Dec 31 17:04:22 CST 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011f5208 + 8) },
	  (void*)0xffffffc0001e06fc, (void*)0xffffffc0001a8100, NULL, NULL, (void*)0xffffffc000eed3f8, (void*)0xffffffc0011edcec },
	//M5 30.0.A.1.23
	{ "E5653", "Linux version 3.10.61+ (hudsonslave@cnbjlx20340) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Fri Jul 24 17:37:23 CST 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011d5d90) },
	  (void*)0xffffffc0001de6fc, (void*)0xffffffc0001a5e6c, NULL, NULL, (void*)0xffffffc000ed0ee0, (void*)0xffffffc0011ceeec },
	//M5 30.1.A.1.33
	{ "E5653", "Linux version 3.10.72+ (hudsonslave@cnbjlx20401) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Thu Dec 31 17:39:24 CST 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011a7208 + 8) },
	  (void*)0xffffffc0001e06fc, (void*)0xffffffc0001a8100, NULL, NULL, (void*)0xffffffc000ec53f8, (void*)0xffffffc00119fcec },
	//M5 Dual 30.0.B.1.23
	{ "E5663", "Linux version 3.10.61+ (hudsonslave@cnbjlx20100) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Fri Jul 24 17:39:51 CST 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc001224d90) },
	  (void*)0xffffffc0001de6fc, (void*)0xffffffc0001a5e6c, NULL, NULL, (void*)0xffffffc000ef8ee0, (void*)0xffffffc00121deec },
	//M5 Dual 30.1.B.1.33
	{ "E5663", "Linux version 3.10.72+ (hudsonslave@cnbjlx21095) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Thu Dec 31 17:04:22 CST 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011f5208 + 8) },
	  (void*)0xffffffc0001e06fc, (void*)0xffffffc0001a8100, NULL, NULL, (void*)0xffffffc000eed3f8, (void*)0xffffffc0011edcec },
	//Z5C 32.0.A.6.200
	{ "E5803", "Linux version 3.10.49-perf-g83fc9bc (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Oct 13 05:33:30 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc00194f590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001886940, (void*)0xffffffc001886748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188329c },
	//Z5C 32.0.A.6.200 Malaysia
	{ "E5803", "Linux version 3.10.49-perf-g75e6207 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Mon Oct 26 23:20:48 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc00194f590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001886940, (void*)0xffffffc001886748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188329c },
	//Z5C 32.0.A.6.200
	{ "E5823", "Linux version 3.10.49-perf-g75e6207 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Mon Oct 26 23:20:48 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc00194f590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001886940, (void*)0xffffffc001886748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188329c },
	//Z3+ Dual 28.0.A.8.266
	{ "E6533", "Linux version 3.10.49-perf-g3363e96 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Wed Oct 7 17:07:50 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc0018ff4f0) },
	  (void*)0xffffffc0003b9780, (void*)0xffffffc000302688, (void*)0xffffffc0018354b8, (void*)0xffffffc0018352c0, (void*)0xffffffc001649548, (void*)0xffffffc001831e1c },
	//Z3+ 28.0.A.8.266
	{ "E6553", "Linux version 3.10.49-perf-g3363e96 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Wed Oct 7 17:07:50 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc0018ff4f0) },
	  (void*)0xffffffc0003b9780, (void*)0xffffffc000302688, (void*)0xffffffc0018354b8, (void*)0xffffffc0018352c0, (void*)0xffffffc001649548, (void*)0xffffffc001831e1c },
	//Z5 32.0.A.6.152
	{ "E6603", "Linux version 3.10.49-perf-g83fc9bc (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Oct 13 05:33:30 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940, (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
	//Z5 Dual Sim 32.0.A.6.152
	{ "E6633", "Linux version 3.10.49-perf-g83fc9bc (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Oct 13 05:33:30 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc00194f590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001886940, (void*)0xffffffc001886748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188329c },
	//Z5 32.0.A.6.152
	{ "E6653", "Linux version 3.10.49-perf-g83fc9bc (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Oct 13 05:33:30 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940, (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
	//Z5 32.0.A.6.200
	{ "E6653", "Linux version 3.10.49-perf-g75e6207 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Mon Oct 26 23:20:48 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940, (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
	//Z5 Dual Sim 32.0.A.6.152
	{ "E6683", "Linux version 3.10.49-perf-g83fc9bc (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Oct 13 05:33:30 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc00194f590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001886940, (void*)0xffffffc001886748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188329c },
	//Z5 Dual Sim 32.0.A.6.209
	{ "E6683", "Linux version 3.10.49-perf-g2174004 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Fri Nov 13 16:33:06 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc00194f590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001886940, (void*)0xffffffc001886748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188329c },
	//Z5 Premium Dual Sim 32.0.A.6.170
	{ "E6833", "Linux version 3.10.49-perf-g9a3c9a8-04532-g75e6207 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Mon Oct 26 23:20:48 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940, (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
	//Z5 Premium International 32.0.A.6.170 & 32.0.A.6.200
	{ "E6853", "Linux version 3.10.49-perf-g75e6207 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Mon Oct 26 23:20:48 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940, (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
	//Z5 Premium Dual Sim 32.0.A.6.160
	{ "E6883", "Linux version 3.10.49-perf-g83fc9bc (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Oct 13 05:33:30 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940, (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
	//Z5 Premium Dual Sim 32.0.A.6.170
	{ "E6883", "Linux version 3.10.49-perf-g9a3c9a8-04532-g75e6207 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Mon Oct 26 23:20:48 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940, (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
	//Z5 Premium Dual Sim 32.0.A.6.209
	{ "E6883", "Linux version 3.10.49-perf-g2174004 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Fri Nov 13 16:33:06 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940, (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
	//Z4 Tablet LTE 28.0.A.8.260
	{ "SGP771", "Linux version 3.10.49-perf-g3363e96 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Wed Oct 7 17:07:50 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc0018fd4f0) },
	  (void*)0xffffffc0003b9780, (void*)0xffffffc000302688, (void*)0xffffffc0018334b8, (void*)0xffffffc0018332c0, (void*)0xffffffc001649548, (void*)0xffffffc00182fe1c },
	//Z4 Tablet WiFi 28.0.A.8.260
	{ "SGP712", "Linux version 3.10.49-perf-g3363e96 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Wed Oct 7 17:07:50 2015", { (void*)CHECK_FLAGS_OFFSET(0xffffffc0018fc4f0) },
	  (void*)0xffffffc0003b9780, (void*)0xffffffc000302688, (void*)0xffffffc0018324b8, (void*)0xffffffc0018322c0, (void*)0xffffffc001649548, (void*)0xffffffc00182ee1c },
};

#else

struct offsets offsets[] = {
	//Z3C 23.4.A.1.264
	{ "D5803", "Linux version 3.4.0-perf-gbe52486 (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Thu Sep 17 15:00:01 2015", { (void*)FSYNC_OFFSET(0xc10ec130) }, (void*)0xc10e0c3c, (void*)0xc10e0b2c, (void*)0xc0f57884, (void*)0xc10df0d8 },
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
	fclose(f);
	return name;
}

static char* get_kernelver(char* str)
{
	FILE* f;
	size_t s;

	if(!str)
		return NULL;

	if(!(f = fopen("/proc/version", "r")))
	{
		perror("fopen()");
		return NULL;
	}

	if((s = fread(str, 1, KERNELVER_LEN - 1, f)) > 0)
	{
		char* nl = strchr(str, '\n');
		if(nl)
			*nl = 0;
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
	if(o == NULL)
		printf("Error: Device not supported\n");
	free(devname);
	free(kernelver);
	return o;
}
