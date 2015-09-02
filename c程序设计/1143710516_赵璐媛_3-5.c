#include<stdio.h>
int main()
{
    int a,count=0,sum=0;
    for(;;)
    {
        scanf("%d",&a);
        if(a>0)
        {
            sum+=a;
            count++;
        }
        else if(a<0) continue;
        else
        {
            break;
        }
    }
    printf("sum = %d, count = %d",sum,count);
    return 0;
}
