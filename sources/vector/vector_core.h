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


// GET FUNCTIONS
#define VCT_INDEX(vct_ref) \
	(vct_index((vct_ref)))
#define VCT_LENGTH(vct_ref) \
    (vct_length((vct_ref)))

#define VCT_ITEM(vct_ref,index) \
	vctITEM_ITEM((vct_ref)->items[index])

#define VCT_ITEM_SIZE(vct_ref,index) \
	((VCT_ITEM_EMPTY((vct_ref),(index)))?0:\
	 vctITEM_ITEM_SIZE((vct_ref)->items[(index)]))

#define VCT_ITEM_PICK(vct_ref,index,src) \
	(VCT_ITEM_EMPTY((vct_ref),(index))?NULL:\
	 vct_item_get((vct_ref),(index),(void**)&(src)))

#define VCT_ITEM_EMPTY(vct_ref,index) \
	(vctITEM_ITEM_EMPTY((vct_ref)->items[(index)]))
// UPT FUNCTIONS
#define VCT_APPEND(vct_ref,item,item_size) \
	(vct_append((vct_ref),(void*)(item),(item_size)))

#define VCT_INSERT(vct_ref,index,item,item_size) \
	(vct_insert((vct_ref),(index),(void*)(item),(item_size)))

#define VCT_REPLACE(vct_ref,index,item,item_size) \
	(vct_replace((vct_ref),(index),(void*)(item),(item_size)))

// DEL FUNCTIONS
#define VCT_POP(vct_ref,index) \
	(!(VCT_ITEM_EMPTY((vct_ref),(index)))?vct_pop((vct_ref),(index)):NULL)

#define VCT_POPUP(vct_ref,index,src) \
	(!(VCT_ITEM_EMPTY((vct_ref),(index)))?\
	   vct_popup((vct_ref),(index),(void**)&src):NULL)

#define VCT_WIPE(vct_ref) \
	(vct_delete(&(vct_ref)))

#define VCT_WASH(vct_ref) \
	(vct_clean((vct_ref)))

#define VCT_REBOOT(vct_ref) \
	(vct_reset(&(vct_ref)))

#define VCT_REMOVE(vct_ref,index) \
	(vct_remove((vct_ref),(index)))

//
// CRUD operations
// Create
struct 	Vector*
vct_create(size_t vct_size);
// Read
static inline void*
vct_item(struct Vector*vct_ref,size_t index){
	return vctItem_item(vct_ref->items[index]);
}
static inline size_t 
vct_item_size(struct Vector*vct_ref,size_t index){
	return vctItem_item_size(vct_ref->items[index]);
}
static inline size_t 
vct_index(struct Vector*vct_ref){
	return vct_ref->vector_index;
}
static inline size_t 
vct_length(struct Vector*vct_ref){
	return vct_ref->vector_length;
}
size_t 
vct_size_t(struct Vector*vct_ref);

void 
vct_item_get(struct Vector*vct_ref,size_t index,void**src);
// Update
void
vct_append(struct Vector*vct_ref,void*item,size_t item_size);

void 			
vct_insert(struct Vector*vct_ref, size_t index,void*item,size_t item_size);

static inline void 	
vct_replace(struct Vector*vct_ref,size_t index,void*item,size_t item_size){
	vctItem_replace(vct_ref->items[index],item,item_size);
}
// Delete
void*
vct_pop(struct Vector*vct_ref,size_t index);

void 
vct_popup(struct Vector*vct_ref,size_t index,void**src);

void 
vct_clean(struct Vector*vct_ref);

void 
vct_reset(struct Vector**vct_ref);

void 
vct_remove(struct Vector*vct_ref,size_t index);

void 
vct_delete(struct Vector**vct_ref);
//---------------------------------------------------------------------------//
#endif
