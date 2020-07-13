#include <stdio.h>
#define c 0.55f
void case_with_int(void);
void case_with_float(void);
int main(void){


case_with_float();

        return 0;}

void case_with_int(void){

int top=0,bottom=300;
unsigned int celsius=0;

while(top<=bottom){

celsius=(c*(top-32));

printf("%d  %d\n",top,celsius);
top+=20;



}



}

void case_with_float(void){

float top=0.0f,bottom=300.0f;
float celsius=0.0f;
while(top<=bottom){

celsius=(c*(top-32.0f));
printf("%.1f    %.1f\n",top,celsius); //%.1f represents that the floating point number has been roundedoff by 1 decimal places
top+=20.0f;
}



        }
