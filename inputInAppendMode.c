/* THIS IS A PROGRAM TO APPEND ANY TEST TO A TXT FILE */
/* MOREOVER THIS ALSO ADDS A NEWLINE CHARACTER INTO THE FILE AFTER ALL THE CHRACTERS ARE INPUTTED */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 200
int main(void)
{

    char s[MAX];
    FILE *p;
    p = fopen("testx.txt", "a");
    if (!p == NULL)
    {
        printf("Input the text !\n");
        fgets(s, MAX, stdin);
        size_t i;
        for (i = 0; i < strlen(s)-1; i++)
        {
            fputc(s[i], p);
        }
        s[i]='\n';  /* this is line where the newline character get inserted in the file */
        fputc(s[i],p);
        

        fclose(p);
        printf("Operation completed !\n");
    }
    else
    {
        printf("Couldn't open the file !\n");
        exit(1);
    }

    return 0;
}