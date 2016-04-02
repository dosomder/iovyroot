#ifndef SIDTAB_H
#define SIDTAB_H

#define SIDTAB_HASH_BITS 7
#define SIDTAB_HASH_BUCKETS (1 << SIDTAB_HASH_BITS)
#define SIDTAB_HASH_MASK (SIDTAB_HASH_BUCKETS-1)
#define SIDTAB_HASH(sid) (sid & SIDTAB_HASH_MASK)
#define SIDTAB_SIZE SIDTAB_HASH_BUCKETS

struct sidtab* sidtab;

#ifndef u32
typedef unsigned int u32;
#endif

struct ebitmap {
	void *node;	/* first node in the bitmap */
	u32 highbit;	/* highest position in the total bitmap */
};

struct mls_level {
	u32 sens;		/* sensitivity */
	struct ebitmap cat;	/* category set */
};

struct mls_range {
	struct mls_level level[2]; /* low == level[0], high == level[1] */
};

struct context {
	u32 user;
	u32 role;
	u32 type;
	u32 len;        /* length of string in bytes */
	struct mls_range range;
	char *str;	/* string representation if context cannot be mapped. */
};

struct sidtab_node {
	u32 sid;		/* security identifier */
	struct context context;	/* security context structure */
	struct sidtab_node *next;
};

struct sidtab {
	struct sidtab_node **htable;
	unsigned int nel;	/* number of elements */
	/* ... */
};

#endif /* SIDTAB_H */
