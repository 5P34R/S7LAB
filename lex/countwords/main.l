%{ 
#include<stdio.h> 
#include<string.h> 
int i = 0; 
%} 
  
/* Rules Section*/
%% 
([a-zA-Z0-9])*    {i++;} 
                          
"\n" {printf("count : %d\n", i); i = 0;} 
%% 
  
int yywrap(void){} 
  
int main() 
{     
    yylex(); 
  
    return 0; 
} 