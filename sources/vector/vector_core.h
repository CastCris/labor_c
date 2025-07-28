#ifndef VECTOR_CORE_H
#define VECTOR_CORE_H
//---------------------------------------------------------------------------//
#include<stdint.h>
#include<stddef.h>
#include<stdlib.h>
#include<string.h>
#include"vectorItem.h"
#include"vector_struct.h"
//
#define VCT_LENGTH_INCRASE(vct_ref) (vct_ref->vector_length*=2)
#define VCT_LENGHT_MAX 1e+9
#define VCT_LENGTH_MIN 1
//
struct 	Vector*vct_create
(size_t vct_size);

// Read
#define VCT_INDEX(vct_ref) \
	(__vct_index((vct_ref)))

#define VCT_INDEX_VALID(vct_ref,index) \
    (__vct_index_valid((vct_ref),(index)))

#define VCT_LENGTH(vct_ref) \
    (__vct_length((vct_ref)))

#define VCT_SIZE_T(vct_ref) \
    (__vct_size_t((vct_ref)))


#define VCT_ITEM(vct_ref,index) \
    (__vct_item((vct_ref),(index)))

#define VCT_ITEM_SIZE(vct_ref,index) \
    (__vct_item_size((vct_ref),(index))) //

/* */
#define VCT_ITEM_PICK(vct_ref,index,src) \
    (__vct_item_get((vct_ref),(index),(void**)&(src))) //

#define VCT_ITEM_EMPTY(vct_ref,index) \
	(vctITEM_ITEM_EMPTY((vct_ref)->items[(index)]))


static inline size_t    __vct_index
(struct Vector*vct_ref){
	return vct_ref->vector_index;
}

static inline int       __vct_index_valid
(struct Vector*vct_ref,size_t index)
{
    return (VCT_INDEX(vct_ref)<=index)?0:1;
}

static inline size_t    __vct_length
(struct Vector*vct_ref)
{
	return vct_ref->vector_length;
}

size_t                  __vct_size_t //
(struct Vector*vct_ref);


static inline void*     __vct_item
(struct Vector*vct_ref,size_t index)
{
	return vctITEM_ITEM(vct_ref->items[index]);
}

static inline size_t    __vct_item_size
(struct Vector*vct_ref,size_t index){
    return vctITEM_ITEM_SIZE(vct_ref->items[index]);
}

void                    __vct_item_get
(struct Vector*vct_ref,size_t index,void**src);

// Update
#define VCT_APPEND(vct_ref,item,item_size) \
	(__vct_append((vct_ref),(void*)(item),(item_size)))

#define VCT_INSERT(vct_ref,index,item,item_size) \
	(__vct_insert((vct_ref),(index),(void*)(item),(item_size))) //

#define VCT_REPLACE(vct_ref,index,item,item_size) \
	(__vct_replace((vct_ref),(index),(void*)(item),(item_size))) //
                                                               //

void    __vct_append
(struct Vector*vct_ref,void*item,size_t item_size);

#ifndef VECTOR_SAFE
    void                __vct_insert
    (struct Vector*vct_ref, size_t index,void*item,size_t item_size);

    static inline void 	__vct_replace
    (struct Vector*vct_ref,size_t index,void*item,size_t item_size){
        vctITEM_REPLACE(vct_ref->items[index],item,item_size);
    }
#else
    void    safe__vct_insert
    (struct Vector*vct_ref,size_t index,void*item,size_t item_size);

    void    safe__vct_replace
    (struct Vector*vct_ref,size_t index,void*item,size_t item_size);
#endif

// Delete or manipulate the address vector
#define VCT_POP(vct_ref,index) \
    (__vct_pop((vct_ref),(index))) //

/* */
#define VCT_POPUP(vct_ref,index,src) \
    (__vct_popup((vct_ref),(index),(void**)&(src))) //

/* */
#define VCT_WIPE(vct_ref) \
	(__vct_delete(&(vct_ref)))

#define VCT_WASH(vct_ref) \
	(__vct_clean((vct_ref)))

/* */
#define VCT_REBOOT(vct_ref) \
	(__vct_reset(&(vct_ref)))

#define VCT_REMOVE(vct_ref,index) \
	(__vct_remove((vct_ref),(index)))


void*   __vct_pop
(struct Vector*vct_ref,size_t index);

void    __vct_popup
(struct Vector*vct_ref,size_t index,void**src);

void    __vct_clean
(struct Vector*vct_ref);

void    __vct_reset
(struct Vector**vct_ref);

void    __vct_remove
(struct Vector*vct_ref,size_t index);

void    __vct_delete
(struct Vector**vct_ref);
//---------------------------------------------------------------------------//
#endif
