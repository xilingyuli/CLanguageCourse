#include<stdio.h>
#include<ctype.h>
#include<string.h>

int IsNumIn(char word[])
{
    int i,t=0;
    for(i=0;word[i]!='\0';i++)
    {
        if(word[i]>='0'&&word[i]<='9')
        {
            t = 1;
            break;
        }
    }
    return t;
}

int IsSpcIn(char word[])
{
    int i,n=0;
    for(i=0;word[i]!='\0';i++)
    {
        if(word[i]==' ')
        {
            n++;
        }
    }
    return n;
}

void Trim(char oldWord[], char newWord[])
{
    int front=0,behind=0,n,t;
    unsigned int i;
    while(oldWord[front]==' '||oldWord[front]=='\t'||oldWord[front]=='\n')
    {
        front++;
    }
    i = strlen(oldWord);
    while(oldWord[i-1]==' '||oldWord[i-1]=='\t'||oldWord[i-1]=='\n')
    {
        i--;
        behind++;
    }
    n = strlen(oldWord)-front-behind;
    for(t=0;t<n;t++)
    {
        newWord[t] = oldWord[front+t];
    }
    newWord[t] = '\0';
}

void Seg(char words[], char wArray[][100] )
{
    int i,j=0,k;
    for(i=0;words[i]!='\0';i++)
    {
        for(k=0;words[i]!=' ';k++)
        {
            wArray[j][k] = words[i];
            i++;
        }
        if(words[i]==' ')
        {
            wArray[j][k] = '\0';
            j++;
        }
    }
    wArray[j][k] = '\0';
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

