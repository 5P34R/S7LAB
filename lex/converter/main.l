%{
	#include<stdio.h>
	#include<string.h>
	int i;
%}

%%
([a-zA-Z])* {
	char new_string[100];
	for(i=0;i<=yyleng;i++)
	{
		if((yytext[i]=='a')&&(yytext[i+1]=='b')&&(yytext[i+2]=='c'))
		{
			yytext[i]=='A';
			yytext[i+1]=='B';
			yytext[i+2]=='C';
		}
		printf("%c",yytext[i]);
	}
}

.* {ECHO;}
\n {printf("%s",yytext);}
%%

int main()
{
yylex();
}
int yywrap()
{
return 1;
}
