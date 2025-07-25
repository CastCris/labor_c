#include<stdio.h>
#include<stdlib.h>
//
int main(){
	int**array=malloc(sizeof(int*)*10);
	for(int i=0;i<10;++i){
		array[i]=malloc(sizeof(int));
		*array[i]=i;
	}
	int*ref=array[9];
	for(int i=0;i<10;++i)
		printf("%i ",*array[i]);
	printf("\n");

	for(int i=0;i<9;++i)
		array[i]=array[i+1];
	array[9]=NULL;
	printf("%li %li\n",array[8],ref);

	for(int i=0;i<9;++i)
		printf("%i ",*array[i]);
	printf("\n");

	return 0;
}
