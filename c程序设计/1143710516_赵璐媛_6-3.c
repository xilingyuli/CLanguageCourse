#include<stdio.h>
int main()
{
    int a[40],b[10]={0,0,0,0,0,0,0,0,0,0},i,t;
    char ch='*';
    printf("Input the feedbacks of 40 students:\n");
    for(i=0;i<=39;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]-1]++;
    }
    printf("Feedback    Count    Histogram\n");
    for(i=0;i<=8;i++)
    {
        printf("%8d    %5d    ",i+1,b[i]);
        for(t=1;t<=b[i];t++)
        {
            printf("%c",ch);
        }
        printf("\n");
    }
    printf("%8d    %5d    ",10,b[9]);
    for(t=1;t<=b[i];t++)
    {
        printf("%c",ch);
    }
    return 0;
}
