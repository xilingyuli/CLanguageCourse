#include<stdio.h>
#define M 3
#define N 4
int FindMax(int score[M][N],int m,int n,int *pRow,int *pCol);
int main()
{
    int score[M][N],i,j,*pRow,*pCol;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d",&score[i][j]);
        }
    }
    i = 1;
    j = 1;
    pRow = &i;
    pCol = &j;
    FindMax(score,M,N,pRow,pCol);
    printf("maxScore=%d,class=%d,number=%d",FindMax(score,M,N,pRow,pCol),*pRow,*pCol);
    return 0;
}
int FindMax(int score[M][N],int m,int n,int *pRow,int *pCol)
{
    int i,j,max=score[0][0];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(score[i][j]>max)
            {
                max = score[i][j];
                *pRow = i+1;
                *pCol = j+1;
            }
        }
    }
    return max;
}
