#include<stdio.h>
int main()
{
    const double PI = 3.14159;
    double r,surface,volume;
    printf("Input r:");
    scanf("%lf",&r);
    surface = 4*PI*r*r;
    volume = 4*PI*r*r*r/3;
    printf("surface = %lf\n",surface);
    printf("volume = %lf",volume);
    return 0;
}
