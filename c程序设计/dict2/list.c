#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "word.h"
#include "tool.h"

int RegSearch(char reg[], char target[])
{
    int i,t,find,start=0,end=0,m,n;
    for(i=0;;i++)
    {
        if(target[i]=='\0')
        {
            m = i;
            break;
        }
    }
    for(i=0;;i++)
    {
        if(reg[i]=='\0')
        {
            n = i;
            break;
        }
    }
    if(target[0]=='^')
    {
        start = 1;
    }
    if(target[m-1]=='$')
    {
        end = 1;
    }
    if(start==1&&end==0)
    {
        find=1;
        if(m-1>n)
        {
            find = 0;
        }
        target++;
        for(i=1;i<=m-1;i++)
        {
            if(*target!=*reg&&*target!='.')
            {
                find = 0;
                break;
            }
            else
            {
                target++;
                reg++;
            }
        }
    return find;
    }
    else if(start==0&&end==1)
    {
        find=1;
        if(m-1>n)
        {
            find = 0;
        }
        target = target+m-2;
        reg = reg+n-1;
        for(i=1;i<=m-1;i++)
        {
            if(*target!=*reg&&*target!='.')
            {
                find = 0;
                break;
            }
            else
            {
                target--;
                reg--;
            }
        }
    return find;
    }
    else if(start==1&&end==1)
    {
        find=1;
        target++;
        if(m-2!=n)
        {
            find = 0;
        }
        else
        {
            for(i=1;i<=m-2;i++)
            {
                if(*target!=*reg&&*target!='.')
                {
                    find = 0;
                    break;
                }
                else
                {
                    target++;
                    reg++;
                }
            }
        }
    return find;
    }
    else
    {
        find=0;
        for(i=1;i<=n-m+1&&find==0;i++)
        {
            if(*target==*reg||*target=='.')
            {
                find = 1;
                for(t=1;t<m&&find==1;t++)
                {
                    if(*(target+t)==*(reg+t)||*(target+t)=='.');
                    else
                    {
                        find = 0;
                    }
                }
                if(find==0)
                {
                    reg++;
                }
                else
                {
                    goto B;
                }
            }
            else
            {
                reg++;
            }
        }
B:      return find;
    }
}

WORDNODE* Create()
{
    FILE *f;
    WORDNODE *p = NULL,*head = NULL;
    if((f=(fopen("dict","r")))==NULL)
    {
        exit(0);
    }
    head = (WORDNODE*)malloc(sizeof(WORDNODE));
    p = head;
    for(;;)
    {
        fread(p,sizeof(WORDNODE),1,f);
        if(p->next==NULL)
        {
            break;
        }
        p->next = (WORDNODE*)malloc(sizeof(WORDNODE));
        p = p->next;
    }
    fclose(f);
    return head;
}

void LookUp(WORDNODE *head, char re[])
{
    WORDNODE *p=NULL;
    p = head;
    if(p == NULL)
    {
        exit(0);
    }
    for(;p->next!=NULL;)
    {
        if(RegSearch(p->Eword,re)==1)
        {
            printf("%s %s\n",p->Eword,p->Chinese);
        }
        p = p->next;
    }
    if(RegSearch(p->Eword,re)==1)
    {
       printf("%s %s\n",p->Eword,p->Chinese);
    }
}

void DispList(WORDNODE *head)
{
    WORDNODE *p = head;
    if(p == NULL)
    {
        exit(0);
    }
    for(;p->next!=NULL;)
    {
        printf("%s %s\n",p->Eword,p->Chinese);
        p = p->next;
    }
    printf("%s %s\n",p->Eword,p->Chinese);
}

void Add(WORDNODE* head,char Eword[],char Chinese[])
{
    char nEword[30],nChinese[100];
    Trim(Eword,nEword);
    Trim(Chinese,nChinese);
    WORDNODE* p=head;
    for(;p!=NULL;)
    {
        p = p->next;
    }
    p = (WORDNODE*)malloc(sizeof(WORDNODE));
    strcpy(p->Eword,nEword);
    strcpy(p->Chinese,nChinese);
    p->next = NULL;
}

