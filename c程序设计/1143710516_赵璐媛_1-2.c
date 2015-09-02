#include<stdio.h>
main()
{
    char ch;
    ch = getchar();
    ch = ch - 32;
    printf("%c,%d",ch,ch);
    return 0;
}
