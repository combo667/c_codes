#include <stdio.h>
#include <stdlib.h>

struct array
{
    int *arrayptr;
    int size;
    int length;
};
void input(struct array *);
void output(struct array *);
struct array *createArray(int);
void append(struct array *);
void delete (struct array *);
void insert(struct array *);
int binary_search(struct array *, int);
void Lrotate(struct array *);
void Lshift(struct array *);
void Get(struct array *);
void Set(struct array *);
void MAX_MIN(struct array *p);
void reverse(struct array *);
void sum(struct array *);
void avg(struct array *);
void Union(struct array *, struct array *);
void Bubble_Sort(struct array *,int);

int main(void)
{

    int size = 0, choice = 0, element = 0; int sizex;
    printf("Input the size of the array you wanna create!\n");
    scanf("%d", &size);

    struct array *p;
    p = createArray(size);

    while (1)
    {
        printf("INPUT 1 FOR INPUTTING ELEMENTS !\n");
        printf("Input 2 for the output of the array!\n");
        printf("Input 3 to Append a element to the array !\n");
        printf("Input 4 for deleting an element!\n");
        printf("Input 5 for inserting an element!\n");
        printf("Input 6 for searching an element!\n");
        printf("Input 7 for Left rotating the array !\n");
        printf("Input 8 for Left shifting the array elements !\n");
        printf("Input 9 for getting the array element !\n");
        printf("Input 10 for setting an array element !\n");
        printf("Input 11 for finding the max,min elements from the  array !\n");
        printf("Input 12 for reversing the  array !\n");
        printf("Input 13 for finding sum of all elements in the  array !\n");
        printf("Input 14 for finding average of all elements in the  array !\n");
        printf("Input 15 for finding union of two arrays !\n");
        printf("Input 16 for Sorting the array !\n");
        printf("Input 17 for exit!\n");

        printf("Input your choice !\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            input(p);
            break;
        case 2:
            output(p);
            break;
        case 3:
            append(p);
            break;

        case 4:
            delete (p);
            break;
        case 5:
            insert(p);
            break;
        case 6:
            printf("Input the element you want to search for :\n");
            scanf("%d", &element);
            int index = 0;
            index = binary_search(p, element);
            if (index)
            {
                printf("The searched element is at index :%d\n", index);
            }
            else
            {
                printf("The searched element is not found !\n");
            }
            break;
        case 7:
            Lrotate(p);
            break;
        case 8:
            Lshift(p);
            break;
        case 9:
            Get(p);
            break;
        case 10:
            Set(p);
            break;
        case 11:
            MAX_MIN(p);
            break;
        case 12:
            reverse(p);
            break;
        case 13:
            sum(p);
            break;
        case 14:
            avg(p);
            break;
        case 15:
           
            printf("Input the size of array2 :\n");
            scanf("%d",&sizex);
            struct array *q;
            q=createArray(sizex);
            input(p);
            input(q);
           
          Bubble_Sort(p,size);
            Bubble_Sort(q,sizex);
            printf("The Union of array1 and array2 is :\n");
            Union(p,q);
            break;
        case 16:
            Bubble_Sort(p,p->size);
            break;
        case 17:
            free(p);
            exit(0);
            break;
        }
    }

    return 0;
}

struct array *createArray(int size)
{

    struct array *p;

    p = (struct array *)malloc(sizeof(struct array));
    p->arrayptr = (int *)malloc(sizeof(int) * size);
    p->size = size;
    p->length = 0;

    return p;
}

void input(struct array *p)
{
    int *size = (int *)malloc(sizeof(int));
    printf("Input the number of elements you want to  enter :\n");
    scanf("%d", size);
    p->length = *size;
    if (*size > p->size)
    {
        printf("Sorry but the number of elements exceeds  your array size !,Please try again!\n");
        free(size);
        return;
    }
    else
    {
        printf("Input the elements one by one !\n");
        for (size_t i = 0; i < p->length; ++i)
        {
            scanf("%d", p->arrayptr + i);
        }
        free(size);
    }
}

void output(struct array *p)
{
    if (p->length != 0)
    {
        printf("The array elements are :\n");
        for (size_t i = 0; i < p->length; ++i)
        {
            printf("%d   ", *(p->arrayptr + i));
        }
        printf("\n\n");
    }
    else
    {
        printf("Array is empty !\n\n");
    }
}

void append(struct array *p)
{

    int element = 0;
    printf("Input the element you want to append !\n");
    scanf("%d", &element);
    if (p->length != p->size)
    {
        *(p->arrayptr + p->length) = element;
        ++(p->length);
        printf("Element successfully appended !\n\n");
    }
    else
    {
        printf("Sorry! But array is Already Full!\n\n");
        return;
    }
}

void delete (struct array *p)
{
    int index = 0;
    printf("Input the index of the element !\n");
    scanf("%d", &index);
    if (p->length != 0)
    {
        for (size_t i = index; i < p->length - 1; i++)
        {
            *(p->arrayptr + i) = *(p->arrayptr + i + 1);
        }
        --(p->length);

        printf("Element successfully deleted !\n");
    }
    else
    {
        printf("Sorry but array is already empty!\n");
        return;
    }
}