void Delete(WORDNODE *head, char re[])
{
    WORDNODE *p=NULL,*q=NULL;
    p = head;
    if(p == NULL)
    {
        exit(0);
    }
    for(;p->next!=NULL;)
    {
        if(RegSearch(p->Eword,re)==1)
        {
            q = p;
        }
        p = p->next;
        free(q);
        q = NULL;
    }
    if(RegSearch(p->Eword,re)==1)
    {
        if(RegSearch(p->Eword,re)==1)
        {
            q = p;
        }
        p = p->next;
        free(q);
        q = NULL;
    }
}

int MemWord(WORDNODE * head,int num)
{
    WORDNODE *p=head;
    struct tm *t;
    time_t timep;
    FILE *f;
    int i,j,date,count,random[7],find=1;
    char name[10];
    time(&timep);
    t = localtime(&timep);
    date = 10000*(t->tm_year+1900)+100*(t->tm_mon+1)+(t->tm_mday);
    itoa(date,name,10);
    if((f=(fopen(name,"w")))==NULL)
    {
        exit(0);
    }
    for(i=0;i<7;)
    {
        srand(time(NULL));
        random[i] = rand()%num +1;
        for(j=0;j<i;j++)
        {
            if(random[i]==random[j])
            {
                find = 0;
            }
        }
        if(find==0)
        {
            find = 1;
        }
        else
        {
            i++;
        }
    }
    i = 0;
    BubbleSort(random,7);
    for(count=1;i<7;count++)
    {
        if(count==random[i])
        {
            printf("%s %s\n",p->Eword,p->Chinese);
            fwrite(p,sizeof(WORDNODE),1,f);
            i++;
        }
        p = p->next;
    }
    fclose(f);
    return date;
}

int Review()
{
    FILE *f1,*f2,*f3;
    WORDNODE *p1=NULL,*p2=NULL,*p3=NULL;
    struct tm *t1,*t2,*t3;
    time_t timep,time1,time2,time3;
    long d1,d2,d3;
    char date1[10],date2[10],date3[10];
    time(&timep);
    time1 = timep-604800;
    t1 = gmtime(&time1);
    d1 = 10000*(t1->tm_year+1900)+100*(t1->tm_mon+1)+(t1->tm_mday);
    itoa(d1,date1,10);
    time(&timep);
    time2 = timep-2*604800;
    t2 = gmtime(&time2);
    d2 = 10000*(t2->tm_year+1900)+100*(t2->tm_mon+1)+(t2->tm_mday);
    itoa(d2,date2,10);
    time(&timep);
    time3 = timep-3*604800;
    t3 = gmtime(&time3);
    d3 = 10000*(t3->tm_year+1900)+100*(t3->tm_mon+1)+(t3->tm_mday);
    itoa(d3,date3,10);
    if((f1=(fopen(date1,"r")))!=NULL)
    {
        do
        {
            p1 = (WORDNODE*)malloc(sizeof(WORDNODE));
            fread(p1,sizeof(WORDNODE),1,f1);
            printf("%s %s\n",p1->Eword,p1->Chinese);
            p1 = p1->next;
        }
        while (p1!=NULL);
        fclose(f1);
    }
    if((f2=(fopen(date2,"r")))!=NULL)
    {
        do
        {
            p2 = (WORDNODE*)malloc(sizeof(WORDNODE));
            fread(p2,sizeof(WORDNODE),1,f2);
            printf("%s %s\n",p2->Eword,p2->Chinese);
            p2 = p2->next;
        }
        while (p2!=NULL);
        fclose(f2);
    }
    if((f3=(fopen(date3,"r")))!=NULL)
    {
        do
        {
            p3 = (WORDNODE*)malloc(sizeof(WORDNODE));
            fread(p3,sizeof(WORDNODE),1,f3);
            printf("%s %s\n",p3->Eword,p3->Chinese);
            p3 = p3->next;
        }
        while (p3!=NULL);
        fclose(f3);
    }
    return 0;
}
