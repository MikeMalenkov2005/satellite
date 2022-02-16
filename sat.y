%{
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

M : M ','
  | GVAR '=' O ','
  | LVAR '=' O ','
  | GFUN O ','
  | LFUN O ','
  | M M
  ;

O : '{' M '}'
  | '{' M GVAR '=' O '}'
  | '{' M LVAR '=' O '}'
  | '{' M GFUN O '}'
  | '{' M LFUN O '}'
  ;

%%
