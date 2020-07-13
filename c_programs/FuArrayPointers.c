//THIS IS A PROGRAM OF ARRAY OF FUNCTION POINTERS

#include <stdlib.h>
#include <stdio.h>

int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);

int main(void)
{
    int x, y, result, choice;

    int (*op[4])(int, int);
    op[0] = add;
    op[1] = multiply;
    op[2] = divide;
    op[3] = subtract;

    while (1)
    {
        printf("Input the two number :\n");
        scanf("%d %d", &x, &y);

        printf("INPUT 1 FOR ADDITION :\n");
        printf("Input 2 for multiplication\n");
        printf("Input 3 for division\n");
        printf("Input 4 for subtraction\n");
        printf("Input  6 for exit :\n");
        printf("Input your choice :\n");
        scanf("%d", &choice);
        if (choice == 6)
            exit(1);

        result = op[choice - 1](x, y);
        printf("The result is : %d\n", result);
    }

    return 0;
}

int add(int a, int b)
{
    return a + b;
}
int subtract(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}
int divide(int a, int b)
{
    if (a > b)
        return a / b;
    else
        return b / a;
}
int multiply(int a, int b)
{
    return a * b;
}
