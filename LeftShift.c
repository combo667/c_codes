#include <stdio.h>
#include <stdlib.h>




struct array{
int  *arrptr;
int length;
int size;


};
void shift(struct array*,int);
void output(struct array*);
void input(struct array*);
struct array* createArray(int);
void rotate(struct array*,int);




int main(void)
{

    struct array *A;
    int size,shifts,rotates;
    printf("Input the size of the array !\n");
    scanf("%d", &size);
    A=createArray(size);
    input(A);
    printf("Input the number of rotates you want!\n");
    scanf("%d",&rotates);
    // shift(A,shifts);
    rotate(A,rotates);
    output(A);
    free(A);



    return 0;
}

struct array* createArray(int size){

    struct array *p;
    p=(struct array*)malloc(sizeof(struct array));

    p->arrptr=(int*)malloc(sizeof(int)*size);
    p->length=0;
    p->size=size;
    return p;

}

void input(struct array *p){
    printf("Input the number of elements you want to input to the array!\n");
    scanf("%d",&p->length);
    printf("Input the elements :\n");
    for (size_t i = 0; i < p->length; i++)
    {
        scanf("%d",p->arrptr+i);
    }
    



}

void output(struct array *p){

    for (size_t i = 0; i < p->length; i++)
    {
      printf("%d  ",*(p->arrptr+i));
    }
    printf("\n\n");
    
}

void shift(struct array *p,int shifts){

    for(int j=0;j<shifts;++j){

        for (size_t i = 0; i < p->length; i++)
        {
            *(p->arrptr+i)=*(p->arrptr+i+1);
        }
        *(p->arrptr+p->length-1)=0;


    }



}

void rotate(struct array *p,int rotate){
    int temp=0;
    for (size_t i = 0; i < rotate; i++)
    {
            temp=*(p->arrptr);
        for (size_t i = 0; i < p->length; i++)
        {
            *(p->arrptr+i)=*(p->arrptr+i+1);


        }
            *(p->arrptr+p->length-1)=temp;
        
    }
    



}
