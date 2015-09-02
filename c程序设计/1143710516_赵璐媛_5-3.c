#include<stdio.h>
main()
{
    int year,month,day,c=0,i,d=-1;
    int a[12]={31,28,31,30,31,30,31,31,30,31,30,31},b[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    scanf("%d-%d-%d",&year,&month,&day);
    if(month>12||month<1||day>a[month-1]||day<1||year<=0)
    {
        printf("%d",d);
    }
    else if(year%4==0&&year%100!=0)
    {
        for(i=0;i<month-1;i++)
        {
            c+=b[i];
        }
        c+=day;
        printf("%d",c);
    }
    else
    {
        for(i=0;i<month-1;i++)
        {
            c+=a[i];
        }
        c+=day;
        printf("%d",c);
    }
    return 0;
}
