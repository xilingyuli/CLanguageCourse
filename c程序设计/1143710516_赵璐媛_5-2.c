#include<stdio.h>
int main()
{
    static int a[5][5],b[5],c[5];
    int i,j,k=1;
    for(i=0;i<=4;i++)
    {
        for(j=0;j<=4;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<=4;i++)
    {
        b[i] = a[i][0] + a[i][1] + a[i][2] + a[i][3] + a[i][4];
    }
    for(i=0;i<=4;i++)
    {
        c[i] = a[0][i] + a[1][i] + a[2][i] + a[3][i] + a[4][i];
    }
    for(i=1;i<=4;i++)
    {
        if(b[i]!=b[0]||c[i]!=c[0])
        {
            k = 0;
        }
    }
    if(k==0)
    {
        printf("It is not a magic square!");
    }
    else
    {
        printf("It is a magic square!");
    }
    return 0;
}
