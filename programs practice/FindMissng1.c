/* //This program finds multiple missing elements from and array of sorted integers
 */

#include <stdio.h>

int main(void){

int array[10]={1,2,3,4,5,6,7,8,9,12};
int diff=array[0]-0;
for (int i = 0; i < 10; i++)
{
    if(array[i]-i != diff){
        while(diff<array[i]-i){
            printf("The missing element is :%d\n",diff+i);
            ++diff;
        }
    }
}








    return 0;
}