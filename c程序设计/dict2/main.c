#include <stdio.h>
#include <string.h>
#include "list.h"
#include "word.h"

int main()
{
    int num;
    char c,Eword[30],Chinese[30];
    WORDNODE* head,*p=NULL;
	head = Create();
	p = head;
	for(num=0;p!=NULL;num++)
    {
        p = p->next;
    }
	printf("this is IDict, please input h for help\n");
	printf("please input your command here\n");
    while(1)
    {   c=getchar();
        while(getchar()!='\n');
		if(c=='H' || c=='h')
		{
			printf("a for add a word\n");
			printf("d for delete a word\n");
			printf("c for change a word\n");
			printf("s for search a word\n");
			printf("q for quit the programme\n");
		}
		else if(c=='Q' || c=='q')
		{
			break;
		}
		else if(c=='A' || c=='a')
		{
			printf("please input word\n");
			scanf("%s",Eword);
			printf("please input Chinese\n");
			scanf("%s",Chinese);
			Add(head,Eword,Chinese);
		}
		else if(c=='C' || c=='c')
		{
		    printf("please input the word you want to change\n");
		    scanf("%s",Eword);
		    Delete(head,Eword);
			printf("please input word\n");
			scanf("%s",Eword);
			printf("please input Chinese\n");
			scanf("%s",Chinese);
			Add(head,Eword,Chinese);
		}
		else if(c=='D' || c=='d')
		{
			printf("please input word\n");
			scanf("%s",Eword);
			Delete(head,Eword);
		}
		else if(c=='S' || c=='s')
		{
			printf("please input search word pattern\n");
			scanf("%s",Eword);
			LookUp(head,Eword);
		}
		else if(c=='W' || c=='w')
        {
            MemWord(head,num);
        }
        else if(c=='R' || c=='r')
        {
            Review();
        }
		else
		{
			printf("error command, please type h for help\n");
		}
	}
	return 0;
}
