%{
#include<stdio.h>
#include "y.tab.h"
extern yylval;
%}
%%
[\t];
[+|-|*|/|<|>] {printf("Operators is %s\n",yytext); return OP;}
[0-9]+ {yylval=atoi(yytext); printf("number is %d\n",yylval); return DIGIT;}
int|char|bool|void|float|for|do|while|if|else|return {printf("keyword is %s\n",yytext); return KEY;} 
[a-zA-Z0-9]+ { printf("identifiers is %s\n",yytext); return ID;}
.;
%%

