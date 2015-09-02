#include<stdio.h>
int  MaxCommonFactor( int a, int  b);
int main()
{
    int a,b;
    scanf("%d,%d",&a,&b);
    printf("%d",MaxCommonFactor(a,b));
    return 0;
}
int  MaxCommonFactor( int a, int  b)
{
    int i,c;
    if(a>0&&b>0)
    {
        for(i=1;i<=a&&i<=b;i++)
        {
            if(a%i==0&&b%i==0)
            {
                c = i;
            }
        }
    }
    else
    {
        c = -1;
    }
    return c;
}
