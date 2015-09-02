#include<stdio.h>
int main()
{
    char ch;
    scanf("%c",&ch);
    if(ch>='A'&&ch<='Z'||ch>='a'&&ch<='z')
    {
        printf("It is an English character.");
    }
    else if(ch>='0'&&ch<='9')
    {
        printf("It is a digit character.");

    }
    else if(ch==' ')
    {
        printf("It is a space character.");
    }
    else
    {
        printf("It is other character.");
    }
    return 0;
}
