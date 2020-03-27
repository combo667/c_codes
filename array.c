#include <stdio.h>
void display(int *);
void sort(int *);
int main(void)
{
    int A[5];
    int *p = A;
    for (int i = 0; i <= 4; ++i)
        scanf("%d", p + i);
    printf("THE ARRAY VALUES WERE : \n");
    display(A);
    printf("THE SORTED ARRAY VALUES IS AS : \n");
    sort(A);

    return 0;
}
void display(int *p)
{

    for (int i = 0; i <= 4; ++i)
        printf("%d\n", *(p + i));
}
void sort(int *p)
{
    //BUBBLE SORT TECHNIQUE
    int temp = 0;
    for (int i = 0; i <= 4; ++i)
    {
        for (int j = 0; j <= 3; ++j)
        {

            if (*(p + j) > *(p + j + 1))
            {
                temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }

    for (int j = 0; j < 5; ++j)
        printf("%d\n", *(p + j));
}