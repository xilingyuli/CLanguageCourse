#include<stdio.h>
#include<math.h>
long Fact(int n);
int main()
{
    int n;
    printf("Input n(n>0):");
    scanf("%d",&n);
    printf("sum = %d",Fact(n));
    return 0;
}
long Fact(int n)
{
    int a,b,c=1;
    long d=0;
    for(b=1;b<=n;b++)
    {
        for(a=1;a<=b;a++)
        {
            c = a*c;
        }
        d = d+c;
        c = 1;
    }
    return d;
}

