#include<stdio.h>
#include<string.h>
void BubbleSort(char wordList[30][30], int n);
int main()
{
    int i,n;
    char wordList[30][30],a[30]="$$";
    for(i=0;;i++)
    {
        scanf("%s",wordList[i]);
        if(strcmp(wordList[i],"$$")==0)
        {
            n = i;
            break;
        }
    }
    BubbleSort(wordList,n);
    for(i=0;i<n-1;i++)
    {
        printf("%s\n",wordList[i]);
    }
    printf("%s",wordList[n-1]);
    return 0;
}
void BubbleSort(char wordList[30][30], int n)
{
    int i,j;
    char a[30];
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(wordList[i],wordList[j])>0)
            {
                strcpy(a,wordList[i]);
                strcpy(wordList[i],wordList[j]);
                strcpy(wordList[j],a);
            }
        }
    }
}
