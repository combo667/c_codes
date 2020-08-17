#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *ConvertIntToString(int);
int TRIODE_TUPLE(int);
int length(int);


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
        check = TRIODE_TUPLE(i);
        if (check != -1)
        {
            printf("(%d,%d,%d)\n", i, i * 2, i * 3);
        }
    }

    return 0;
}

char *ConvertIntToString(int num)
{
    int mod = 0;
    char *buffer = (char *)malloc(sizeof(char) * 4);
    int i = 0;
    while (num > 0)
    {
        mod = num % 10;
        buffer[i] = '0' + mod;
        num /= 10;
        ++i;
    }
    buffer[3] = '\0';

    return buffer;
}

int TRIODE_TUPLE(int num)
{
    int value = num;
    bool flag = true;
    int Hash[10] = {0};
    char *array = NULL;

    if (length(value) == 3 && length(value * 2) == 3 && length(value * 3) == 3)
    {
        char *buffer = (char *)malloc(sizeof(char) * 11);
        array = ConvertIntToString(value);
        strcat(buffer, array);
        free(array);
        array = ConvertIntToString(value * 2);
        strcat(buffer, array);
        free(array);
        array = ConvertIntToString(value * 3);
        strcat(buffer, array);
        free(array);
        array = NULL;

        for (int i = 0; buffer[i] != '\0'; i++)
        {
            Hash[buffer[i] - 48]++;
        }

        for (int i = 0; i < 10; i++)
        {
            if (Hash[i] > 1)
                flag = false;
        }

        free(buffer);

        if (flag != false)
            return 1;
        else
            return -1;
    }
    else
    {
        return -1;
    }
}

int length(int num)
{
    if (num == 0)
        return 0;
    return length(num / 10) + 1;
}