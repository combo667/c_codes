#include <stdio.h>
#include <stdlib.h>
void display(int*,int);
void input(int*,int);
int MIN(int *,int,int);
void selectionSort(int*,int);

int main(void){
    int size=0;
    printf("Input the size :\n");
    scanf("%d",&size);
    int *p;
    p=(int*)malloc(sizeof(int)*size);
    input(p,size);
    selectionSort(p,size);
    
    display(p,size);
    free(p);

}

void display(int *array,int size){
    printf("The sorted array is :\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d  ",*(array+i));
    }
    
}

void input(int *array,int size){
    printf("Input the values :\n");
    for (size_t i = 0; i < size; i++)
    {
        scanf("%d",array+i);
    }
    
}

void swap(int *array,int x,int y){
    int temp;
    temp=*(array+x);
    *(array+x)=*(array+y);
    *(array+y)=temp;

}

int MIN(int *array,int start,int end){

    int min=*(array+start);
    int index=start;
    int i=start;
    for(i;i<end;++i){
        if(*(array+i)<min){
            min=*(array+i);
            index=i;
        }
    }
    return index;

}

void selectionSort(int *array,int size){
 
    for(int i=0;i<size-1;++i){
        
        swap(array,MIN(array,i,size),i);
    }


}