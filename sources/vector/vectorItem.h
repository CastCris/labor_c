#ifndef VECTOR_ITEM_H
#define VECTOR_ITEM_H
//
#include<stdlib.h>
#include<string.h>
//
struct VectorItem{
	void*	item;
	size_t	item_size;
};
//
struct VectorItem*vctItem_create(void*item,size_t item_size);
//
void*	vctItem_item(struct VectorItem*vct_item_ref);
size_t	vctItem_item_size(struct VectorItem*vct_item_ref);
//
void 	vctItem_replace(struct VectorItem*vct_item_ref,void*item,
		size_t item_size);
//
void	vctItem_delete(struct VectorItem*vct_item_ref);

#endif
