#include"vector_core.h"
//---------------------------------------------------------------------------//
// CRUD operations
// Create
struct     Vector*    vct_create(size_t vct_size){
    struct Vector*vct_new=malloc(sizeof(struct Vector));
    vct_new->items=malloc(sizeof(struct VectorItem*)*vct_size);
    for(size_t i=0;i<vct_size;++i)
        vct_new->items[i]=NULL;

    vct_new->vector_index=0;
    vct_new->vector_length=vct_size;

    return vct_new;
}
// Check Vector functions
static void vct_size_check
(struct Vector*vct_ref)
{
    if(VCT_INDEX(vct_ref)>=VCT_LENGTH(vct_ref)){
        VCT_LENGTH_INCRASE(vct_ref);
        vct_ref->items=realloc(vct_ref->items,
                        VCT_LENGTH(vct_ref)*sizeof(struct VectorItem));

        for(size_t i=0;i<VCT_LENGTH(vct_ref)-VCT_INDEX(vct_ref)+1;++i)
            vct_ref->items[VCT_INDEX(vct_ref)+i]=NULL;
    }
}
// Read
void    __vct_item_get
(struct Vector*vct_ref,size_t index,void**src)
{
    *src=malloc(VCT_ITEM_SIZE(vct_ref,index));
    memcpy(*src,VCT_ITEM(vct_ref,index),VCT_ITEM_SIZE(vct_ref,index));
}
// Update
void    __vct_append
(struct Vector*vct_ref,void*item,size_t item_size)
{
    vct_size_check(vct_ref);

    vct_ref->items[VCT_INDEX(vct_ref)]=vctItem_create(item,item_size);
    ++vct_ref->vector_index;
}

void    __vct_insert
(struct Vector*vct_ref,size_t index, void*item,size_t item_size)
{
    vct_size_check(vct_ref);

    for(size_t i=0;i<VCT_INDEX(vct_ref)-index;++i)
        vct_ref->items[VCT_INDEX(vct_ref)-i]=
            vct_ref->items[VCT_INDEX(vct_ref)-i-1];
    vct_ref->items[index]=vctItem_create(item,item_size);
    ++vct_ref->vector_index;
}
// Delete
void*    __vct_pop
(struct Vector*vct_ref,size_t index)
{
    void*item;
    __vct_item_get(vct_ref,index,(void**)&item);
    VCT_REMOVE(vct_ref,index);

    return item;
}

void     __vct_popup
(struct Vector*vct_ref,size_t index,void**src)
{
    __vct_item_get(vct_ref,index,src);
    VCT_REMOVE(vct_ref,index);
}

void     __vct_remove
(struct Vector*vct_ref,size_t index)
{
    vctITEM_DELETE(vct_ref->items[index]);
    for(size_t i=0;i<VCT_INDEX(vct_ref)-index-1;++i)
        vct_ref->items[index+i]=vct_ref->items[index+i+1];
    vct_ref->items[VCT_INDEX(vct_ref)-1]=NULL;

    --vct_ref->vector_index;
}


void     __vct_clean
(struct Vector*vct_ref)
{
    for(size_t i=0;i<VCT_INDEX(vct_ref);++i)
        vctITEM_ERASE(vct_ref->items[i]);
    vct_ref->vector_index=0;
}

void     __vct_reset
(struct Vector**vct_ref)
{
    for(size_t i=0;i<VCT_LENGTH(*vct_ref);++i)
        vctITEM_DELETE((*vct_ref)->items[i]);

    free((*vct_ref)->items);
    free(*vct_ref);

    *vct_ref=vct_create(VCT_LENGTH_MIN);
}

void     __vct_delete
(struct Vector**vct_ref){
    for(size_t i=0;i<VCT_LENGTH(*vct_ref);++i)
        vctITEM_DELETE((*vct_ref)->items[i]);

    free((*vct_ref)->items);
    free((*vct_ref));
}
