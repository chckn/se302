/* The first try of yacc to impl MyLang */
%{
#include<stdio.h>
#include<string.h>
#include "mylang.h"
#include "mylang.tab.h"
#define new(T) ((T*)malloc(sizeof(T)))
	int yylex();
	void yyerror(char const *);
/*
	typedef struct Node Node;
	struct Node
	{
		int type;//0,1,2
		char *str;
		int integer;
		char *name;
		Node *first,*last;
		Node *next;
	};
*/
	void push(Node *ptr, Node *child);
	Node * nodes(const char* str,const char* name);
	Node * nodei(int i,const char* name);
	Node * noden(const char* name);
	static Node *head;
%}
%union
{
	char* str;
	int integer;
	struct Node *node;
}
%token <str> IDENT
%token <integer> NUM
%verbose
%error-verbose
%token PROGRAM IS BEGINS END TYPE ARRAY OF CLASS  EXTENDS FUNCTION  RETURN ASSIGN PRINT FOREACH IN DO REPEAT UNTIL WHILE IF THEN ELSE ELIF OR AND EQUAL LEQA SEQA YES NO VAR INTEGER BOOLEAN
%type <node> program exp index var nevar boolean variables type argument retype sentence funcheader methods nevalues values fname fcall final primary term coperator declarblock block arguments if elif elifs else while repeat foreach print assignment return function class array bterm bexpressions bprimary declar 
%left '+' '-'
%left '*' '/' '%'
%%
program:	PROGRAM IDENT '(' ')' declarblock IS arguments BEGINS block END {
				$$=noden("program");
				head=$$;	
				push($$,noden("PROGRAM"));
				push($$,nodes($2,"IDENT"));
				push($$,$5);
				push($$,noden("IS"));
				push($$,$7);
				push($$,noden("BEGIN"));
				push($$,$9);
				push($$,noden("END"));}
;
boolean:	YES {$$=noden("boolean");push($$,nodei(1,"BOOL"));}
			| NO {$$=noden("boolean");push($$,nodei(0,"BOOL"));}
;
exp:		final {$$=noden("exp");push($$,$1);}
			| boolean {$$=noden("exp");push($$,$1);}
/*		| fcall {$$=noden("exp");push($$,$1);}*/
;

index:		'[' final ']' {$$=noden("index");push($$,$2);} 

;
var:		IDENT {$$=noden("var");push($$,nodes($1,"IDENT"));}
			| var '.' IDENT {$$=noden("var");push($$,$1);push($$,nodes(".","DOT"));
							push($$,nodes($3,"IDENT"));}
			| var index {$$=noden("var");push($$,$1);push($$,$2);}
;
nevar:		var {$$=noden("nevar");push($$,$1);}
			| var ',' nevar {
								$$=noden("nevar");
								push($$,$1);
								push($$,nodes(",","DOT"));
								push($$,$3);
							}
;
variables:	/*empty*/	{$$=noden("variables");push($$,nodes("","EMPTY"));}
			| nevar {$$=noden("variables");push($$,$1);}
;
type:		INTEGER {$$=noden("type");push($$,noden("INTEGER"));}
			| BOOLEAN {$$=noden("type");push($$,noden("BOOLEAN"));}
			| IDENT {$$=noden("type");push($$,nodes($1,"IDENT")); }
;
argument:	VAR IDENT IS type ';' {
				$$=noden("argument");
				push($$,noden("VAR"));
				push($$,nodes($2,"IDENT"));
				push($$,noden("IS"));
				push($$,$4);}
;
retype:		/*empty*/ {$$=noden("retype");push($$,nodes("","EMPTY"));}
			| RETURN type ';' {
				$$=noden("retype");
				push($$,noden("RETURN"));
				push($$,$2);
				}
;
arguments:  /*empty*/ {$$=noden("arguments");push($$,nodes("","EMPTY"));}	
			| argument arguments {
				$$=noden("arguments");
				push($$,$1);
				push($$,$2);}
