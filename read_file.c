#include <stdio.h>
#include <stdlib.h>
int main(void){

FILE *p;char c;
p=fopen("testx.txt","r");
if(!p==NULL){
    //c=fgetc(p);
    while(!feof(p)){
        printf("%c",c);
        c=fgetc(p);

    }

    fclose(p);
    printf("Operation successfully completed !\n");

}
else{

    printf("THE FILE CAN'T BE OPENED!\n");
    exit(1);
}





    return 0;
}