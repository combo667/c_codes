#include <stdio.h>
void display(struct book );
struct book input(void);


struct book{
    int id;
    char title[20];
    float price;

};



int main(void){




struct book b1;

b1=input();
display(b1);


        return 0;
}

struct book input(void){
    struct book b;
printf("Input the book ID :\n");
scanf("%d",&b.id);
printf("Input the book title :\n");
scanf("%s",&b.title);
printf("Input the book price :\n");
scanf("%f",&b.price);

    return b;
}

void display(struct book b){
    printf("The name of the book is :%s\n",b.title);
    printf("The ID of the book is :%d\n",b.id);
    printf("The price of the book is :%.2f\n",b.price);


}