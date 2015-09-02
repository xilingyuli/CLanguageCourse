#include<stdio.h>
void inverse(char str[],int m,int n);
int main()
{
    int m,n;
    char str[20];
    printf("input m,n:");
    scanf("%d,%d",&m,&n);
    printf("input the string:");
    getchar();
    gets(str);
    inverse(str,m,n);
    printf("the inverse string:");
    puts(str);
    return 0;
}
void inverse(char str[],int m,int n)
{
    int i,b;
    char a;
    b = n/2-1;
    for(i=0;i<=b;i++)
    {
        a = str[m+i-1];
        str[m+i-1] = str[m+n-i-2];
        str[m+n-i-2] = a;
    }
}
