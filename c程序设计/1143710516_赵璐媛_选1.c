#include<stdio.h>
#include<string.h>
void QuickSort(char wordList[30][30], int low, int high);
int main()
{
    int i,low=0,high;
    char wordList[30][30],a[30]="$$";
    for(i=0;;i++)
    {
        gets(wordList[i]);
        if(strcmp(wordList[i],a)==0)
        {
            break;
        }
    }
    high = i-1;
    QuickSort(wordList,low,high);
    for(i=0;i<=high;i++)
    {
        puts(wordList[i]);
    }
    return 0;
}
void QuickSort(char wordList[30][30], int low, int high)
{
    int max=high;
    char key[30],a[30];
    strcpy(key,wordList[low]);
    for(;low<high;)
    {
        for(;high>low;high--)
        {
            if(strcmp(key,wordList[high])>0)
            {
                strcpy(a,wordList[high]);
                strcpy(wordList[high],wordList[low]);
                strcpy(wordList[low],a);
                low++;
                break;
            }
        }
        for(;low<high;low++)
        {
            if(strcmp(key,wordList[low])<0)
            {
                strcpy(a,wordList[high]);
                strcpy(wordList[high],wordList[low]);
                strcpy(wordList[low],a);
                high--;
                break;
            }
        }
    }
    if(low>0)
    {
        QuickSort(wordList,0,low);
    }
    if(max>low+1)
    {
        QuickSort(wordList,low+1,max);
    }
}
