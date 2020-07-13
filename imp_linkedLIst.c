#include <stdio.h>
#include <stdlib.h>

struct NODE
{

    int DATA;
    struct NODE *LINK;
};

struct NODE *HEAD = NULL;

struct NODE *CREATE_NODE()
{

    struct NODE *TEMP_HEAD;
    TEMP_HEAD = (struct NODE *)malloc(sizeof(struct NODE));
    return TEMP_HEAD;
}

void INSERT_NODE()
{

    struct NODE *TEMP, *TEMP1;
    TEMP = CREATE_NODE();
    printf("INPUT THE VALUE TO BE INSERTED :\n");
    scanf("%d", &TEMP->DATA);
    TEMP->LINK = NULL;

    if (HEAD == (struct NODE *)NULL)
    {
        HEAD = TEMP;
    }
    else
    {
        TEMP1 = HEAD;
        while (TEMP1->LINK != NULL)
        {

            TEMP1 = TEMP1->LINK;
        }
        TEMP1->LINK = TEMP;
    }
}

void DELETE_NODE()
{
    struct NODE *TEMP;

    if (!HEAD == (struct NODE *)NULL)
    {
        TEMP = HEAD;

        HEAD = HEAD->LINK;

        free(TEMP);
    }

    else
    {
        printf("CAN'NT DELETE! LIST IS ALREADY EMPTY!\n\n");
    }
}

void TRAVERSE()
{
    struct NODE *TEMP;
    if (!HEAD == NULL)
    {
        TEMP = HEAD;
        while (TEMP!= NULL)
        {
            printf("%d  ", TEMP->DATA);

            TEMP = TEMP->LINK;
        }
        printf("\n\n");
    }
    else
    {
        printf("THE LIST IS ALREADY EMPTY !\n\n");
    }
}

int choice()
{
    int ch;
    printf("PLEASE INPUT YOUR CHOICE ACCORDINGLY!\n");
    printf("INPUT 1 FOR INSERTING A  NODE.\n");
    printf("INPUT 2 FOR DETELETING A NODE.\n");
    printf("INPUT 3 FOR TRAVERSING THE NODES.\n");
    printf("INPUT 4 FOR EXIT.\n");
    scanf("%d", &ch);
    return ch;
}

int main(void)
{

    while (1)
    {
        switch (choice())
        {
        case 1:
            INSERT_NODE();
            break;
        case 2:
            DELETE_NODE();
            break;
        case 3:
            TRAVERSE();
            break;
        case 4:
            printf("Thanks for using! \n");
            exit(1);

        default:
            printf("Please input a valid choice !\n");
        }
    }

    return 0;
}