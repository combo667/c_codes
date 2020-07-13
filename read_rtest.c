#include <stdio.h>
int main(void){

int y;

FILE *p;
p=fopen("rtest.bin","rb");

fread(&y,sizeof(int),1,p);fread(&y,sizeof(int),1,p);
printf("%d",y);
fclose(p);
printf("\nDONE\n");


}