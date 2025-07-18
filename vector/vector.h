#ifndef VECTOR_H
#define VECTOR_H

#include<stdio.h>
#include<stdlib.h>
//
#define VCT_LENGTH_INCRASE(vct_ref) (vct_ref->vector_length*=2)
//
struct Vector{
	void** items;
	size_t item_size;

	size_t vector_index;
	size_t vector_length;
};
// Check vector functions
void 	vct_size_check(struct Vector*vct_ref);
// CRUD operations
// Create
struct 	Vector*	vct_create(size_t vct_size,size_t item_size);
// Read
void*	vct_item(struct Vector*vct_ref,size_t index);
size_t 	vct_item_size(struct Vector*vct_ref);
size_t 	vct_index(struct Vector*vct_ref);
size_t 	vct_length(struct Vector*vct_ref);
// Update

void 	vct_append(struct Vector*vct_ref,void*item,size_t item_size);
void 	vct_insert(struct Vector*vct_ref,size_t index,void*item,size_t item_size);
void 	vct_replace(struct Vector*vct_ref,size_t index,void*item,size_t item_size);
// Delete
void 	vct_delete(struct Vector*vct_ref);

#endif
