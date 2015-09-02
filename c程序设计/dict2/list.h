#ifndef _LIST_H
#define _LIST_H

#include "word.h"
#include "tool.h"

int RegSearch(char reg[], char target[]);
WORDNODE* Create();
void LookUp(WORDNODE *head, char re[]);
void DispList(WORDNODE *head);
void Add(WORDNODE* head,char Eword[],char Chinese[]);
void Delete(WORDNODE *head, char re[]);
int MemWord(WORDNODE * head,int num);
int Review();

#endif
