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
void*	vctItem_item(struct VectorItem*vct_item_ref){
	return vct_item_ref->item;
}
size_t	vctItem_item_size(struct VectorItem*vct_item_ref){
	return vct_item_ref->item_size;
}
//
void 	vctItem_replace(struct VectorItem*vct_item_ref,void*item,size_t item_size){
	free(vct_item_ref->item);
	
	vct_item_ref->item_size=item_size;
	vct_item_ref->item=malloc(vctItem_item_size(vct_item_ref));
	memcpy(vct_item_ref->item,item,vctItem_item_size(vct_item_ref));
}
//
/*
void	vctItem_delete(struct VectorItem**vct_item_ref){
	free((*vct_item_ref)->item);
	free((*vct_item_ref));
}
*/
void	vctItem_delete(struct VectorItem*vct_item_ref){
	free(vct_item_ref->item);
	free(vct_item_ref);
}
