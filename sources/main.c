#include<stdio.h>
#include"vector.h"

//
int main(){
	struct Vector*tst=vct_create(1);
	vct_fill_str(tst,10);
	vct_str_display(tst);

	char my_str[]="Hello World!";
	vct_insert(tst,vct_index(tst),(void*)my_str,sizeof(my_str));
	vct_insert(tst,0,(void*)my_str,sizeof(my_str));
	vct_str_display(tst);

	vct_insert_str(tst,10,vct_index(tst));
	vct_str_display(tst);

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
