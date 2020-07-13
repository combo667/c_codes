//READING BINARY FILE USING FREAD() FUNCTION
#include <stdio.h>
#include <stdlib.h>
struct book {
        char title[20];
        int id;
        float price;

};

int main(void){

    struct book b;int counter=0;
    FILE *p;
    p=fopen("hello.bin","rb");
    if(!p==NULL){
    while(fread(&b,sizeof(b),1,p)!=0){
        ++counter;
        printf("%s\n",b.title);
        printf("%d\n",b.id);
        printf("%f\n",b.price);

    }
    printf("\n THE COUNTER IS = %d",counter);
    fclose(p);
    printf("\nOPERATION SUCESSFULL!\n");

    }
    else{
        printf("OPERATION FALIED !\n");
        exit(1);
    }



    return 0;
}