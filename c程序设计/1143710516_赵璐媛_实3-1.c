#include<stdio.h>
#include<string.h>
int Start(char *a,char *b,int m,int n);
int End(char *a,char *b,int m,int n);
int Both(char *a,char *b,int m,int n);
int Normal(char *a,char *b,int m,int n);
int main()
{
    int i,find,start=0,end=0,m,n;
    char a[10],b[10],c[10]={"###"};
A:  scanf("%s",a);
    scanf("%s",b);
    if(strcmp(a,c)==0&&strcmp(b,c)==0)
    {
        return 0;
    }
    for(i=0;;i++)
    {
        if(a[i]=='\0')
        {
            m = i;
            break;
        }
    }
    for(i=0;;i++)
    {
        if(b[i]=='\0')
        {
            n = i;
            break;
        }
    }
    if(a[0]=='^')
    {
        start = 1;
    }
    if(a[m-1]=='$')
    {
        end = 1;
    }
    if(start==1&&end==0)
    {
        find = Start(a,b,m,n);
    }
    else if(start==0&&end==1)
    {
        find = End(a,b,m,n);
    }
    else if(start==1&&end==1)
    {
        find = Both(a,b,m,n);
    }
    else
    {
        find = Normal(a,b,m,n);
    }
    if(find==0)
    {
        printf("lost\n");
        goto A;
    }
    else
    {
        puts(b);
        goto A;
    }
}
int Start(char *a,char *b,int m,int n)
{
    int i,find=1;
    if(m-1>n)
    {
        find = 0;
    }
    a++;
    for(i=1;i<=m-1;i++)
    {
        if(*a!=*b&&*a!='.')
        {
            find = 0;
            break;
        }
        else
        {
            a++;
            b++;
        }
    }
    return find;
}
int End(char *a,char *b,int m,int n)
{
    int i,find=1;
    if(m-1>n)
    {
        find = 0;
    }
    a = a+m-2;
    b = b+n-1;
    for(i=1;i<=m-1;i++)
    {
        if(*a!=*b&&*a!='.')
        {
            find = 0;
            break;
        }
        else
        {
            a--;
            b--;
        }
    }
    return find;
}
int Both(char *a,char *b,int m,int n)
{
    int i,find=1;
    a++;
    if(m-2!=n)
    {
        find = 0;
    }
    else
    {
        for(i=1;i<=m-2;i++)
        {
            if(*a!=*b&&*a!='.')
            {
                find = 0;
                break;
            }
            else
            {
                a++;
                b++;
            }
        }

    }
    return find;
}
int Normal(char *a,char *b,int m,int n)
{
    int i,t,find=0;
    for(i=1;i<=n-m+1&&find==0;i++)
    {
        if(*a==*b||*a=='.')
        {
            find = 1;
            for(t=1;t<m&&find==1;t++)
            {
                if(*(a+t)==*(b+t)||*(a+t)=='.');
                else
                {
                    find = 0;
                }
            }
            if(find==0)
            {
                b++;
            }
            else
            {
                goto B;
            }
        }
        else
        {
            b++;
        }
    }
B:  return find;
}
