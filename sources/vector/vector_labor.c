#include"vector_labor.h"
//---------------------------------------------------------------------------//
//
void generate_str(char**str_ref,size_t init_value){
	*str_ref=malloc(VCT_TEST_STR_SIZE);
	for(size_t i=0;i<VCT_TEST_STR_SIZE;++i)
		*str_ref[i]=(char)VCT_TEST_CHAR_GEN(i+init_value);
}
void fill_str(char*str_ref,size_t str_size,size_t init_value){
	for(size_t i=0;i<str_size;++i)
		str_ref[i]=VCT_TEST_CHAR_GEN(i+init_value);
}
//
void vct_fill_str(struct Vector*vct_ref,size_t amount_str){
	for(size_t i=0;i<amount_str;++i){
		char my_str[VCT_TEST_STR_SIZE];
		fill_str(my_str,sizeof(my_str)/sizeof(my_str[0]),i);
		vct_append(vct_ref,(void*)my_str,sizeof(my_str));
	}
}
void vct_insert_str(struct Vector*vct_ref,size_t amount_str,size_t index){
	for(size_t i=0;i<amount_str;++i){
		char my_str[VCT_TEST_STR_SIZE];
		fill_str(my_str,sizeof(my_str)/sizeof(my_str[0]),i);
		vct_insert(vct_ref,index,my_str,sizeof(my_str)/sizeof(my_str[0]));
	}
}
//
void vct_str_display(struct Vector*vct_ref){
	for(size_t i=0;i<vct_index(vct_ref);++i){
		char*copy_str;
		vct_item_get(vct_ref,(void**)&copy_str,i);
		printf("%s ",copy_str);
	}
	printf("\n");
}
