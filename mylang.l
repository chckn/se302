%{
	#include<stdlib.h>
	#include<string.h>
	#include<malloc.h>
	#include "mylang.tab.h"
	/*yytext is char*,yylval is typeof(RETURN TYPE)*/
%}

%%
\/\/.*
program {
	return PROGRAM;
}
begin {
	return BEGINS;
}
end {
	return END;
}
type {
	return TYPE;
}
is {
	return IS;
}
array {
	return ARRAY;
}
of {
	return OF;
}
class {
	return CLASS;
}
extends {
	return EXTENDS;
}
function {
	return FUNCTION;
} 
return {
	return RETURN;
}
:= {
	return ASSIGN;
}
print {
	return PRINT;
}
foreach {
	return FOREACH;
}
in {
	return IN;
}
do {
	return DO;
}
repeat {
	return REPEAT;
}
until {
	return UNTIL;
}
while {
	return WHILE;
}
if {
	return IF;
}
then {
	return THEN;
}
else {
	return ELSE;
}
elif {
	return ELIF;
}
or {
	return OR;
}
and {
	return AND;
}
== {
	return EQUAL;
}
>= {
	return LEQA;
}
\<\= {
	return SEQA;
}
yes {
	return YES;
}
no {
	return NO;
}
var {
	return VAR;
}
integer {
	return INTEGER;
}
boolean {
	return BOOLEAN;
}
[A-Za-z_][A-Za-z0-9_]* {
		yylval.str=(char*)malloc(strlen(yytext)+1);
		strcpy(yylval.str,yytext);
		return IDENT;
}
[0-9]+ {
	yylval.integer=atoi(yytext);
	return NUM;	
}
[,;+\-*/%.()><\[\]=] {
	return *yytext;
}
\n
[ ]
. {
		yylval.str=(char*)malloc(strlen(yytext)+1);
		strcpy(yylval.str,yytext);
		return 1;
}
%%

int yywrap(void)
{
	return 1;
}
