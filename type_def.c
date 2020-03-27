#include <stdio.h>

int main(int argc, char const *argv[])
{
    struct student{

        int x,y;
        float f;




    };

    typedef struct student s;
    s s1;
    s1.x=40;
    printf("%d",s1.x);
    return 0;
}
