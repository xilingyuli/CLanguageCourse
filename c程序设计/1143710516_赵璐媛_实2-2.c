#include<stdio.h>
#include<math.h>
int main()
{
    int salary,hour,b,d,e,f,i;
    float a;
    long long c;
    i = 0;
    scanf("%d %d",&salary,&hour);
    a = (float)salary/hour;
    b = salary/hour;
    if((a-b)>=0.5)
    {
        b = b+1;
    }
    c = (long long)b*b;
    while(c/pow(10,i)>=1)
    {
        i++;
    }
    d = c%10;
    e = ((c-d)%100)/10;
    f = ((c-d-10*e)%1000)/100;
    printf("%.2f\n",a);
    printf("%d\n",b);
    printf("%d\n",i);
    printf("%d %d %d",f,e,d);
    return 0;
}
