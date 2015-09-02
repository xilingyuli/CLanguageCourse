#include<stdio.h>
const int N = 11;
int ReadData(int *pa);
void SortData(int *pa,int n);
void InsertData(int *pa,int px,int n);
void PrintData(int *pa,int n);
int main()
{
    int a[N],n,x;
    n = ReadData(a);
    SortData(a,n);
    scanf("%d",&x);
    InsertData(a,x,n);
    PrintData(a,n+1);
    return 0;
}
int ReadData(int *pa)
{
    int i;
    for(i=0;;i++)
    {
        scanf("%d",pa);
        pa++;
        if(getchar()!=' ')
        {
            break;
        }
    }
    return i;
}
void SortData(int *pa,int n)
{
    int a,i,t;
    for(i=0;i<=n;i++)
    {
        for(t=i+1;t<=n;t++)
        {
            if((*(pa+t))<(*(pa+i)))
            {
                a = *(pa+t);
                *(pa+t) = *(pa+i);
                *(pa+i) = a;
            }
        }
    }
}
void InsertData(int *pa,int px,int n)
{
    int i,t;
    for(i=0;;i++)
    {
        if(px<=*pa)
        {
            for(t=n-i+1;t>=0;t--)
            {
                *(pa+t) = *(pa+t-1);
            }
            *pa = px;
            break;
        }
        pa++;
    }
}
void PrintData(int *pa,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",*(pa+i));
    }
    printf("%d",*(pa+n));
}