;
funcheader:	arguments retype {$$=noden("funcheader");push($$,$1);push($$,$2);}
;
methods:	/*empty*/ {$$=noden("methods");push($$,nodes("","EMPTY"));}
			| function methods {$$=noden("methods");push($$,$1);push($$,$2);}
;
nevalues:	exp {$$=noden("nevalues");push($$,$1);}
			| exp ',' nevalues {
				$$=noden("nevalues");
				push($$,$1);
				push($$,nodes(",","DOT"));
				push($$,$3);}
;
values:		/*empty*/ {$$=noden("values");push($$,nodes("","EMPTY"));}
			| nevalues {$$=noden("values");push($$,$1);}
;
fname:		IDENT {$$=noden("fname");push($$,nodes($1,"IDENT"));}
			| var '.' IDENT {
				$$=noden("fname");
				push($$,$1);
				push($$,nodes(".","DOT"));
				push($$,nodes($3,"IDENT"));
			}
;
fcall:		fname '(' values ')' {$$=noden("fcall");push($$,$1);
			/*	push($$,noden("("));*/push($$,$3);/*push($$,noden(")"));*/}
;
primary:	NUM {$$=noden("primary");push($$,nodei($1,"NUM"));}
			| var {$$=noden("primary");push($$,$1);}
			| fcall  {$$=noden("primary");push($$,$1);} 
			| '(' exp ')' {$$=noden("primary");/*push($$,noden("("));*/
				push($$,$2);/*push($$,noden(")"));*/}
;
term:		primary  {$$=noden("term");push($$,$1);}
			| term '*' primary  {$$=noden("term");
				push($$,$1);push($$,nodes("*","OP"));push($$,$3);}
			| term '/' primary   {$$=noden("term");
				push($$,$1);push($$,nodes("/","OP"));push($$,$3);}
			| term '%' primary   {$$=noden("term");	
				push($$,$1);push($$,nodes("%","OP"));push($$,$3);}
;
final:		final '+' term {$$=noden("final");
				push($$,$1);push($$,nodes("+","OP"));push($$,$3);}
			| final '-' term {$$=noden("final");
				push($$,$1);push($$,nodes("-","OP"));push($$,$3);}
			| term {$$=noden("final");push($$,$1);} 
;
coperator: 	EQUAL {$$=noden("compare_op");push($$,nodes("==","COP"));}
			| '<' {$$=noden("compare_op");push($$,nodes("less","COP"));}
			| '>' {$$=noden("compare_op");push($$,nodes("large","COP"));}
			| SEQA {$$=noden("compare_op");push($$,nodes("large_equal","COP"));}
			| LEQA {$$=noden("compare_op");push($$,nodes("less_equal","COP"));}
;
bprimary:	exp {$$=noden("bprimary");push($$,$1);}
			| exp coperator exp  {$$=noden("bprimary");push($$,$1); 
				push($$,$2);push($$,$3);}
;
bterm:		bprimary  {$$=noden("bterm");push($$,$1);}
			| bprimary AND bterm  {$$=noden("bterm");
				push($$,$1);push($$,noden("AND"));push($$,$3);}
;
bexpressions:	bterm  {$$=noden("bexpressions");push($$,$1);}
				| bterm OR bexpressions {$$=noden("bexpressions");
				push($$,$1);push($$,noden("OR"));push($$,$3);}
;
elif:		ELIF bexpressions THEN block{
				$$=noden("elif");push($$,noden("ELIF"));push($$,$2);
				push($$,noden("THEN"));}
;
elifs:		/*empty*/  {$$=noden("elifs");push($$,nodes("","EMPTY"));}
			| elif elifs {$$=noden("eifs");push($$,$1);push($$,$2);}
;
else:		/*empty*/ {$$=noden("else");push($$,nodes("","EMPTY"));}
			| ELSE block {$$=noden("else");
				push($$,noden("ELSE"));push($$,$2);}
