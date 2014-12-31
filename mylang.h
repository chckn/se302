#ifndef MYLANG_H
#define MYLANG_H

void lexical();
typedef struct Node Node;
struct Node
{
	int type;//0:non,1:str,2:int
	char *str;
	int integer;
	char *name;
	Node *first,*last;
	Node *next;
};
Node* syntax(int);
#endif
