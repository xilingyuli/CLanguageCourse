#ifndef _WORD_H
#define _WORD_H

typedef struct wordnode
{
    char Eword[30];
    char Chinese[100];
    struct wordnode *next;
} WORDNODE;

#endif
