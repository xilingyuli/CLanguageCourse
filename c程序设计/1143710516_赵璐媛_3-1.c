#include<stdio.h>
int main()
{
    int x,y,z,count=0;
    for(x=1;x<=10;x++)
    {
        for(y=1;y<=20;y++)
        {
            for(z=1;z<=100;z++)
            {
                if(x+y+z==50&&10*x+5*y+z==100)
                {
                    printf("x = %d, y = %d, z = %d\n",x,y,z);
                    count++;
                }
            }
        }
    }
    printf("count = %d",count);
    return 0;
}