void insert(struct array *p)
{

    if (p->length != p->size)
    {

        int index = 0, element = 0;
        printf("Input the index :\n");
        scanf("%d", &index);
        if (index < p->length && index >= 0)
        {
            printf("Input the element that you wish to insert !\n");
            scanf("%d", &element);
            for (size_t i = p->length; i > index; i--)
            {
                *(p->arrayptr + i) = *(p->arrayptr + i - 1);
            }
            *(p->arrayptr + index) = element;
            ++(p->length);
            printf("Element successfully inserted !\n\n");
        }
        else
        {
            printf("Array index out of range !\n\n");
            return;
        }
    }
    else
    {
        printf("Array is already filled! Can't insert more elements !\n\n");
        return;
    }
}

int binary_search(struct array *p, int key)
{

    int low, high, mid;
    low = 0;
    high = p->length;
    mid = (low + high) / 2;
    while (low <= high)
    {

        if (*(p->arrayptr + mid) == key)
        {
            return mid;
        }
        else if (key < *(p->arrayptr + mid))
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
        else if (key > *(p->arrayptr + mid))
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
    }
    return 0;
}

void Lrotate(struct array *p)
{
    int rotate = 0;
    printf("By how much bits do you want to rotate the array :\n");
    scanf("%d", &rotate);
    int temp = 0;
    for (size_t i = 0; i < rotate; i++)
    {
        temp = *(p->arrayptr);
        for (size_t i = 0; i < p->length; i++)
        {
            *(p->arrayptr + i) = *(p->arrayptr + i + 1);
        }
        *(p->arrayptr + p->length - 1) = temp;
    }

    printf("\nThe array has been successfully rotated !\n\n");
}

void Lshift(struct array *p)
{
    int shifts = 0;
    printf("By how many elements do you want to shift the array !\n");
    scanf("%d", &shifts);
    for (int j = 0; j < shifts; ++j)
    {

        for (size_t i = 0; i < p->length; i++)
        {
            *(p->arrayptr + i) = *(p->arrayptr + i + 1);
        }
        *(p->arrayptr + p->length - 1) = 0;
    }

    printf("The array has been successfully shifted by %d element!\n\n", shifts);
}

void Get(struct array *p)
{
    int index = 0;
    printf("Input the index number :\n");
    scanf("%d", &index);
    if (index >= 0 && index < p->length)
    {
        printf("\nThe element at index %d is %d.\n", index, *(p->arrayptr + index));
    }
}

void Set(struct array *p)
{
    int element, index;
    printf("Input the element !\n");
    scanf("%d", &element);
    printf("Input the index !\n");
    scanf("%d", &index);
    if (index >= 0 && index < p->length)
    {
        *(p->arrayptr + index) = element;
        printf("Element successfully replaced!\n");
    }
    else
    {
        printf("Sorry but the operation failed !\n");
    }
}

void MAX_MIN(struct array *p)
{
    int max = *(p->arrayptr);
    int min = *(p->arrayptr);
    for (size_t i = 1; i < p->length; i++)
    {
        if (*(p->arrayptr + i) > max)
            max = *(p->arrayptr + i);
    }

    printf("The max element in the array is : %d\n\n", max);

    for (size_t i = 1; i < p->length; i++)
    {
        if (*(p->arrayptr + i) < min)
            min = *(p->arrayptr + i);
    }

    printf("The min element in the array is : %d\n\n", min);
}

void reverse(struct array *p)
{
    for (size_t i = 0, j = p->length - 1; i <= j; i++, --j)
    {
        int temp = 0;
        temp = *(p->arrayptr + i);
        *(p->arrayptr + i) = *(p->arrayptr + j);
        *(p->arrayptr + j) = temp;
    }
    printf("The array is successfully reversed !\n");
}

void sum(struct array *p)
{
    int sum = 0;
    for (size_t i = 0; i < p->length; i++)
    {
        sum += *(p->arrayptr + i);
    }

    printf("The sum of all the elements in the array is : %d\n", sum);
}

void avg(struct array *p)
{
    int avg = 0;
    int sum = 0;
    for (size_t i = 0; i < p->length; i++)
    {
        sum += *(p->arrayptr + i);
    }
    avg = sum / p->length;

    printf("The average of all the elements in the array is :%d\n", avg);
}

void Union(struct array *p, struct array *q)
{
    struct array *c = (struct array *)malloc(sizeof(struct array));
    c->arrayptr = (int *)malloc(sizeof(int) * 20);

    int i = 0, j = 0, k = 0;
    while (i < p->length && j < q->length)
    {

        if (*(p->arrayptr + i) < *(q->arrayptr + j))
        {
            *(c->arrayptr + k) = *(p->arrayptr + i);
            i++;
            k++;
        }
        else if (*(q->arrayptr + j) < *(p->arrayptr + i))
        {
            *(c->arrayptr + k) = *(q->arrayptr + j);
            j++;
            k++;
        }
        else
        {
            *(c->arrayptr + k) = *(p->arrayptr + i);
            ++i;
            ++j;
            ++k;
        }
    }

    for (; i < p->length; ++i)
    {
        *(c->arrayptr + k) = *(p->arrayptr + i);
        ++k;
    }

    for (; j < q->length; ++j)
    {
        *(c->arrayptr + k) = *(q->arrayptr + j);
        ++k;
    }

    c->length = k;
    c->size = 20;

    output(c);

    free(c);
}

void Bubble_Sort(struct array *p,int size){
    int temp=0;

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size-1; j++)
        {
            if(*(p->arrayptr+j)>*(p->arrayptr+j+1)){
                temp=*(p->arrayptr+j);
                *(p->arrayptr+j)=*(p->arrayptr+j+1);
                *(p->arrayptr+j+1)=temp;
            }
        }
        
    }
    


}