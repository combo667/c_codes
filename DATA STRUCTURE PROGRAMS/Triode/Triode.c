#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void Hash(int *, int);
int TRIODE_NUMBER(int);

int main(int argc, char const *argv[])
{
    int check = 0;

    int start_range = 0, end_range = 0;
    printf("Input the starting Range!\n");
    scanf("%d", &start_range);
    printf("Input the end Range!\n");
    scanf("%d", &end_range);

    printf("The below tuples within range %d <-> %d are Valid Triodes.\n", start_range, end_range);

    for (int i = start_range; i < end_range; i++)
    {
        check = TRIODE_NUMBER(i);
        if (check != -1)
        {
            printf("(%d,%d,%d)\n", i, i * 2, i * 3);
        }
    }

    return 0;
}

void Hash(int *arr, int num)    //We are using HAshing 
{
    int mod = 0;
    while (num > 0)
    {
        mod = num % 10;
        arr[mod] = arr[mod] + 1;
        num = num / 10;
    }
}

int TRIODE_NUMBER(int num)
{
    int buffer[10] = {0};
    bool flag = true;

    int value = num;

    int value2 = value * 2;
    int value3 = value * 3;

    if (value / 100 != 0 && value2 / 100 != 0 && value3 / 100 != 0) //check that digit[0] is !=0
    {
        Hash(buffer, value);
        Hash(buffer, value2);
        Hash(buffer, value3);

        for (int i = 0; i < 10; ++i)
        {
            if (buffer[i] > 1)
                flag = false;
        }

        if (flag != true)
            return -1; //Failure
        else
            return 1; //Success
    }

    else
    {
        return -1; //Failure
    }
}
