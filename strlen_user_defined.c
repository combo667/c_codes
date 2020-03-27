#include <stdio.h>
#define max 30

int strr_length(char *p);
char* rev_str(char *);

int main(void){
    
        char s[max];
        printf("INPUT THE STRING LESS THAN 20 CHARACTERS IN LENGTH : \n");
        scanf("%s",s);
        printf("THE LENGTH OF the string is : %d \n",strr_length(s));

        
        printf("The reversed string is :  ");
        printf("%s",rev_str(s));
        return 0;}

int strr_length(char *p){
    int i=0;
    while(*(p+i)!='\0'){
        ++i;

    }

    return i;


}

char* rev_str(char *p){

char temp=' ';
int l=0;
for(l=0;*(p+l)!='\0';++l);
for(int i=0;i<l/2;++i){
    temp=*(p+i);
    *(p+i)=*(p+(l-1)-i);
    *(p+(l-1)-i)=temp;

}

return p;




}