#include<stdio.h>
int IsPrime(int x);
int main()
{
    int x;
    printf("Please input n:");
    scanf("%d",&x);
    printf("%d",IsPrime(x));
    return 0;
}
int IsPrime(int x)
{
    int i,t=1;
    x++;
    for(;;x++)
    {
        for(i=2;i<x;i++)
        {
            if(x%i==0)
            {
                t = 0;
            }
        }
        if(t==1)
        {
            break;
        }
        else
        {
            t = 1;
        }
    }
    return x;
}
