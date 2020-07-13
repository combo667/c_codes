#include <stdio.h>
#include <math.h>
void calculate(double, double);

int main(void)
{
    double base, exp;
    printf("Input the base value :\n");
    scanf("%lf", &base);
    printf("Input the exponent value :\n");
    scanf("%lf", &exp);
    calculate(base, exp);

    return 0;
}

void calculate(double base, double exp)
{
double k=pow(base,exp);
    printf("The value is : %.2lf", k);
}