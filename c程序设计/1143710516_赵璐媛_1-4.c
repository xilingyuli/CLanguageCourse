#include<stdio.h>
int main()
{
    int a,b,c,d,e,f;
    scanf("%d",&a);
    b = a/1000;
    c = (a-1000*b)/100;
    d = (a-1000*b-100*c)/10;
    e = a-1000*b-100*c-10*d;
    f = 1000*e+100*d+10*c+b;
    printf("%d",f);
    return 0;
}
