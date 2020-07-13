/* C atoi() function */
/* A GAPFUL NUMBER IS A NUMBER OF ATLEAST 3 DIGITS THAT IS DIVISIBLE BY THE NUMBER FORMED BY THE FIRST AND LAST DIGIT OF THE ORIGINAL NUMBER
Example  192 is divisible by 12 
583 is divisible by 53
ans so on 
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char num[20];
    int gap, div;
    int length = 0;
    char x, y, x1[3];

    printf("Input the number :\n");
    fgets(num, 20, stdin);
    length = strlen(num) - 1;
    x = num[0];
    y = num[length - 1];
    x1[0] = x;
    x1[1] = y;
    x1[2] = '\0';
    gap = atoi(num);
    div = atoi(x1);
    if (gap % div == 0)
        printf("The number %d is a gapful number !\n", gap);
    else
        printf("The number %d is not a gapful number !\n", gap);

    return 0;
}