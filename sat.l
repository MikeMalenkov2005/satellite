%{
#include "y.tab.h"
%}

%%

"if"		return IF;
"else"		return ELSE;
"for"		return FOR;
"while"		return WHILE;

\".*\"		{
		return STRING;
		}

\.[a-z_A-Z]+	{
		return LOCAL;
		}

[a-z_A-Z]+	{
		return GLOBAL;
		}

[+-/*=(){}\[\]]	return *yytext;
[ \t\v\f]	;

%%

int yywrap()  {
	return 1;
}
