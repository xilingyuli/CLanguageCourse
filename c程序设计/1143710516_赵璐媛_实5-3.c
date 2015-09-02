#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"1143710516_ÕÔè´æÂ_Êµ5-3.h"
/*typedef struct wordnode
{
    char Eword[30];
    char Chinese[100];
    struct wordnode *next;
} WORDNODE;
int RegSearch(char reg[], char target[]);
void LookUp(WORDNODE *head, char re[]);
WORDNODE* Create();*/
int main()
{
    FILE *f;
    char re[30];
    WORDNODE *head = (WORDNODE*)malloc(sizeof(WORDNODE)),*p = NULL;
    //head = Create();
    if((f=(fopen("data1.dat","r")))==NULL)
    {
        exit(0);
    }
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
    getchar();
    gets(re);
    LookUp(head,re);
    return 0;
}
/*int RegSearch(char reg[], char target[])
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
    WORDNODE *p = NULL,*head = NULL;
    char Eword[30],Chinese[100],a[30]="##";
    for(;;)
    {
        scanf("%s",Eword);
        if(strcmp(Eword,a)==0)
        {
            break;
        }
        if(p == NULL)
        {
            p = (WORDNODE*)malloc(sizeof(WORDNODE));
            head = p;
        }
        else
        {
            p->next = (WORDNODE*)malloc(sizeof(WORDNODE));
            p = p->next;
        }
        if(p == NULL)
        {
            exit(0);
        }
        strcpy(p->Eword,Eword);
        getchar();
        scanf("%s",Chinese);
        strcpy(p->Chinese,Chinese);
        getchar();
    }
    p->next = NULL;
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
}*/
