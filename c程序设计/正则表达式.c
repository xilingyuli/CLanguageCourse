#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 40
int main()
{
    int length_a,length_b,i,j,k,find=1;
    char a[N],b[N];
    char ch[N] = "###";
    scanf("%s",a);
    scanf("%s",b);
    length_a = strlen(a);
    length_b = strlen(b);
    while(strcmp(a,ch)!=0&&strcmp(b,ch)!=0)
    {
    if(a[0]=='^'&&a[length_a - 1]=='$')
    {
        if(length_a - 2!=length_b)
        {
            find = 0;
        }
        for(i = 1;i <= length_b;i++)
        {
            if(a[i] != b[i - 1]&&a[i]!='.')
            {
                find = 0;
            }
        }
    }
    else if (a[0] == '^')
    {
        if(length_a - 1 > length_b)
        {
            find = 0;
        }
        for(i = 1;i <= length_a - 1;i++)
        {
            if(a[i] != b[i - 1]&&a[i]!='.')
            {
                find = 0;
            }
        }
    }
    else if (a[length_a - 1] == '$')
    {
        if(length_a - 1 > length_b)
        {
            find = 0;
        }
        for(i = 1;i <= length_a - 1;i++)
        {
            if(a[length_a - i - 1] != b[length_b - i]&&a[length_a - i - 1]!='.')
            {
                find = 0;
            }
        }
    }
    else
    {
        if(length_a > length_b)
        {
            find = 0;
        }
        find = 0;
        for(j=1;j<=length_b-length_a+1;j++)
        {
            k = j;
            for(i=1;i<=length_a;i++,k++)
            {
                if(a[i-1]!=b[k-1]&&a[i-1]!='.')
                {
                    break;
                }
            }
            if(i==length_a+1)
            {
                find = 1;
                break;
            }
        }
    }
    if(find==1)
    {
        puts(b);
    }
    else
    {
        printf("error\n");
    }
    scanf("%s",a);
    scanf("%s",b);
    length_a = strlen(a);
    length_b = strlen(b);
    find = 1;
    }
    return 0;
}
