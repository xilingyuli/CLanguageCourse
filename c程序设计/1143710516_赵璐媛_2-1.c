#include<stdio.h>
main()
{
    float data1,data2;
    char op;
    scanf("%f%c%f",&data1,&op,&data2);
    switch(op)
    {
        case '+':
            printf("%f+%f=%f",data1,data2,data1+data2);
            break;
        case '-':
            printf("%f-%f=%f",data1,data2,data1-data2);
            break;
        case '*':
            printf("%f*%f=%f",data1,data2,data1*data2);
            break;
        case '/':
            printf("%f/%f=%f",data1,data2,data1/data2);
            break;

    }
    return 0;
}
