//INPUT IN A FILE USING FWRITE() FUNCTION!

#include <stdio.h>
#include <stdlib.h>
struct book {
    char title[20];
    int id;
    float price;


};

struct book* createbook(){

    struct book *b;
    b=(struct book*)malloc(sizeof(struct book));
    printf("INPUT BOOK TITLE :\n");
    scanf("%s",b->title);
    printf("INPUT BOOK ID :\n");
    scanf("%d",&b->id);
    printf("INPUT BOOK PRICE :\n");
    scanf("%f",&b->price);

    return b;


}




int main(void){

struct book *b;
b=createbook();

FILE *p;
p=fopen("hello.bin","ab");
if(!p==NULL){
fwrite(b,sizeof(struct book),1,p);

fclose(p);
free(b);
printf("OPERATION COMPLETED !\n");

}
else{
    printf("OPERATION FAILED !\n");
    free(b);
    exit(0);

}



    return 0;
}