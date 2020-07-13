#include <stdio.h>
#include <string.h>

int kcalculator(int, int);
void armstrong(int, int);

int main(void)
{
    char arr[10];
    int len = 0;
    int num = 0;
    printf("Input the number :\n");
    fgets(arr, 10, stdin);
    len = strlen(arr);

    for (size_t i = 0; i < len - 1; i++)
    {
        num = num * 10 + (arr[i] - '0');
    }

    armstrong(num, len - 1);

    return 0;
}

//MAIN LOGIC PART
void armstrong(int num, int k)
{
    int number = num;
    int sum = 0;
    int mod = 0;

    for (size_t i = 0; i < k; i++)
    {
        mod = num % 10;
        sum += kcalculator(mod, k);
        num = num / 10;
    }
    if (sum == number)
    {
        printf("Number %d is a Narcissistic Number !\n", number);
    }
    else
    {
        printf("Number %d is not a Narssisistic Number !\n", number);
    }
}

int kcalculator(int num, int k)
{
    int mul = num;
    if (k > 1)
    {
        mul = mul * kcalculator(num, k - 1); //   RECURSIVE FUNCTION
    }
    else
    {
        return mul;
    }
}