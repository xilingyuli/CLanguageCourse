#include<stdio.h>
int main()
{
    int a,b,c,t=0;
    scanf("%d",&a);
    for(b=2;b<a;b++)
    {
        for(c=2;c<b&&t==0;c++)
        {
            if(b%c==0)
            {
                t=1;
            }
        }
        if(t==0)
        {

            for(c=2;c<(a-b)&&t==0;c++)
            {
                if((a-b)%c==0)
                {
                    t=1;
                }
            }
        }
        if(t==0)
        {
            printf("%d %d",b,a-b);
            break;
        }
        else
        {
            t=0;
        }
    }
    return 0;
}
