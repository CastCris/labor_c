#include"vector_core.h"
//---------------------------------------------------------------------------//
// CRUD operations
// Create
struct 	Vector*	vct_create(size_t vct_size){
	struct Vector*vct_new=malloc(sizeof(struct Vector));
	vct_new->items=malloc(sizeof(struct VectorItem*)*vct_size);
	for(size_t i=0;i<vct_size;++i)
		vct_new->items[i]=NULL;

	vct_new->vector_index=0;
	vct_new->vector_length=vct_size;

	return vct_new;
}
// Check Vector functions
static void	vct_size_check(struct Vector*vct_ref){
	if(vct_index(vct_ref)>=vct_length(vct_ref)){
		VCT_LENGTH_INCRASE(vct_ref);
		vct_ref->items=realloc(vct_ref->items,
						VCT_LENGTH(vct_ref)*sizeof(struct VectorItem));

		for(size_t i=0;i<VCT_LENGTH(vct_ref)-VCT_INDEX(vct_ref)+1;++i)
			vct_ref->items[VCT_INDEX(vct_ref)+i]=NULL;
	}
}
// Read
void*	vct_item(struct Vector*vct_ref,size_t index){
	return vctItem_item(vct_ref->items[index]);
}
void 	vct_item_get(struct Vector*vct_ref,size_t index,void**src){
	*src=malloc(vct_item_size(vct_ref,index));
	memcpy(*src,vct_item(vct_ref,index),vct_item_size(vct_ref,index));
}
size_t 	vct_item_size(struct Vector*vct_ref,size_t index){
	return vctItem_item_size(vct_ref->items[index]);
}
size_t 	vct_index(struct Vector*vct_ref){
	return vct_ref->vector_index;
}
size_t 	vct_length(struct Vector*vct_ref){
	return vct_ref->vector_length;
}

//size_t	vct
// Update

void 	vct_append(struct Vector*vct_ref,void*item,size_t item_size){
	vct_size_check(vct_ref);

	vct_ref->items[vct_index(vct_ref)]=vctItem_create(item,item_size);
	++vct_ref->vector_index;
}
void 	vct_insert(struct Vector*vct_ref,size_t index,void*item,size_t item_size){
	vct_size_check(vct_ref);

	for(size_t i=0;i<vct_index(vct_ref)-index;++i)
		vct_ref->items[vct_index(vct_ref)-i]=
			vct_ref->items[vct_index(vct_ref)-i-1];
	vct_ref->items[index]=vctItem_create(item,item_size);
	++vct_ref->vector_index;
}
void 	vct_replace(struct Vector*vct_ref,size_t index,void*item,size_t item_size){
	vctItem_replace(vct_ref->items[index],item,item_size);
}
// Delete
void*	vct_pop(struct Vector*vct_ref,size_t index){
	void*item;
	vct_item_get(vct_ref,index,&item);
	vct_remove(vct_ref,index);

	return item;
}
void 	vct_popup(struct Vector*vct_ref,size_t index,void**src){
	vct_item_get(vct_ref,index,src);
	vct_remove(vct_ref,index);
}
void 	vct_remove(struct Vector*vct_ref,size_t index){
	vctITEM_DELETE(vct_ref->items[index]);
	for(size_t i=0;i<vct_index(vct_ref)-index-1;++i)
		vct_ref->items[index+i]=vct_ref->items[index+i+1];
	vct_ref->items[VCT_INDEX(vct_ref)-1]=NULL;

	--vct_ref->vector_index;
}


void 	vct_clean(struct Vector*vct_ref){
	for(size_t i=0;i<vct_index(vct_ref);++i)
		vctITEM_ERASE(vct_ref->items[i]);
	vct_ref->vector_index=0;
}
void 	vct_reset(struct Vector**vct_ref){
	for(size_t i=0;i<vct_length(*vct_ref);++i)
		vctITEM_DELETE((*vct_ref)->items[i]);

	free((*vct_ref)->items);
	free(*vct_ref);

	*vct_ref=vct_create(VCT_LENGTH_MIN);
}
void 	vct_delete(struct Vector**vct_ref){
	for(size_t i=0;i<vct_length(*vct_ref);++i)
		vctITEM_DELETE((*vct_ref)->items[i]);

	free((*vct_ref)->items);
	free((*vct_ref));
}
