#include<stdio.h>
struct telephone
{
    char name[10];
    char telno[20];
};
void search(struct telephone b[],char *x,int n);
int main()
{
    int i,n;
    char a[10];
    struct telephone b[10];
    for(i=0;;i++)
    {
        printf("Please input name:");
        gets(b[i].name);
        if(b[i].name[0]=='#')
        {
            n = i;
            break;
        }
        printf("Please input telephone:");
        gets(b[i].telno);
    }
    printf("Please input find name:");
    gets(a);
    search(b,a,n);
    return 0;
}
void search(struct telephone b[],char *x,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(b[i].name,x)==0)
        {
            printf("the telephone is %s",b[i].telno);
            break;
        }
    }
    if(i==n)
    {
        printf("Not found!");
    }
}
