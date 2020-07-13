#include <stdio.h>
#define my_sizeof(type) (char*)(&type+1)-(char *)(&type)
int main(void){

    double x=90;
    printf("%ld",my_sizeof(x));

    return 0;
}