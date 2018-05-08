%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B
%%
input:S'\n' {printf("Succesful Grammar\n");exit(0);}
    S: A S1 B|B
   S1: ;|A S1
%%
int yyerror()
{
  printf("Error");
  exit(0);
}
main()
{
 printf("Enter a String:\n");
 yyparse();
}