;
if:			IF bexpressions THEN block elifs else END IF {$$=noden("if");
				push($$,noden("IF"));push($$,$2);push($$,noden("THEN"));
				push($$,$4);push($$,$5);push($$,$6);push($$,noden("END_IF"));}
;
while:		WHILE bexpressions DO block END WHILE {$$=noden("while");
				push($$,noden("WHILE"));push($$,$2);push($$,noden("DO"));
				push($$,$4);push($$,noden("END_WHILE"));}
;
repeat:		REPEAT block UNTIL bexpressions ';' {$$=noden("repeat");
				push($$,noden("REPEAT"));push($$,$2);
				push($$,noden("UNTIL"));push($$,$4);}
;
foreach:	FOREACH IDENT IN var DO block END FOREACH {$$=noden("foreach");
				push($$,noden("FOREACH"));push($$,nodes($2,"IDENT"));
				push($$,noden("IN"));push($$,$4);push($$,noden("DO"));
				push($$,$6);push($$,noden("END_FOREACH"));}
;
print:		PRINT exp ';' {$$=noden("print");push($$,noden("PRINT"));
				push($$,$2);}
;
assignment:		var ASSIGN exp ';' {$$=noden("assignment");push($$,$1);
					push($$,nodes(":=","ASSIGN"));push($$,$3);}
;
return:		RETURN exp ';' {$$=noden("return");push($$,noden("RETURN"));
				push($$,$2);}
			| RETURN ';' {$$=noden("return");push($$,nodes("","EMPTY"));}
;
function:	FUNCTION IDENT '(' variables ')' funcheader IS arguments BEGINS block END FUNCTION IDENT ';' {
				$$=noden("function");
				push($$,noden("FUNCTION"));
				push($$,nodes($2,"IDENT"));
				push($$,$4);
				push($$,$6);
				push($$,noden("IS"));
				push($$,$8);
				push($$,noden("BEGIN"));
				push($$,$10);
				push($$,noden("END_FUNCTION"));
				push($$,nodes($13,"IDENT"));
			}
;
class:		TYPE IDENT IS CLASS arguments methods END CLASS ';' {
				$$=noden("class");
				push($$,noden("TYPE"));
				push($$,nodes($2,"IDENT"));
				push($$,noden("IS_CLASS"));
				push($$,$5);push($$,$6);push($$,noden("END_CLASS"));}
			| TYPE IDENT IS CLASS EXTENDS IDENT arguments methods END CLASS ';'
				{
				$$=noden("class");
				push($$,noden("TYPE"));
				push($$,nodes($2,"IDENT"));
				push($$,noden("IS_CLASS_EXTENDS"));
				push($$,nodes($6,"IDENT"));
				push($$,$7);push($$,$8);push($$,noden("END_CLASS"));}
;
array:		TYPE IDENT IS ARRAY OF NUM type ';' {$$=noden("array");
				push($$,noden("TYPE"));
				push($$,nodes($2,"IDENT"));
				push($$,noden("IS_ARRAY_OF"));
				push($$,nodei($6,"NUM"));
				push($$,$7);}
;
declar:		function {$$=noden("declar");push($$,$1);}
			| class  {$$=noden("declar");push($$,$1);}
			| array {$$=noden("declar");push($$,$1);}
			/*			| sentence {$$=noden("declar");push($$,$1);}*/
;
sentence:	if {$$=noden("sentence");push($$,$1);} 
			| while {$$=noden("sentence");push($$,$1);}
			| repeat {$$=noden("sentence");push($$,$1);}
			| foreach {$$=noden("sentence");push($$,$1);}
			| return {$$=noden("sentence");push($$,$1);}
			| assignment {$$=noden("sentence");push($$,$1);}
			| fcall ';' {$$=noden("sentence");push($$,$1);}
			| print {$$=noden("sentence");push($$,$1);}
;
declarblock:  /*empty*/ {$$=noden("declarblock");push($$,nodes("","EMPTY"));}
			| declar declarblock  {$$=noden("declarblock");push($$,$1);push($$,$2);}
