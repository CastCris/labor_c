#include"vectorItem.h"
//
struct VectorItem*vctItem_create(void*item,size_t item_size){
    struct VectorItem*vct_item_new=malloc(sizeof(struct VectorItem));
    vct_item_new->item=malloc(item_size);
    memcpy(vct_item_new->item,item,item_size);
    vct_item_new->item_size=item_size;

    return vct_item_new;
}
//
void     __vctItem_replace
(struct VectorItem*vct_item_ref,void*item,size_t item_size)
{
    free(vct_item_ref->item);
    
    vct_item_ref->item_size=item_size;
    vct_item_ref->item=malloc(vctITEM_ITEM_SIZE(vct_item_ref));
    memcpy(vct_item_ref->item,item,vctITEM_ITEM_SIZE(vct_item_ref));
}
//
void    __vctItem_erase
(struct VectorItem*vct_item_ref)
{
    if(vctITEM_ITEM_EMPTY(vct_item_ref))
        return;

    free(vct_item_ref->item);
    vct_item_ref->item=NULL;
    vct_item_ref->item_size=0;
}
void    __vctItem_delete
(struct VectorItem**vct_item_ref)
{
    if(vctITEM_EMPTY(*vct_item_ref))
        return;

    free((*vct_item_ref)->item);
    free((*vct_item_ref));
    (*vct_item_ref)=NULL;
}
