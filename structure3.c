/*HOW TO CONTROL A ARRAY FROM A STRUCTURE WHERE THE STRUCTURE WILL BE CONTROLLED 
BY A VARIABLE */
#include <cstdlib>
#include <stdio.h>
int main(void){

struct array_control{

    int *p;

};

struct array_control *ptr;
struct array_control array;
ptr=&array;



ptr->p=(int*)malloc(sizeof(int)*5);
printf("Please input the values one by one :\n");
for(int i=0;i<5;++i){
    printf("Input the value :\n");
    scanf("%d",ptr->p+i);

}
printf("The inputted values are :\n");
for(int j=0;j<5;++j){

    printf("%d\n",*(ptr->p+j));

}

free(ptr->p);


    return 0;
}