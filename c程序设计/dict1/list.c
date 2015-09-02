#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    int find=0;
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
            find = 1;
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
            find = 1;
        }
        p = p->next;
        free(q);
        q = NULL;
    }
}
