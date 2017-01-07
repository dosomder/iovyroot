#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <inttypes.h>

#include "offsets.h"

#define ARRAYELEMS(a) (sizeof(a) / sizeof(a[0]))

#if (__LP64__)

struct offsets offsets[] = {
	/********************** LENOVO **********************/
	//Vibe P1, LMY47V
	{ "Lenovo P1a42", "Linux version 3.10.49-perf-gb8aeeef (buildslave@njbs12) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Jan 26 18:24:36 CST 2016",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc00121a520) },
	  (void*)0xffffffc0001ae450, (void*)0xffffffc00017c70c, (void*)0xffffffc0011808b0,
	  (void*)0xffffffc0011806b8, (void*)0xffffffc000eff168, (void*)0xffffffc00117d21c },

	/********************** LG **********************/
	//G Flex 2, 5.1.1 LMY47S
	{ "LG-H955", "Linux version 3.10.49-perf-g524d659 (lgmobile@si-rd10-bx56) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Wed Dec 9 11:56:36 KST 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc001963938) },
	  (void*)0xffffffc000336ce4, (void*)0xffffffc0003037c8, (void*)0xffffffc00189b9c0,
	  (void*)0xffffffc00189b7c8, (void*)0xffffffc001649320, (void*)0xffffffc001898324 },
	//G Flex 2, 5.1.1 LMY47S
	{ "LG-H959", "Linux version 3.10.49-perf-g7db53f8 (lgmobile@LGEACI5R9) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Mon Nov 16 14:32:00 KST 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc001963938) },
	  (void*)0xffffffc000336c74, (void*)0xffffffc000303758, (void*)0xffffffc00189b9c0,
	  (void*)0xffffffc00189b7c8, (void*)0xffffffc001649320, (void*)0xffffffc001898324 },
	//Nexus 5X, 6.0.1 MHC19J
	{ "Nexus 5X", "Linux version 3.10.73-g3e127ab (android-build@wpiz15.hot.corp.google.com) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Feb 9 20:02:25 UTC 2016",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc001cfd430 + 8) },
	  (void*)0xffffffc0003ee4f0, (void*)0xffffffc0003075b0, (void*)0xffffffc001c364e0,
	  (void*)0xffffffc001c36520, (void*)0xffffffc0018269ac, (void*)0xffffffc001c3302c },

	/********************** SONY **********************/
	//M4 Aqua 26.1.A.2.147
	{ "E2303", "Linux version 3.10.49-perf-g8486ae6 (hudsonslave@cnbjlx20365) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Thu Sep 10 07:23:52 CST 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc00112a930) },
	  (void*)0xffffffc0001aea94, (void*)0xffffffc00017cc78, (void*)0xffffffc001090bd8,
	  (void*)0xffffffc0010909e0, (void*)0xffffffc000f002d8, (void*)0xffffffc00108d544 },
	//M5 30.0.A.1.23
	{ "E5603", "Linux version 3.10.61+ (hudsonslave@cnbjlx20340) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Fri Jul 24 17:37:23 CST 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011d5d90) },
	  (void*)0xffffffc0001de6fc, (void*)0xffffffc0001a5e6c, NULL,
	  NULL, (void*)0xffffffc000ed0ee0, (void*)0xffffffc0011ceeec },
	//M5 30.1.A.1.33
	{ "E5603", "Linux version 3.10.72+ (hudsonslave@cnbjlx20401) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Thu Dec 31 17:39:24 CST 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011a7208 + 8) },
	  (void*)0xffffffc0001e06fc, (void*)0xffffffc0001a8100, NULL,
	  NULL, (void*)0xffffffc000ec53f8, (void*)0xffffffc00119fcec },
	//M5 30.0.A.1.23
	{ "E5606", "Linux version 3.10.61+ (hudsonslave@cnbjlx20340) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Fri Jul 24 17:37:23 CST 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011d5d90) },
	  (void*)0xffffffc0001de6fc, (void*)0xffffffc0001a5e6c, NULL,
	  NULL, (void*)0xffffffc000ed0ee0, (void*)0xffffffc0011ceeec },
	//M5 30.1.A.1.33
	{ "E5606", "Linux version 3.10.72+ (hudsonslave@cnbjlx20401) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Thu Dec 31 17:39:24 CST 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011a7208 + 8) },
	  (void*)0xffffffc0001e06fc, (void*)0xffffffc0001a8100, NULL,
	  NULL, (void*)0xffffffc000ec53f8, (void*)0xffffffc00119fcec },
	//M5 Dual 30.0.B.1.23
	{ "E5633", "Linux version 3.10.61+ (hudsonslave@cnbjlx20100) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Fri Jul 24 17:39:51 CST 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc001224d90) },
	  (void*)0xffffffc0001de6fc, (void*)0xffffffc0001a5e6c, NULL,
	  NULL, (void*)0xffffffc000ef8ee0, (void*)0xffffffc00121deec },
	//M5 Dual 30.1.B.1.33
	{ "E5633", "Linux version 3.10.72+ (hudsonslave@cnbjlx21095) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Thu Dec 31 17:04:22 CST 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011f5208 + 8) }, //Xperia M5 uses a different file_operations
	  (void*)0xffffffc0001e06fc, (void*)0xffffffc0001a8100, NULL,
	  NULL, (void*)0xffffffc000eed3f8, (void*)0xffffffc0011edcec },
	//M5 Dual 30.0.B.1.23
	{ "E5643", "Linux version 3.10.61+ (hudsonslave@cnbjlx20100) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Fri Jul 24 17:39:51 CST 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc001224d90) },
	  (void*)0xffffffc0001de6fc, (void*)0xffffffc0001a5e6c, NULL,
	  NULL, (void*)0xffffffc000ef8ee0, (void*)0xffffffc00121deec },
	//M5 Dual 30.1.B.1.33
	{ "E5643", "Linux version 3.10.72+ (hudsonslave@cnbjlx21095) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Thu Dec 31 17:04:22 CST 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011f5208 + 8) },
	  (void*)0xffffffc0001e06fc, (void*)0xffffffc0001a8100, NULL,
	  NULL, (void*)0xffffffc000eed3f8, (void*)0xffffffc0011edcec },
	//M5 30.0.A.1.23
	{ "E5653", "Linux version 3.10.61+ (hudsonslave@cnbjlx20340) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Fri Jul 24 17:37:23 CST 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011d5d90) },
	  (void*)0xffffffc0001de6fc, (void*)0xffffffc0001a5e6c, NULL,
	  NULL, (void*)0xffffffc000ed0ee0, (void*)0xffffffc0011ceeec },
	//M5 30.1.A.1.33
	{ "E5653", "Linux version 3.10.72+ (hudsonslave@cnbjlx20401) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Thu Dec 31 17:39:24 CST 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011a7208 + 8) },
	  (void*)0xffffffc0001e06fc, (void*)0xffffffc0001a8100, NULL,
	  NULL, (void*)0xffffffc000ec53f8, (void*)0xffffffc00119fcec },
	//M5 Dual 30.0.B.1.23
	{ "E5663", "Linux version 3.10.61+ (hudsonslave@cnbjlx20100) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Fri Jul 24 17:39:51 CST 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc001224d90) },
	  (void*)0xffffffc0001de6fc, (void*)0xffffffc0001a5e6c, NULL,
	  NULL, (void*)0xffffffc000ef8ee0, (void*)0xffffffc00121deec },
	//M5 Dual 30.1.B.1.33
	{ "E5663", "Linux version 3.10.72+ (hudsonslave@cnbjlx21095) (gcc version 4.9 20140514 (mtk-20150408) (GCC) ) #1 SMP PREEMPT Thu Dec 31 17:04:22 CST 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0011f5208 + 8) },
	  (void*)0xffffffc0001e06fc, (void*)0xffffffc0001a8100, NULL,
	  NULL, (void*)0xffffffc000eed3f8, (void*)0xffffffc0011edcec },
	//Z5C 32.0.A.6.200
	{ "E5803", "Linux version 3.10.49-perf-g83fc9bc (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Oct 13 05:33:30 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc00194f590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001886940,
	  (void*)0xffffffc001886748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188329c },
	//Z5C 32.0.A.6.200 Malaysia
	{ "E5803", "Linux version 3.10.49-perf-g75e6207 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Mon Oct 26 23:20:48 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc00194f590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001886940,
	  (void*)0xffffffc001886748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188329c },
	//Z5C 32.0.A.6.152
	{ "E5823", "Linux version 3.10.49-perf-g83fc9bc (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Oct 13 05:33:30 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc00194f590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001886940,
	  (void*)0xffffffc001886748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188329c },
	//Z5C 32.0.A.6.200
	{ "E5823", "Linux version 3.10.49-perf-g75e6207 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Mon Oct 26 23:20:48 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc00194f590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001886940,
	  (void*)0xffffffc001886748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188329c },
	//Z3+ Dual 28.0.A.8.266
	{ "E6533", "Linux version 3.10.49-perf-g3363e96 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Wed Oct 7 17:07:50 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0018ff4f0) },
	  (void*)0xffffffc0003b9780, (void*)0xffffffc000302688, (void*)0xffffffc0018354b8,
	  (void*)0xffffffc0018352c0, (void*)0xffffffc001649548, (void*)0xffffffc001831e1c },
	//Z3+ 28.0.A.8.266
	{ "E6553", "Linux version 3.10.49-perf-g3363e96 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Wed Oct 7 17:07:50 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0018ff4f0) },
	  (void*)0xffffffc0003b9780, (void*)0xffffffc000302688, (void*)0xffffffc0018354b8,
	  (void*)0xffffffc0018352c0, (void*)0xffffffc001649548, (void*)0xffffffc001831e1c },
	//Z5 32.0.A.6.152
	{ "E6603", "Linux version 3.10.49-perf-g83fc9bc (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Oct 13 05:33:30 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940,
	  (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
	//Z5 Dual Sim 32.0.A.6.152
	{ "E6633", "Linux version 3.10.49-perf-g83fc9bc (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Oct 13 05:33:30 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc00194f590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001886940,
	  (void*)0xffffffc001886748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188329c },
	//Z5 32.0.A.6.152
	{ "E6653", "Linux version 3.10.49-perf-g83fc9bc (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Oct 13 05:33:30 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940,
	  (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
	//Z5 32.0.A.6.200
	{ "E6653", "Linux version 3.10.49-perf-g75e6207 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Mon Oct 26 23:20:48 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940,
	  (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
	//Z5 Dual Sim 32.0.A.6.152
	{ "E6683", "Linux version 3.10.49-perf-g83fc9bc (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Oct 13 05:33:30 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc00194f590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001886940,
	  (void*)0xffffffc001886748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188329c },
	//Z5 Dual Sim 32.0.A.6.209
	{ "E6683", "Linux version 3.10.49-perf-g2174004 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Fri Nov 13 16:33:06 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc00194f590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001886940,
	  (void*)0xffffffc001886748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188329c },
	//Z5 Premium Dual Sim 32.0.A.6.170
	{ "E6833", "Linux version 3.10.49-perf-g9a3c9a8-04532-g75e6207 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Mon Oct 26 23:20:48 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940,
	  (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
	//Z5 Premium International 32.0.A.6.170 & 32.0.A.6.200
	{ "E6853", "Linux version 3.10.49-perf-g75e6207 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Mon Oct 26 23:20:48 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940,
	  (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
	//Z5 Premium Dual Sim 32.0.A.6.160
	{ "E6883", "Linux version 3.10.49-perf-g83fc9bc (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Oct 13 05:33:30 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940,
	  (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
	//Z5 Premium Dual Sim 32.0.A.6.170
	{ "E6883", "Linux version 3.10.49-perf-g9a3c9a8-04532-g75e6207 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Mon Oct 26 23:20:48 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940,
	  (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
	//Z5 Premium Dual Sim 32.0.A.6.209
	{ "E6883", "Linux version 3.10.49-perf-g2174004 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Fri Nov 13 16:33:06 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940,
	  (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
	//Z4 Tablet LTE 28.0.A.8.260
	{ "SGP771", "Linux version 3.10.49-perf-g3363e96 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Wed Oct 7 17:07:50 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0018fd4f0) },
	  (void*)0xffffffc0003b9780, (void*)0xffffffc000302688, (void*)0xffffffc0018334b8,
	  (void*)0xffffffc0018332c0, (void*)0xffffffc001649548, (void*)0xffffffc00182fe1c },
	//Z4 Tablet WiFi 28.0.A.8.260
	{ "SGP712", "Linux version 3.10.49-perf-g3363e96 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Wed Oct 7 17:07:50 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0018fc4f0) },
	  (void*)0xffffffc0003b9780, (void*)0xffffffc000302688, (void*)0xffffffc0018324b8,
	  (void*)0xffffffc0018322c0, (void*)0xffffffc001649548, (void*)0xffffffc00182ee1c },
	//Z4 Tablet JP 28.0.B.1.229
	{ "SO-05G", "Linux version 3.10.49-perf-g497e6be (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Dec 15 15:01:03 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0018fb4f0) },
	  (void*)0xffffffc0003b7d84, (void*)0xffffffc000301870, (void*)0xffffffc0018314b8,
	  (void*)0xffffffc0018312c0, (void*)0xffffffc001649548, (void*)0xffffffc00182de1c },
	//Z4 JP 28.0.B.0.446
	{ "SO-03G", "Linux version 3.10.49-perf-g897210e (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Fri May 8 17:36:11 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0018fd4f0) },
	  (void*)0xffffffc0003b7d84, (void*)0xffffffc000301870, (void*)0xffffffc0018334b8,
	  (void*)0xffffffc0018332c0, (void*)0xffffffc001649548, (void*)0xffffffc00182fe1c },
	//Z4 JP 28.0.B.0.488
	{ "SO-03G", "Linux version 3.10.49-perf-ga1be5c2 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Wed Jul 29 19:48:33 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0018fd4f0) },
	  (void*)0xffffffc0003b7d84, (void*)0xffffffc000301870, (void*)0xffffffc0018334b8,
	  (void*)0xffffffc0018332c0, (void*)0xffffffc001649548, (void*)0xffffffc00182fe1c },
	//Z4 28.0.B.1.229
	{ "SO-03G", "Linux version 3.10.49-perf-g497e6be (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Tue Dec 15 15:01:03 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0018fd4f0) },
	  (void*)0xffffffc0003b7d84, (void*)0xffffffc000301870, (void*)0xffffffc0018334b8,
	  (void*)0xffffffc0018332c0, (void*)0xffffffc001649548, (void*)0xffffffc00182fe1c },
	//Z4 28.0.D.6.136
	{ "SOV31", "Linux version 3.10.49-perf-geaad5d9 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Mon Oct 19 17:21:43 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0018fd4f0) },
	  (void*)0xffffffc0003b7d84, (void*)0xffffffc000301870, (void*)0xffffffc0018334b8,
	  (void*)0xffffffc0018332c0, (void*)0xffffffc001649548, (void*)0xffffffc00182fe1c },
	//Z4 28.0.C.4.146
	{ "402SO", "Linux version 3.10.49-perf-g9d3eaeb (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Mon Feb 29 19:26:35 2016",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc0018fd4f0) },
	  (void*)0xffffffc0003b7d84, (void*)0xffffffc000301870, (void*)0xffffffc0018334b8,
	  (void*)0xffffffc0018332c0, (void*)0xffffffc001649548, (void*)0xffffffc00182fe1c },
	//Z5 32.0.B.0.370
	{ "SO-01H", "Linux version 3.10.49-perf-g252d546 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Fri Sep 18 18:40:40 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c7560, (void*)0xffffffc000310360, (void*)0xffffffc001887940,
	  (void*)0xffffffc001887748, (void*)0xffffffc00164ad08, (void*)0xffffffc00188429c },
	//Z5 32.0.B.0.443
	{ "SO-01H", "Linux version 3.10.49-perf-g7498fe6 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Thu Nov 19 21:23:00 2015",
	  { (void*)CHECK_FLAGS_OFFSET(0xffffffc001950590) },
	  (void*)0xffffffc0003c66e0, (void*)0xffffffc00030f4e0, (void*)0xffffffc001887940,
	  (void*)0xffffffc001887748, (void*)0xffffffc00164ad48, (void*)0xffffffc00188429c },
};

#else

struct offsets offsets[] = {
	/********************** SONY **********************/
	//Z2 Tablet SGP551 Brazil 23.5.A.0.575
	{ "SGP551", "Linux version 3.4.0-perf-g43ea728 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Fri Apr 22 17:27:56 2016",
	  { (void*)FSYNC_OFFSET(0xc1235674) },
	  (void*)0xc122a08c, (void*)0xc122a0b4, (void*)0xc102f1d0, (void*)0xc1228630 },
	//Z2 Tablet SGP521 UK 23.5.A.0.575
	{ "SGP521", "Linux version 3.4.0-perf-g43ea728 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Fri Apr 22 17:27:56 2016",
	  { (void*)FSYNC_OFFSET(0xc12353b4) },
	  (void*)0xc1229dcc, (void*)0xc1229df4, (void*)0xc102f1c0, (void*)0xc1228370 },
	//Z2 Tablet SGP511 UK 23.5.A.0.575
	{ "SGP511", "Linux version 3.4.0-perf-g43ea728 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Fri Apr 22 17:27:56 2016",
	  { (void*)FSYNC_OFFSET(0xc1234bb4) },
	  (void*)0xc12295cc, (void*)0xc12295f4, (void*)0xc102f1c0, (void*)0xc1227b70 },
	//Z2 Tablet SGP512 UK TW 23.5.A.0.575
	{ "SGP512", "Linux version 3.4.0-perf-g43ea728 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Fri Apr 22 17:27:56 2016",
	  { (void*)FSYNC_OFFSET(0xc1234bb4) },
	  (void*)0xc12295cc, (void*)0xc12295f4, (void*)0xc102f1c0, (void*)0xc1227b70 },
	//Z3C 23.4.A.1.264
	{ "D5803", "Linux version 3.4.0-perf-gbe52486 (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Thu Sep 17 15:00:01 2015",
	  { (void*)FSYNC_OFFSET(0xc10ec130) },
	  (void*)0xc10e0c3c, (void*)0xc10e0b2c, (void*)0xc0f57884, (void*)0xc10df0d8 },
	//Z3C 23.5.A.0.575
	{ "D5803", "Linux version 3.4.0-perf-g43ea728 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Fri Apr 22 17:27:56 2016",
	  { (void*)FSYNC_OFFSET(0xc1234b30) },
	  (void*)0xc122954c, (void*)0xc1229574, (void*)0xc102f1c0, (void*)0xc1227af0 },
	//Z3C 23.1.B.1.197
	{ "SO-02G", "Linux version 3.4.0-perf-gf6a03f1 (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Wed Aug 5 12:06:34 2015",
	  { (void*)FSYNC_OFFSET(0xc10e9470) },
	  (void*)0xc10de07c, (void*)0xc10ddf6c, (void*)0xc0f56dc4, (void*)0xc10dc518 },
	//Z3 23.5.A.0.575
	{ "D6633", "Linux version 3.4.0-perf-g43ea728 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Fri Apr 22 17:27:56 2016",
	  { (void*)FSYNC_OFFSET(0xc1235070) },
	  (void*)0xc1229a8c, (void*)0xc1229ab4, (void*)0xc102ff80, (void*)0xc1228030 },
	//Z3 23.5.A.0.575
	{ "D6653", "Linux version 3.4.0-perf-g43ea728 (BuildUser@BuildHost) (gcc version 4.9.x-google 20140827 (prerelease) (GCC) ) #1 SMP PREEMPT Fri Apr 22 17:27:56 2016",
	  { (void*)FSYNC_OFFSET(0xc12359f0) },
	  (void*)0xc122a40c, (void*)0xc122a434, (void*)0xc102fe28, (void*)0xc12289b0 },
	//M2_EULTE 18.6.A.0.182
	{ "D2303", "Linux version 3.4.0-gc82e70f (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Mon Aug 10 21:54:32 2015",
	  { (void*)FSYNC_OFFSET(0xc0feaf68) },
	  (void*)0xc0fe1fbc, (void*)0xc0fe1eac, (void*)0xc0e4aea4, (void*)0xc0fe0458 },
	//M2_AMERICASLTE 18.6.A.0.182
	{ "D2306", "Linux version 3.4.0-gc82e70f (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Mon Aug 10 21:54:32 2015",
	  { (void*)FSYNC_OFFSET(0xc0feaf68) },
	  (void*)0xc0fe1fbc, (void*)0xc0fe1eac, (void*)0xc0e4aea4, (void*)0xc0fe0458 },
	//M2_DSDS 18.6.A.0.182
	{ "D2302", "Linux version 3.4.0-gc82e70f (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Mon Aug 10 21:54:32 2015",
	  { (void*)FSYNC_OFFSET(0xc0feaf68) },
	  (void*)0xc0fe1fbc, (void*)0xc0fe1eac, (void*)0xc0e4aea4, (void*)0xc0fe0458 },
	//M2Aqua_EULTE 18.6.A.0.182
	{ "D2403", "Linux version 3.4.0-gc82e70f (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Mon Aug 10 21:54:32 2015",
	  { (void*)FSYNC_OFFSET(0xc0feaf68) },
	  (void*)0xc0fe1fbc, (void*)0xc0fe1eac, (void*)0xc0e4aea4, (void*)0xc0fe0458 },
	//M2Aqua_AMERICASLTE 18.6.A.0.182
	{ "D2406", "Linux version 3.4.0-gc82e70f (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Mon Aug 10 21:54:32 2015",
	  { (void*)FSYNC_OFFSET(0xc0feaf68) },
	  (void*)0xc0fe1fbc, (void*)0xc0fe1eac, (void*)0xc0e4aea4, (void*)0xc0fe0458 },
	//M2_SS 18.6.A.0.182
	{ "D2305", "Linux version 3.4.0-gc82e70f (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Mon Aug 10 21:54:32 2015",
	  { (void*)FSYNC_OFFSET(0xc0feae68) },
	  (void*)0xc0fe1ebc, (void*)0xc0fe1dac, (void*)0xc0e4ada4, (void*)0xc0fe0358 },
	//Z1c 14.6.A.1.236
	{ "D5503", "Linux version 3.4.0-perf-gd26777b-00851-ga8b7b55 (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Thu Nov 19 10:33:19 2015",
	  { (void*)FSYNC_OFFSET(0xc10ecb90) },
	  (void*)0xc10e17fc, (void*)0xc10e16ec, (void*)0xc0f57304, (void*)0xc10dfc98 },
	//Z1_C6902 14.6.A.1.236
	{ "C6902", "Linux version 3.4.0-perf-gd26777b-00851-ga8b7b55 (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Thu Nov 19 10:33:19 2015",
	  { (void*)FSYNC_OFFSET(0xc10ecb90) },
	  (void*)0xc10e17fc, (void*)0xc10e16ec, (void*)0xc0f57304, (void*)0xc10dfc98 },
	//Z1_C6903 14.6.A.1.236
	{ "C6903", "Linux version 3.4.0-perf-gd26777b-00851-ga8b7b55 (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Thu Nov 19 10:33:19 2015",
	  { (void*)FSYNC_OFFSET(0xc10ecb90) },
	  (void*)0xc10e17fc, (void*)0xc10e16ec, (void*)0xc0f57304, (void*)0xc10dfc98 },
	//Z1_C6906 14.6.A.1.236
	{ "C6906", "Linux version 3.4.0-perf-gd26777b-00851-ga8b7b55 (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Thu Nov 19 10:33:19 2015",
	  { (void*)FSYNC_OFFSET(0xc10ecb90) },
	  (void*)0xc10e17fc, (void*)0xc10e16ec, (void*)0xc0f57304, (void*)0xc10dfc98 },
	//Z1_C6943 14.6.A.1.236
	{ "C6943", "Linux version 3.4.0-perf-gd26777b-00851-ga8b7b55 (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Thu Nov 19 10:33:19 2015",
	  { (void*)FSYNC_OFFSET(0xc10ecb90) },
	  (void*)0xc10e17fc, (void*)0xc10e16ec, (void*)0xc0f57304, (void*)0xc10dfc98 },
	//C3_D2502 19.4.A.0.182
	{ "D2502", "Linux version 3.4.0+ (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Thu Jul 2 12:32:21 2015",
	  { (void*)FSYNC_OFFSET(0xc0fcb018) },
	  (void*)0xc0fc207c, (void*)0xc0fc1f6c, (void*)0xc0e498e4, (void*)0xc0fc0518 },
	//C3_D2533 19.4.A.0.182
	{ "D2533", "Linux version 3.4.0+ (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Thu Jul 2 12:32:21 2015",
	  { (void*)FSYNC_OFFSET(0xc0fcb018) },
	  (void*)0xc0fc207c, (void*)0xc0fc1f6c, (void*)0xc0e498e4, (void*)0xc0fc0518 },
	//T2u_D5303 19.4.A.0.182
	{ "D5303", "Linux version 3.4.0+ (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Thu Jul 2 12:32:21 2015",
	  { (void*)FSYNC_OFFSET(0xc0fcb318) },
	  (void*)0xc0fc237c, (void*)0xc0fc226c, (void*)0xc0e4a2e4, (void*)0xc0fc0818 },
	//T2u_D5306 19.4.A.0.182
	{ "D5306", "Linux version 3.4.0+ (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Thu Jul 2 12:32:21 2015",
	  { (void*)FSYNC_OFFSET(0xc0fcb318) },
	  (void*)0xc0fc237c, (void*)0xc0fc226c, (void*)0xc0e4a2e4, (void*)0xc0fc0818 },
	//T2u_D5316 19.4.A.0.182
	{ "D5316", "Linux version 3.4.0+ (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Thu Jul 2 12:32:21 2015",
	  { (void*)FSYNC_OFFSET(0xc0fcb318) },
	  (void*)0xc0fc237c, (void*)0xc0fc226c, (void*)0xc0e4a2e4, (void*)0xc0fc0818 },
	//T2u_D5322 19.4.A.0.182
	{ "D5322", "Linux version 3.4.0+ (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Thu Jul 2 12:32:21 2015",
	  { (void*)FSYNC_OFFSET(0xc0fcb318) },
	  (void*)0xc0fc237c, (void*)0xc0fc226c, (void*)0xc0e4a2e4, (void*)0xc0fc0818 },
	//ZR 10.7.A.0.228
	{ "C5503", "Linux version 3.4.0-perf-gbccb33a (BuildUser@BuildHost) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Fri Jul 10 09:23:01 2015",
	  { (void*)FSYNC_OFFSET(0xc1073ca0) },
	  (void*)0xc1059e48, (void*)0xc1059d38, (void*)0xc0ecdfe0, (void*)0xc10582e4 },

	/********************** LG **********************/
	//Nexus 5, 6.0.1 MMB29V
	{ "Nexus 5", "Linux version 3.4.0-gbaedb01 (android-build@vped10.mtv.corp.google.com) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Sat Jan 16 01:19:53 UTC 2016",
	  { (void*)FSYNC_OFFSET(0xc1337f10) },
	  (void*)0xc132fefc, (void*)0xc132fdf4, (void*)0xc11770d8, (void*)0xc132e3a0 },
	//Nexus 5, 5.0.1 LRX22C
	{ "Nexus 5", "Linux version 3.4.0-g88fbc66 (android-build@vpbs1.mtv.corp.google.com) (gcc version 4.7 (GCC) ) #1 SMP PREEMPT Mon Oct 20 22:18:31 UTC 2014",
	  { (void*)FSYNC_OFFSET(0xc1236cd8) },
	  (void*)0xc122ecc0, (void*)0xc122ebb0, (void*)0xc1076be0, (void*)0xc122d164 },

	/********************** ASUS **********************/
	//Nexus 7 [2013] (Wi-Fi), 4.4.4 KTU84P
	{ "Nexus 7", "Linux version 3.4.0-g03485a6 (android-build@vpbs1.mtv.corp.google.com) (gcc version 4.7 (GCC) ) #1 SMP PREEMPT Tue Mar 18 15:02:27 PDT 2014",
	  { (void*)FSYNC_OFFSET(0xc114e828) },
	  (void*)0xc113b10c, (void*)0xc113affc, (void*)0xc0fa58d4, (void*)0xc11395b0 },
	//Nexus 7 [2013] (Wi-Fi), 6.0.1 MMB29V
	{ "Nexus 7", "Linux version 3.4.0-g094b859 (android-build@wpds5.hot.corp.google.com) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Thu Jan 21 23:31:37 UTC 2016",
	  { (void*)FSYNC_OFFSET(0xc114eeb0) },
	  (void*)0xc113b790, (void*)0xc113b680, (void*)0xc0fa5e0c, (void*)0xc1139c2c },

	/********************** MOTOROLA **********************/
	//Nexus 6, 5.1.0 LMY47D
	{ "Nexus 6", "Linux version 3.10.40-geec2459 (android-build@vpbs1.mtv.corp.google.com) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Wed Jan 28 22:14:35 UTC 2015",
	  { (void*)FSYNC_OFFSET(0xc130cfd8) },
	  (void*)0xc1294590, (void*)0xc1294480, (void*)0xc104fc30, (void*)0xc1292a2c },
	//Nexus 6, 6.0.1 MMB29K
	{ "Nexus 6", "Linux version 3.10.40-g557ba38 (android-build@wpiv5.hot.corp.google.com) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Wed Nov 4 00:29:43 UTC 2015",
	  { (void*)FSYNC_OFFSET(0xc1412450) },
	  (void*)0xc13971e0, (void*)0xc13970d0, (void*)0xc115072c, (void*)0xc1395678 },

    /********************** HUAWEI ************************/
 	//MediaPad T1-701u, 4.4.2 B005
	{ "T1-701u", "Linux version 3.10.17-g9c4314c (jslave@wuheatculx00133) (gcc version 4.7 (GCC) ) #0 SMP PREEMPT Wed May 6 18:40:01 CST 2015",
	  { (void*)FSYNC_OFFSET(0xc085ecb0) },
	  (void*)0xc085cddc, (void*)0xc085cccc, (void*)0xc07e5304, (void*)0xc085b278},	  
 	//MediaPad T1-701u, 4.4.2 B005
	{ "T1-701u", "Linux version 3.10.17-ga25a4ce (jslave@wuheatculx00162) (gcc version 4.7 (GCC) ) #0 SMP PREEMPT Sat May 9 22:21:56 CST 2015",
	  { (void*)FSYNC_OFFSET(0xc085ecb0) },
	  (void*)0xc085cddc, (void*)0xc085cccc, (void*)0xc07e5304, (void*)0xc085b278},	
	//MediaPad T1-701u, 4.4.2 B005
	{ "T1-701u", "Linux version 3.10.17-gcf73bb7 (jslave@wuheatculx00126) (gcc version 4.7 (GCC) ) #0 SMP PREEMPT Tue May 26 14:02:13 CST 2015",
	  { (void*)FSYNC_OFFSET(0xc0874a30) },
	  (void*)0xc0872b5c, (void*)0xc0872a4c, (void*)0xc07e5304, (void*)0xc0870ff8 },
	//MediaPad T1-701u, 4.4.2 B006
	{ "T1-701u", "Linux version 3.10.17-gbf3879f (jslave@wuheatculx00135) (gcc version 4.7 (GCC) ) #0 SMP PREEMPT Thu Jun 11 14:53:36 CST 2015",
	  { (void*)FSYNC_OFFSET(0xc0878a30) },
	  (void*)0xc0876b5c, (void*)0xc0876a4c, (void*)0xc07e9304, (void*)0xc0874ff8 },
	//MediaPad T1-701u, 4.4.2 B009
	{ "T1 7.0", "Linux version 3.10.17-g7f6ac8a (jslave@wuheatculx00141) (gcc version 4.7 (GCC) ) #0 SMP PREEMPT Tue Sep 15 20:23:48 CST 2015",
	  { (void*)FSYNC_OFFSET(0xc087aa30) },
	  (void*)0xc0878b5c, (void*)0xc0878a4c, (void*)0xc07eb304, (void*)0xc0876ff8 },
      //MediaPad T1-701u, 4.4.2 B101
	{ "T1-701u", "Linux version 3.10.17-gd7b8e16 (jslave@wuheatculx00129) (gcc version 4.7 (GCC) ) #0 SMP PREEMPT Sat Nov 21 12:12:27 CST 2015",
	  { (void*)FSYNC_OFFSET(0xc087cdb0) },
	  (void*)0xc087aedc, (void*)0xc087adcc, (void*)0xc07eb304, (void*)0xc0879378 },
      //MediaPad T1-701u, 4.4.2 B101
	{ "T1 7.0", "Linux version 3.10.17-g9935c48 (jslave@wuheatculx00128) (gcc version 4.7 (GCC) ) #0 SMP PREEMPT Wed Jan 6 11:15:40 CST 2016",
	  { (void*)FSYNC_OFFSET(0xc088e530) },
	  (void*)0xc088c65c, (void*)0xc088c54c, (void*)0xc07fb304, (void*)0xc088aaf8 },
      //MediaPad T1-701u, 4.4.2 B102
	{ "T1-701u", "Linux version 3.10.17-g9935c48 (jslave@wuheatculx00118) (gcc version 4.7 (GCC) ) #0 SMP PREEMPT Fri Jan 8 16:34:04 CST 2016",
	  { (void*)FSYNC_OFFSET(0xc088e530) },
	  (void*)0xc088c65c, (void*)0xc088c54c, (void*)0xc07fb304, (void*)0xc088aaf8 },

	/********************** XIAOMI ************************/
	//Xiaomi MI 2, MIUI 7.2.4.0 Android 5.0.2 LRX22G
	{ "MI 2", "Linux version 3.4.0-perf-g9b728b6-00625-ge66671e (builder@qh-miui-ota-bd53) (gcc version 4.8 (GCC) ) #1 SMP PREEMPT Mon Mar 7 20:05:25 CST 2016",
	  { (void*)FSYNC_OFFSET(0xC12D5298) },
	  (void*)0xC12BC530, (void*)0xC12BC420, (void*)0xC0F5332C, (void*)0xC12BA9D0 },
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
