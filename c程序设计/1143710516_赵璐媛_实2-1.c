#include<stdio.h>
int main()
{
    int a,b,ret;
    ret = scanf("%d %d",&a,&b);
    if(ret==2)
    {
        printf("%d",a+b);;
    }
    else
    {
        printf("error input");
    }
    return 0;
}
