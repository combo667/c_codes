#include <stdio.h>
void even_case(int);
void odd_case(int);

//THIS IS THE MAIN FUNCTION
int main(void){

int rows=0;
printf("Input the number of rows :\n");
scanf("%d",&rows);

    if(rows%2==0){

    even_case(rows);


        }
    else
        odd_case(rows);




return 0;

}


//FOR EVEN CASES

void even_case(int rows){
int i=0,j=0,k=0;
int row=rows/2;



for(i=1;i<=rows;++i){
if(i<=row)   ++k;
        if(i>row+1)    --k;


 for(j=1;j<=(rows+1)/2;++j){

        if(j<=k){
        printf("*");

        }
        else{
        printf(" ");
        }


    }

    printf("\n");

    }
    }





//FOR ODD INPUTS

void odd_case(int rows){
int i=0,j=0,k=0;



for(i=1;i<=rows;++i){
i<=(rows+1)/2?++k:--k;



 for(j=1;j<=(rows+1)/2;++j){

        if(j<=k){
        printf("*");

        }
        else{
        printf(" ");
        }


    }

    printf("\n");

    }


}













