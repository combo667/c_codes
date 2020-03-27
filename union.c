#include <stdio.h>
int main(int argc, char const *argv[])
{
    union item {
        int x;
        float f;
        char c;


    };

    union item i1;
    i1.x=5;
    printf("%d\n",i1.x);
    i1.f=3.4;
    printf("%f\n",i1.f);
    i1.c='A';
    printf("%c\n",i1.c);


    return 0;
}
