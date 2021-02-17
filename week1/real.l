%{
#include <stdio.h>	
int realnum = 0;
%}
digit [0-9]
%%
{digit}*(\.{digit}+)? {realnum++;
	printf("[realnum: %s %f]", yytext, atof(yytext));}
%%
int main(){
	yylex();
	printf("Number of real numbers: %d\n", realnum);
	return 0;
}

    © 2021 GitHub, Inc.
    Terms
    Privacy
    S
