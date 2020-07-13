#include <stdio.h>
#include <string.h>

int factorial(int);
void krishnamurthy(int);

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
    krishnamurthy(num);

    return 0;
}
//MAIN LOGIC PART
void krishnamurthy(int num)
{
    int check = num, mod = 0, sum = 0;

    while (num > 0)
    {

        mod = num % 10;
        sum += factorial(mod);
        num /= 10;
    }

    if (sum == check)
    {
        printf("The number %d is a krishnamurthy number !\n", check);
    }

    else
    {
        printf("The number %d is not a krishnamurthy number !\n", check);
    }
}

int factorial(int num)
{

    if (num > 1)
    {
        num *= factorial(num - 1);
    }
    else
    {
        return num;
    }
}