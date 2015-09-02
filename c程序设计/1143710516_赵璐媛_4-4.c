#include<stdio.h>
int main()
{
    int n,flag=0,i=2;
    printf("Input m:");
    scanf("%d",&n);
    if(n<=1)
    {
        flag = 0;
    }
    else
    {
        for(i=2;i<n&&flag==0;i++)
        {
            if(n%i==0)
            {
                flag = 1;
            }
        }
    }
    if(flag==0)
    {
        printf("It is a prime number\n");
    }
    else
    {
        i = 2;
        printf("%d =",n);
START:  if(n%i==0&&n!=i)
        {
            printf(" %d *",i);
            n = n/i;
            goto START;
        }
        else if(i==n)
        {
            printf(" %d",i);
        }
        else
        {
            i++;
            goto START;
        }
    }
    return 0;
}
