#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
#define A_EMPTY(a_ref) do{\
    if(!a_ref) \
        a_ref=a_create(100); \
    } while(0)
//
struct A{
    int x;
};
struct A*a_create(int x){
    struct A*a_new=malloc(sizeof(struct A));
    a_new->x=x;

    return a_new;
}

int main(){
    struct A*tst=NULL;
    A_EMPTY(tst);
    printf("%i\n",tst->x);

    return 0;
}
