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
//
struct VectorItem*vctItem_create
(void*item,size_t item_size);

// GET FUNCTIONS
#define vctITEM_ITEM(vctItem_ref) \
	(__vctItem_item((vctItem_ref)))

#define vctITEM_ITEM_SIZE(vctItem_ref) \
    (__vctItem_item_size((vctItem_ref)))

#define vctITEM_ITEM_EMPTY(vctItem_ref) \
	(!vctITEM_ITEM(vctItem_ref))

#define vctITEM_EMPTY(vctItem_ref) \
	(!(vctItem_ref))

static inline void*	    __vctItem_item
(struct VectorItem*vct_item_ref)
{
    return vctITEM_EMPTY(vct_item_ref)?NULL:vct_item_ref->item;
}

static inline size_t    __vctItem_item_size
(struct VectorItem*vct_item_ref)
{
    return vctITEM_EMPTY(vct_item_ref)?0:vct_item_ref->item_size;
}

// UPDATE FUNCTIONS
#define vctITEM_REPLACE(vctItem_ref,item,item_size) \
    (__vctItem_replace((vctItem_ref),(item),(item_size)))

void    __vctItem_replace //
(struct VectorItem*vct_item_ref,void*item,size_t item_size);

// DEL FUNCTIONS
#define vctITEM_ERASE(vctItem_ref) \
    (__vctItem_erase((vctItem_ref)))

/* */
#define vctITEM_DELETE(vctItem_ref) \
    (__vctItem_delete(&(vctItem_ref)))

void    __vctItem_erase // 
(struct VectorItem*vct_item_ref);

void    __vctItem_delete //
(struct VectorItem**vct_item_ref);

#endif
