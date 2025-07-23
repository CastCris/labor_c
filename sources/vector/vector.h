#ifndef VECTOR_H
#define VECTOR_H
//---------------------------------------------------------------------------//
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include"vectorItem.h"
//
struct 	Vector{
	struct VectorItem**items;

	size_t	vector_index;
	size_t	vector_length;
};

#define VCT_LENGTH_INCRASE(vct_ref) (vct_ref->vector_length*=2)

#define VCT_LENGHT_MAX 1e+9
#define VCT_LENGTH_MIN 1
//
#ifdef EXTRA
#define VECTOR_EXTRA
#endif

#ifdef VECTOR_EXTRA
#include"vector_labor.h"
#endif
// CRUD operations
// Create
struct 	Vector*	vct_create(size_t vct_size);
// Check Vector functions
void	vct_size_check(struct Vector*vct_ref);
// Read
void*	vct_item(struct Vector*vct_ref,size_t index);
void 	vct_item_get(struct Vector*vct_ref,void**src,size_t index);
size_t 	vct_item_size(struct Vector*vct_ref,size_t index);

size_t 	vct_index(struct Vector*vct_ref);
size_t 	vct_length(struct Vector*vct_ref);
// Update
void 	vct_append(struct Vector*vct_ref,void*item,size_t item_size);
void 	vct_insert(struct Vector*vct_ref,
		size_t index,void*item,size_t item_size);
void 	vct_replace(struct Vector*vct_ref
		,size_t index,void*item,size_t item_size);
// Delete
void 	vct_delete(struct Vector*vct_ref);
//---------------------------------------------------------------------------//
#endif
