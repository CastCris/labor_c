struct Vector{
	void** items;
	size_t item_size;

	size_t vector_index;
	size_t vector_length;
};
// CRUD operations
// Create
struct 	Vector*	vct_create(size_t vct_size,size_t item_size){
	struct Vector*vct_new=malloc(sizeof(struct Vector));
	vct_new->items=malloc(item_size*vct_size);
	vct_new->item_size=item_size;

	vct_new->vector_index=0;
	vct_new->vector_length=vct_size;

	return vct_new;
}
// Read
void*	vct_item(struct Vector*vct_ref,size_t index){
	return *(vct_ref->items+index);
}
size_t 	vct_item_size(struct Vector*vct_ref){
	return vct_ref->item_size;
}
size_t 	vct_index(struct Vector*vct_ref){
	return vct_ref->vector_index;
}
size_t 	vct_length(struct Vector*vct_ref){
	return vct_ref->vector_length;
}
// Update
void vct_size_check(struct Vector*vct_ref){
	if(vct_index(vct_ref)>=vct_length(vct_ref)){
		VCT_LENGTH_INCRASE(vct_ref);
		vct_ref->items=realloc(vct_ref->items,vct_length(vct_ref)*vct_item_size(vct_ref));
	}
}

void vct_append(struct Vector*vct_ref,void*item,size_t item_size){
	vct_size_check(vct_ref);

	(*vct_ref->items+vct_index(vct_ref))=malloc(item_size);
	memcpy((*vct_ref->items+vct_index(vct_ref)),item,item_size);
	++vct_ref->vector_index;
}
void vct_insert(struct Vector*vct_ref,size_t index,void*item,size_t item_size){
	vct_size_check(vct_ref);

	for(size_t i=0;i<vct_index(vct_ref)-index;++i)
		(*vct_ref->items+vct_index(vct_ref)-i)=(*vct_ref->items+vct_index(vct_ref)-1-i);
	//
	free((*vct_ref->items+index));
	(*vct_ref->items+index)=malloc(item_size);
	//
	memcpy((*vct_ref->items+index),item,item_size);
	++vct_ref->vector_index;
}
void vct_replace(struct Vector*vct_ref,size_t index,void*item,size_t item_size){
	free((*vct_ref->items+index));
	(*vct_ref->items+index)=malloc(item_size);
	//
	memcpy((*vct->items+index),item,item_size);
}
// Delete
void vct_delete(struct Vector*vct_ref){
	for(size_t i=0;i<vct_index(vct_ref);++i)
		free(*(vct_ref->items+i));
	free(vct_ref->items);
	free(vct_ref);
}
