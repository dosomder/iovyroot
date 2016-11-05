#ifndef FLEX_ARRAY_H
#define FLEX_ARRAY_H

#include <fcntl.h>

#define FLEX_ARRAY_PART_SIZE PAGE_SIZE
#define FLEX_ARRAY_BASE_SIZE PAGE_SIZE

#define SYM_COMMONS 0
#define SYM_CLASSES 1
#define SYM_ROLES   2
#define SYM_TYPES   3
#define SYM_USERS   4
#define SYM_BOOLS   5
#define SYM_LEVELS  6
#define SYM_CATS    7
#define SYM_NUM     8

struct symtab {
	void *table;	/* hash table (keyed on a string) */
	__u32 nprim;		/* number of primary names in table */
};

struct flex_array_part {
	char elements[FLEX_ARRAY_PART_SIZE];
};

struct flex_array {
	union {
		struct {
			int element_size;
			int total_nr_elements;
			int elems_per_part;
			__u32 reciprocal_elems;
			struct flex_array_part *parts[];
		};
		/*
		 * This little trick makes sure that
		 * sizeof(flex_array) == PAGE_SIZE
		 */
		char padding[FLEX_ARRAY_BASE_SIZE];
	};
};

/* Number of bytes left in base struct flex_array, excluding metadata */
#define FLEX_ARRAY_BASE_BYTES_LEFT					\
	(FLEX_ARRAY_BASE_SIZE - offsetof(struct flex_array, parts))

void *flex_array_get(struct flex_array *fa, unsigned int element_nr);
//safe functions for usercode
#ifdef __GNUC_GNU_INLINE__ 
inline unsigned int flex_array_has_element(struct flex_array* fa, unsigned int element_nr);
#else
extern inline unsigned int flex_array_has_element(struct flex_array* fa, unsigned int element_nr);
#endif
void *flex_array_get_base(struct flex_array *fa, unsigned int element_nr);
void* flex_array_get_from_part(struct flex_array_part* part, int part_nr, struct flex_array* fa, unsigned int element_nr);
struct flex_array_part* flex_array_get_part(struct flex_array* fa, unsigned int element_nr, int* partnr);

#endif /* FLEX_ARRAY_H */
