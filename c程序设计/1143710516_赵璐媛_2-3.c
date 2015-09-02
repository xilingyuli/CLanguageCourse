#include<stdio.h>
#include<math.h>
#define EPS 1e-6
int main()
{
    float a,b,c,d,x1,x2,e,f,g;
    printf("Please enter the coefficients a,b,c:");
    scanf("%f,%f,%f",&a,&b,&c);
    d = b*b-4*a*c;
    if(a!=0)
    {
        e = fabs(d);
        f = -b/(2*a);
        if(e<EPS)
        {
            printf("x1 = x2 = %.2f",f);
        }
        else if(d>0)
        {
            x1 = -(b-sqrt(d))/(2*a);
            x2 = -(b+sqrt(d))/(2*a);
            printf("x1 = %.2f, x2 = %.2f",x1,x2);
        }
        else
        {
            g = sqrt(e)/(2*a);
            printf("x1 = %.2f + %.2fi, x2 = %.2f - %.2fi",f,g,f,g);
        }

    }
    else
    {
        printf("It is not a quadratic equation!");
    }
    return 0;
}
