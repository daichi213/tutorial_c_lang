#include <stdio.h>
#include <math.h>

void quadratic_eq(double a, double b, double c);

int main(void)
{
    quadratic_eq(1,-4,4);
}

void quadratic_eq(double a, double b, double c)
{
    double num = 2;
    printf("%5.3f\n", (-b + sqrt(pow(b, num) - 4*a*c)) / num / a);
    printf("%5.3f\n", (-b - sqrt(pow(b, num) - 4*a*c)) / num / a);
}