;
block:		 sentence {$$=noden("block");push($$,$1);}
			| sentence block {$$=noden("block");push($$,$1);push($$,$2);}
;
%%

void yyerror (char const *s)
{
	      printf ("%s\n", s);
}
void push(Node * ptr,Node * child)
{
	if(ptr->first==NULL)
		ptr->first=ptr->last=child;
	else
	{
		ptr->last->next=child;
		ptr->last=child;
	}	
	
}
Node* nodes(const char *str,const char* name)
{
	Node* nd=new(Node);
	nd->type=1;
	nd->name=(char*)malloc(strlen(name));
	strcpy(nd->name,name);
	nd->str=(char*)malloc(strlen(str));
	strcpy(nd->str,str);
	nd->first=nd->last=nd->next=NULL;
	return nd;	
}
Node *nodei(int i,const char* name)
{

	Node* nd=new(Node);
	nd->type=2;
	nd->name=(char*)malloc(strlen(name));
	strcpy(nd->name,name);
	nd->integer=i;
	nd->first=nd->last=nd->next=NULL;
	return nd;	
}
Node *noden(const char *name)
{
	
	Node* nd=new(Node);
	nd->type=0;
	nd->name=(char*)malloc(strlen(name));
	strcpy(nd->name,name);
	nd->first=nd->last=nd->next=NULL;
	return nd;	
}
void print(Node* node,int tab)
{
	int i;
	Node* ptr;
	for(i=0;i<=tab;i++)
		printf(" ");
	printf("<%s>\n",node->name);
	if(node->type!=0)
	{
		for(i=0;i<=tab+1;i++)
			printf(" ");
		if(node->type==1)
			printf("%s\n",node->str);
		else
			printf("%d\n",node->integer);
		
	}
	for(ptr=node->first;ptr!=NULL;ptr=ptr->next)
	{
		print(ptr,tab+1);
	}
	for(i=0;i<=tab;i++)
		printf(" ");
	printf("</%s>\n",node->name);
}
void lexical()
{

	int token;
	while((token=yylex())>1)
	{
		switch(token)
		{
#define GOT_TOKEN(TAT) case TAT: printf(#TAT " "); break
  GOT_TOKEN(IDENT); GOT_TOKEN(NUM); GOT_TOKEN(PROGRAM); GOT_TOKEN(IS);
  GOT_TOKEN(BEGINS); GOT_TOKEN(END); GOT_TOKEN(TYPE); GOT_TOKEN(ARRAY); GOT_TOKEN(OF); GOT_TOKEN(CLASS); GOT_TOKEN(EXTENDS); GOT_TOKEN(FUNCTION);
  GOT_TOKEN(RETURN); GOT_TOKEN(ASSIGN); GOT_TOKEN(PRINT); GOT_TOKEN(FOREACH); GOT_TOKEN(IN); GOT_TOKEN(DO); GOT_TOKEN(REPEAT); GOT_TOKEN(UNTIL);
  GOT_TOKEN(WHILE); GOT_TOKEN(IF); GOT_TOKEN(THEN); GOT_TOKEN(ELSE); GOT_TOKEN(ELIF); GOT_TOKEN(OR); GOT_TOKEN(AND); GOT_TOKEN(EQUAL); GOT_TOKEN(LEQA);
  GOT_TOKEN(SEQA); GOT_TOKEN(YES); GOT_TOKEN(NO); GOT_TOKEN(VAR); GOT_TOKEN(INTEGER); GOT_TOKEN(BOOLEAN); 
			default:
printf("%c ", token);  
		}
	}
	if(token==1)
		printf("ERROR: Unexpected %s\n",yylval);
}
Node* syntax(int p)
{
//	yydebug=1;
				yyparse();
		
//	printf("%s\n","<?xml   version=\"1.0\"   encoding=\"utf-8\"?>");       	
				if(head!=NULL && p)
					print(head,0);
		if(head==NULL)
			return 0;
		else
			return head;
}
