#ifndef VECTOR_ITEM_H
#define VECTOR_ITEM_H
//
#include<stdlib.h>
#include<string.h>

#include<stdio.h>
//
struct VectorItem{
	void*	item;
	size_t	item_size;
};

// GET FUNCTIONS
#define vctITEM_ITEM(vctItem_ref) \
	(!((vctItem_ref))?NULL:vctItem_item((vctItem_ref)))

#define vctITEM_ITEM_SIZE(vctItem_ref) \
	(vctITEM_EMPTY((vctItem_ref))?0:vctItem_item_size((vctItem_ref)))

#define vctITEM_ITEM_EMPTY(vctItem_ref) \
	(!vctITEM_ITEM(vctItem_ref))

#define vctITEM_EMPTY(vctItem_ref) \
	(!(vctItem_ref))
// UPDATE FUNCTIONS
#define vctITEM_REPLACE(vctItem_ref,item,item_size) do{ \
	if (!vctITEM_ITEM_EMPTY((vctItem_ref))) \
		(vctItem_repalce((vctItem_ref),(void*)(item),item_size)); \
	else \
		(vctItem_ref)=vctItem_create((void*)(item),(item_size)); \
	} while(0);

// DEL FUNCTIONS
#define vctITEM_ERASE(vctItem_ref) do { \
	if (!vctITEM_ITEM_EMPTY((vctItem_ref))) \
		(vctItem_erase((vctItem_ref))); \
	}while(0)

#define vctITEM_DELETE(vctItem_ref) do{ \
	if (!vctITEM_EMPTY((vctItem_ref))) \
		(vctItem_delete(&(vctItem_ref))); \
	} while(0);

//
struct VectorItem*
vctItem_create(void*item,size_t item_size);
//
void*	
vctItem_item(struct VectorItem*vct_item_ref);

size_t
vctItem_item_size(struct VectorItem*vct_item_ref);
//
void 
vctItem_replace(struct VectorItem*vct_item_ref,void*item,size_t item_size);
//
void 
vctItem_erase(struct VectorItem*vct_item_ref);

void
vctItem_delete(struct VectorItem**vct_item_ref);

#endif
