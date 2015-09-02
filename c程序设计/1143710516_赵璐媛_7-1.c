#include<stdio.h>
#include<string.h>
int FindString(char *str,char *sub);
int main()
{
    char str[20],sub[10];
    gets(str);
    gets(sub);
    printf("%d",FindString(str,sub));
    return 0;
}
int FindString(char *str,char *sub)
{
    int i,n=0,t;
    char a[10];
    for(t=0;sub[t]!='\0';t++);
    for(i=0;str[i+t-1]!='\0';i++)
    {
        strncpy(a,str+i,t);
        if(strncmp(a,sub,t)==0)
        {
            n++;

        }
    }
    return n;
}
