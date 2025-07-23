#include"vector.h"
//
void vct_fill_str(struct Vector*vct_ref,size_t amount_str){
	for(size_t i=0;i<amount_str;++i){
		char my_str[1];
		for(size_t j=0;j<sizeof(my_str)/sizeof(my_str[0]);++j)
			my_str[j]=(char)((int)(i+j)%26+65);
		vct_append(vct_ref,(void*)my_str,sizeof(my_str));
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
