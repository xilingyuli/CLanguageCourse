#include<stdio.h>
int main()
{
    int a[10],i,max,min,t;
    for(i=0;i<=9;i++)
    {
        scanf("%d",&a[i]);
    }
    max = 0;
    min = 0;
    for(i=1;i<=9;i++)
    {
        if(a[i]>a[max])
        {
            max = i;
        }
        if(a[i]<a[min])
        {
            min = i;
        }
    }
    t = a[max];
    a[max] = a[min];
    a[min] = t;
    for(i=0;i<9;i++)
    {
        printf("%d ",a[i]);
    }
    printf("%d",a[9]);
    return 0;
}
