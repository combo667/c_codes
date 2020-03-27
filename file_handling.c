#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200
int main(int argc, char const *argv[])
{
        char c[MAX];
    printf("Input the text !\n");
    fgets(c,MAX,stdin);
    FILE *fp;
    fp=fopen("testx.txt","w");
    if(!fp==NULL){
        for (size_t i = 0; i < strlen(c); i++)
        {
            fputc(c[i],fp);
        }

        fclose(fp);

        

    }
    else{
        printf("The file couldn't be opened !\n");
        exit(0);
    }
    return 0;
}
