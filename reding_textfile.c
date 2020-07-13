#include <stdio.h>
#include <stdlib.h>
int main(void){

char c;
FILE *p;
p=fopen("testx.txt","r");

if(!p==NULL){
    
    while(!feof(p)){
        printf("%c",c);
        c=fgetc(p);
    }

    printf("\nOperation succedded!\n");
    fclose(p);

}
else
{
    printf("Operation not succeeded!\n");
    exit(0);
}




            return 0;
}