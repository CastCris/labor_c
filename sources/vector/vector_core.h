#ifndef VECTOR_CORE_H
#define VECTOR_CORE_H
//---------------------------------------------------------------------------//
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include"vectorItem.h"
#include"vector_struct.h"
//
#define VCT_LENGTH_INCRASE(vct_ref) (vct_ref->vector_length*=2)
#define VCT_LENGHT_MAX 1e+9
#define VCT_LENGTH_MIN 1
//#define VCT_INDEX(vct_ref) (vct_ref->vector_index)
//
// CRUD operations
// Create
struct 	Vector*	vct_create(size_t vct_size);
// Read
void*	vct_item(struct Vector*vct_ref,size_t index);
void 	vct_item_get(struct Vector*vct_ref,size_t index,void**src);
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
void 	vct_clean(struct Vector*vct_ref);
void 	vct_reset(struct Vector**vct_ref);
void 	vct_remove(struct Vector*vct_ref,size_t index);
void 	vct_delete(struct Vector*vct_ref);
void*	vct_pop(struct Vector*vct_ref,size_t index);
void 	vct_popup(struct Vector*vct_ref,size_t index,void**src);
//---------------------------------------------------------------------------//
#endif
