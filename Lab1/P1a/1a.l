%{
#include<stdio.h>
int v=0,op=0,id=0,flag=0;
%}
%%
[a-zA-Z]+[0-9A-Za-z]* {id++;printf("\n identifier:");ECHO;}
[\+\-\*\/\=] {op++;printf("\n operator");ECHO;} 
"(" {v++;}
")" {v--;}
";" {flag=1;}
.|\n {;}
%%
int yywrap()
{
return 1;
}
int main()
{
printf("enter the expression");
yylex();
if((op+1)==id && v==0 && flag==0)
{
printf("\n the expression is valid\n");
printf("\n identifier count=%d",id);
printf("\n operator count=%d",op);
}
else
printf("\n the expression not is valid\n");
}

