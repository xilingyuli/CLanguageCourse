#include<stdio.h>
#include<math.h>
int main()
{
    double rate,capital,deposit;
    int n;
    scanf("%lf,%d,%lf",&rate,&n,&capital);
    deposit = capital*(pow(rate++,n)+1);
    printf("deposit = %f",deposit);
    return 0;
}
