#include<stdio.h>
int main()
{
    char a[100];
    int i,b,c,d=0;
    printf("Input a string:\n");
    gets(a);
    b = a[0];
    for(i=1;a[i]!='\0';i++)
    {
        c = a[i];
        if(c>b)
        {
            b = c;
            d = i;
        }
    }
    printf("The largest character of \"%s\" is \'%c\' ,The ASCII is %d.",a,a[d],b);
    return 0;
}
