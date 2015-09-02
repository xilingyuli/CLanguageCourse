#include<stdio.h>
#include<string.h>
typedef struct word
{
char Eword[30]; //保存英语单词
char Chinese[100]; //保存词性和汉语意义
}WORD;
void Trim(char oldWord[], char newWord[]);
void Seg(char words[], WORD *wArray);
void BubbleSort(WORD word[], int n);
int main()
{
    int i;
    char a[130],b[130];
    WORD word[15];
    for(i=0;i<15;i++)
    {
        gets(a);
        Trim(a,b);
        Seg(b,&word[i]);
    }
    BubbleSort(word,15);
    for(i=0;i<14;i++)
    {
        printf("%s",word[i].Eword);
        printf(" ");
        printf("%s",word[i].Chinese);
        printf("\n");
    }
        printf("%s",word[i].Eword);
        printf(" ");
        printf("%s",word[i].Chinese);
        return 0;
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
void Seg(char words[], WORD *wArray)
{
    int i,k;
    for(i=0;words[i]!=' ';i++)
    {
        wArray->Eword[i] = words[i];
    }
    wArray->Eword[i] = '\0';
    i++;
    for(k=0;words[i]!=' ';k++)
    {
        wArray->Chinese[k] = words[i];
        i++;
    }
    wArray->Chinese[k] = '\0';
}
void BubbleSort(WORD word[],int n)
{
    int i,j;
    char a[100];
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(word[i].Eword,word[j].Eword)>0)
            {
                strcpy(a,word[i].Eword);
                strcpy(word[i].Eword,word[j].Eword);
                strcpy(word[j].Eword,a);
                strcpy(a,word[i].Chinese);
                strcpy(word[i].Chinese,word[j].Chinese);
                strcpy(word[j].Chinese,a);
            }
        }
    }
}
