#ifndef POLICYDB_H
#define POLICYDB_H

#include "flex_array.h"

struct policydb* policydb;

struct policydb {
	int mls_enabled;

	/* symbol tables */
	struct symtab symtab[SYM_NUM];

	/* symbol names indexed by (value - 1) */
	struct flex_array *sym_val_to_name[SYM_NUM];

	/* ... */
};

#endif
