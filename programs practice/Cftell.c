#include <stdio.h>
#include <string.h>

int main(void){

FILE *p;
char arr[30];
char jubesh[]={" C PROGRAMMING"};
p=fopen("hello.txt","ar+");
fseek(p,0,SEEK_END);
/* for (size_t i = 0; i < strlen(jubesh); ++i)
{
    fputc(jubesh[i],p);
}
rewind(p);

fgets(arr,30,p);
printf("%s\n",arr); */
printf("The file has %ld charaters !\n",ftell(p));
fclose(p);




    return 0;
}