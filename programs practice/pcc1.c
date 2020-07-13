/* CONVERT INPUTTER NUMBER OF DAYS TO NUMBER OF YEARS,NUMBER OF WEEKS ,NUMBER OF DAYS
EXAMPLE : INPUT =373=1YEAR,1WEEK,1DAY; */
#include <stdio.h>
void calculate(int);
int main(void){
    int days=0;
    printf("Input the number of days :\n");
    scanf("%d",&days);
    calculate(days);
}



void calculate(int days){
    printf("It is %d year/s %d week/s %d day/s\n",days/365,(days%365)/7,((days%365)%7));
}