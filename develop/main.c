#include<stdio.h>
#include"vector.h"
//
void vct_display_int(struct Vector*vct_ref){ // int vector
	for(size_t i=0;i<vct_index(vct_ref);++i)
		printf("%i ",*(int*)vct_item(vct_ref,i));
	printf("\n");
}
void vct_display_str(struct Vector*vct_ref){
	for(size_t i=0;i<vct_index(vct_ref);++i){
		char copy_str[51];
		strcpy(copy_str,vct_item(vct_ref,i));
		printf("%s\n",copy_str);
	}
	printf("\n");
}
//
int main(){
	struct Vector*tst=vct_create(10,sizeof(char*)*51);
	for(size_t i=0;i<26;++i){
		char my_str[51]={};
		for(int j=0;j<50;++j)
			my_str[j]=(char)(i+j)%26+65;
		my_str[51]='\0';
		vct_append(tst,(void*)&my_str,strlen(my_str));
	}
	vct_display_str(tst);
	return 0;
}
/*
//How declare a void**
int main(){
	void**tst=malloc(sizeof(void*)*10);
	for(int i=0;i<10;++i){
		char my_str[]="Hello World!";
		//
		tst[i]=malloc(sizeof(char*)*strlen(my_str));
		memcpy(tst[i],(void*)&my_str,sizeof(char*)*strlen(my_str));
	}
	for(int i=0;i<10;++i){
		char*my_str=malloc(sizeof(char*)*20);
		strcpy(my_str,(char*)tst[i]);
		//printf("%s\n",my_str);
	}

	return 0;
}
//
//
int main(){
	char*my_str=malloc(sizeof(char*)*20);
	for(int i=0;i<20;++i)
		my_str[i]=(char)i+65;
	printf("%lx %lx\n",sizeof(my_str),sizeof(char));

	return 0;
}*/
