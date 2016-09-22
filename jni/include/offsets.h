#ifndef OFFSETS_H
#define OFFSETS_H

//struct selinux_ops
#define CAPABLE_OFFSET(i) ((i) + (10 * sizeof(void*)))

struct offsets {
	char* devname; //ro.product.model
	char* kernelver; // /proc/version
    void* fake_capable; // used for replace the selinux_ops->capble,
                        // which have to return 0 always
    void* selinux_ops;
    void* selinux_disabled;
	void* selinux_enabled;
	void* selinux_enforcing;
};

struct offsets* get_offsets();
extern struct offsets offsets[];

#endif /* OFFSETS_H */
