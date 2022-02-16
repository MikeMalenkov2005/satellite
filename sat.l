%{
#include "y.tab.h"
%}

%%

\n		{return ',';}
[+-*/(),{}\[\]]	{return yytext[0];}
[ \t\v\f]	{;}

%%
