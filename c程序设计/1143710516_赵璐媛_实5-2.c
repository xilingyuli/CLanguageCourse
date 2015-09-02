#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"1143710516_ÕÔè´æÂ_Êµ5-2.h"
/*typedef struct wordnode
{
    char Eword[30];
    char Chinese[100];
    struct wordnode *next;
} WORDNODE;
WORDNODE* Create();
void DispList(WORDNODE *head);*/
int main()
{
    WORDNODE *head = NULL,*p=NULL;
    FILE *f;
    head = Create();
    DispList(head);
    if((f=(fopen("data1.dat","w")))==NULL)
    {
        exit(0);
    }
    p = head;
    for(;p!=NULL;)
    {
        fwrite(p,sizeof(WORDNODE),1,f);
        p = p->next;
    }
    fclose(f);
    return 0;
}
/*WORDNODE* Create()
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
}*/

