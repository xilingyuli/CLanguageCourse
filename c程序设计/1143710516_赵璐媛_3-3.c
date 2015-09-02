#include<stdio.h>
int main()
{
    int a,b=0,n,i,sum=0;
    scanf("%d",&a);
    getchar();
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        b = 10*b + a;
        sum = sum + b;
    }
    printf("sum = %d",sum);
    return 0;
}
