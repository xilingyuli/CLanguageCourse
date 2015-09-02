#include<stdio.h>
int Least_Common_Multiple(int a,int b);
int main()
{
    int a,b;
    printf("Input a,b:");
    scanf("%d",&a);
    getchar();
    scanf("%d",&b);
    if(a>0&&b>0)
    {
        printf("Least Common Multiple of %d and %d is %d",a,b,Least_Common_Multiple(a,b));
    }
    else
    {
        printf("Input error!");
    }
    return 0;
}
int Least_Common_Multiple(int a,int b)
{
    int i;
    for(i=a;;i++)
    {
        if(i%a==0&&i%b==0)
        break;
    }
    return i;
}
