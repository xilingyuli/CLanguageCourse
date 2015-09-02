#include<stdio.h>
int main()
{
    int n=0,a=0;
    while(a==0)
    {
        n++;
        if(n%2==1&&n%3==2&&n%4==3&n%5==4&&n%6==5&&n%7==0)
        {
            a=1;
        }
    }
    printf("%d",n--);
    return 0;
}
