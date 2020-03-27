#include <stdlib.h>
#include <stdio.h>
int main(void){

int ALICE=0,BOB=0;

struct candidate{

    int array[3];

};

struct candidate alice ;
struct candidate bob;
struct candidate *q;
struct candidate *p;
p=&alice;q=&bob;
for(int i=0;i<3;++i)
    scanf("%d",&p->array[i]);

for(int i=0;i<3;++i)
    scanf("%d",&q->array[i]);

for(int i =0;i<3;++i){
    if(p->array[i]>q->array[i])
        ++ALICE;

    else if(p->array[i]==q->array[i])
        continue;
    else
        ++BOB;
}

printf("%d %d",ALICE,BOB);



    return 0;
}