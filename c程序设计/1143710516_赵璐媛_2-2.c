#include<stdio.h>
main()
{
    char sex,sport,diet;
    float faHeight,moHeight,height;
    scanf(" %c",&sex);
    scanf("%f",&faHeight);
    scanf("%f",&moHeight);
    getchar();
    scanf("%c",&sport);
    getchar();
    scanf("%c",&diet);
    if(sex=='m'||sex=='M')
    {
        height = (faHeight + moHeight)*0.54;
    }
    else
    {
        height = (faHeight*0.923+moHeight)/2;
    }
    if(sport=='y'||sport=='Y')
    {
        height = height*1.02;
    }
    if(diet=='y'||diet=='Y')
    {
        height = height*1.015;
    }
    printf("Your future height will be %.0f(cm)\n",height);
    return 0;
}
