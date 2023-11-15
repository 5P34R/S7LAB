%{
#include<stdio.h>
%}

%%
[a-c] printf("%c",yytext[0] - ('a' - 'A'));
[a-z] printf("%c", yytext[0]);
0 { return 0;}
%%

int main()
{
 yylex();
 return 0;
}