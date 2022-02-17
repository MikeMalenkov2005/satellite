%{
#include <stdio.h>
#include <stdlib.h>

extern yylex();
%}

%union {
	int i;
	float f;
}

%token <i> INT;
%token <f> FLOAT;
%token GVAR;
%token LVAR;
%token GFUN;
%token LFUN;

%%

S : M $
  ;

M : GVAR '=' O
  | LVAR '=' O
  | GFUN O
  | LFUN O
  | M ',' M
  ;

O : '{' M '}'
  | '{' M ',' '}'
  ;

%%

void yyerror(char *msg) {
	fprintf(stderr, "%s\n",msg);
	exit(-1);
}

int main() {
	yyparse();
	return 0;
}
