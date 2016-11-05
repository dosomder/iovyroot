#ifndef GETROOT_H
#define GETROOT_H

#include "threadinfo.h"

int read_at_address_pipe(void* address, void* buf, ssize_t len);
int write_at_address_pipe(void* address, void* buf, ssize_t len);
#ifdef __GNUC_GNU_INLINE__
inline int writel_at_address_pipe(void* address, unsigned long val);
#else
extern inline int writel_at_address_pipe(void* address, unsigned long val);
#endif
int modify_task_cred_uc(struct thread_info* info);
//32bit
struct thread_info* patchaddrlimit();
//64bit
void preparejop(void** addr, void* jopret);

#endif /* GETROOT_H */
