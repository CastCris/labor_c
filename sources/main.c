#include<stdio.h>
#include"vector.h"
//
int main(){
	struct Vector*tst=vct_create(1);
	vct_fill_str(tst,10);
	vct_str_display(tst);

	/* UPT FUNCTIONS */
	/* NOTES 
	 * For put string(char*) in vector using the strlen
	 * add plus one for include the null character.
	 * Isn't nescessary this for static arrays.
	 */
	// Pointer char
	printf("UPDATE FUNCTIONS\n");
	char tst_str[]="12345";
	char*replace=malloc(sizeof(char)*sizeof(tst_str)/sizeof(tst_str[0]));
	strcpy(replace,tst_str);
	//printf("%s %li\n",replace,strlen(replace));
	VCT_REPLACE(tst,0,replace,strlen(replace)+1);
	// Static string
	char hello[]="Hello World!";
	VCT_APPEND(tst,hello,sizeof(hello));
	VCT_INSERT(tst,0,hello,sizeof(hello));

	// GET FUNCTIONS
	printf("GET FUNCTIONS\n");
	printf("%li\n",VCT_INDEX(tst));
	printf("%li\n",VCT_LENGTH(tst));

	char*my_str;
	VCT_ITEM_PICK(tst,0,my_str);
	my_str[0]='X';
	printf("%s\n",my_str);

	char*my_str2;
	VCT_ITEM_PICK(tst,0,my_str2);
	printf("%s\n",my_str2);

	vct_str_display(tst);
	printf("\n");

	// POP FUNTIONS
	printf("POP UP FUNCTION\n");
	char*item=VCT_POP(tst,0);
	item[0]='K';
	printf("%s\n",item);
	vct_str_display(tst);

	char*item2;
	VCT_POPUP(tst,0,item2);
	printf("%s\n",item2);

	// DEL FUNCTIONS
	VCT_WASH(tst);
	vct_set_display(tst);
	printf("\n");

	printf("%li\n",tst);
	VCT_REBOOT(tst);
	printf("%li\n",tst);

	VCT_WIPE(tst);

	free(item);
	free(item2);
	free(my_str);
	free(my_str2);
	free(replace);

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
