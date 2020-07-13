//Fibonacci using memoization 
//time complexity O(n)



#include <stdio.h>

int fib(int); //function prototype

int array[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; //global array

int main(int argc, char const *argv[])
{
    int num = 0;
    scanf("%d", &num);
    printf("%d", fib(num + 1));
    return 0;
}

int fib(int num)
{
    if (num <= 1)
    {
        if (array[num] == -1)
        {
            array[num] = num;
            return num;
        }
    }

    else
    {
        if (array[num - 2] == -1)
            array[num - 2] = fib(num - 2);
        if (array[num - 1] == -1)
            array[num - 1] = fib(num - 1);

        return array[num - 2] + array[num - 1];
    }
}
