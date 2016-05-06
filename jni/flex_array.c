#include "flex_array.h"

static inline __u32 reciprocal_divide(__u32 A, __u32 R)
{
	return (__u32)(((__u64)A * R) >> 32);
}

static int fa_element_to_part_nr(struct flex_array *fa,
					unsigned int element_nr)
{
	return reciprocal_divide(element_nr, fa->reciprocal_elems);
}

/*
 * If a user requests an allocation which is small
 * enough, we may simply use the space in the
 * flex_array->parts[] array to store the user
 * data.
 */
static inline int elements_fit_in_base(struct flex_array *fa)
{
	unsigned int data_size = fa->element_size * fa->total_nr_elements;
	if (data_size <= FLEX_ARRAY_BASE_BYTES_LEFT)
		return 1;
	return 0;
}

static unsigned int index_inside_part(struct flex_array *fa,
					unsigned int element_nr,
					unsigned int part_nr)
{
	unsigned int part_offset;

	part_offset = element_nr - part_nr * fa->elems_per_part;
	return part_offset * fa->element_size;
}

inline void* flex_array_get_from_part(struct flex_array_part* part, int part_nr, struct flex_array* fa, unsigned int element_nr)
{
	return &part->elements[index_inside_part(fa, element_nr, part_nr)];
}

struct flex_array_part* flex_array_get_part(struct flex_array* fa, unsigned int element_nr, int* partnr)
{
	int part_nr = fa_element_to_part_nr(fa, element_nr);
	struct flex_array_part* part = fa->parts[part_nr];
	if(partnr)
		*partnr = part_nr;
	return part;
}

void *flex_array_get_base(struct flex_array *fa, unsigned int element_nr)
{
	int part_nr = 0;
	struct flex_array_part *part;

	if (!elements_fit_in_base(fa))
		return NULL;

	part = (struct flex_array_part *)&fa->parts[0];
	return &part->elements[index_inside_part(fa, element_nr, part_nr)];
}

inline unsigned int flex_array_has_element(struct flex_array* fa, unsigned int element_nr)
{
	if (!fa->element_size)
		return 0;
	if (element_nr >= (unsigned int)fa->total_nr_elements)
		return 0;
	return 1;
}

void *flex_array_get(struct flex_array *fa, unsigned int element_nr)
{
	int part_nr = 0;
	struct flex_array_part *part;

	if (!flex_array_has_element(fa, element_nr))
		return NULL;
	if (elements_fit_in_base(fa))
		part = (struct flex_array_part *)&fa->parts[0];
	else
	{
		part_nr = fa_element_to_part_nr(fa, element_nr);
		part = fa->parts[part_nr];
		if (!part)
			return NULL;
	}

	return &part->elements[index_inside_part(fa, element_nr, part_nr)];
}
