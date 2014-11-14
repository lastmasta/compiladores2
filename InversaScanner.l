%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include "InversaParser.h"
#include "errores.h"
#include <iostream>

using namespace std;

    int inversaparsercolno = 0;
    #define YY_USER_ACTION { inversaparsercolno += inversaparserleng; }
%}




id   			[a-zA-Z]([a-zA-Z|0-9|"_"])*
numero          [0-9]+



%%

"Stack"				{ inversaparserlval.st = strdup(inversaparsertext); return(stack_rsv); }
"Heap"				{inversaparserlval.st = strdup(inversaparsertext); return(heap_rsv);}
"include"			{inversaparserlval.st = strdup(inversaparsertext); return(include_rsv); }
"using"				{inversaparserlval.st = strdup(inversaparsertext); return(using_rsv); }
"int"				{inversaparserlval.st = strdup(inversaparsertext); return(int_rsv); }
"long"				{inversaparserlval.st = strdup(inversaparsertext); return(long_rsv); }
"void"				{inversaparserlval.st = strdup(inversaparsertext); return(void_rsv); }
"goto"				{inversaparserlval.st = strdup(inversaparsertext); return(goto_rsv); }
"if"				{inversaparserlval.st = strdup(inversaparsertext); return(if_rsv); }
"char"				{inversaparserlval.st = strdup(inversaparsertext); return(char_rsv); }
"main"				{inversaparserlval.st = strdup(inversaparsertext); return(main_rsv); }
"<iostream>"		{inversaparserlval.st = strdup(inversaparsertext); return(iostream_rsv); }
"namespace"			{inversaparserlval.st = strdup(inversaparsertext); return(namespace_rsv); }
"std"				{inversaparserlval.st = strdup(inversaparsertext); return(std_rsv); }
"ptr"				{inversaparserlval.st = strdup(inversaparsertext); return(ptr); }
"ptrH"				{inversaparserlval.st = strdup(inversaparsertext); return(ptrH); }
"return"			{inversaparserlval.st = strdup(inversaparsertext); return(return_rsv); }
"cout"				{inversaparserlval.st = strdup(inversaparsertext); return(cout_rsv); }
"endl"				{inversaparserlval.st = strdup(inversaparsertext); return(endl_rsv); }

"#"				{ inversaparserlval.st = strdup(inversaparsertext); return (numeral); }
"=="			{ inversaparserlval.st = strdup(inversaparsertext); return (esIgual); }
"!="			{ inversaparserlval.st = strdup(inversaparsertext); return (noigual); }
">"				{ inversaparserlval.st = strdup(inversaparsertext); return (mayor); }
"<"				{ inversaparserlval.st = strdup(inversaparsertext); return (menor); }
">="			{ inversaparserlval.st = strdup(inversaparsertext); return (mayorigual); }
"<="			{ inversaparserlval.st = strdup(inversaparsertext); return (menorigual); }
"+"				{ inversaparserlval.st = strdup(inversaparsertext); return (mas); }
"-"				{ inversaparserlval.st = strdup(inversaparsertext); return (menos); }
"*"				{ inversaparserlval.st = strdup(inversaparsertext); return (por); }
"/"				{ inversaparserlval.st = strdup(inversaparsertext); return (divOp); }
"^"				{ inversaparserlval.st = strdup(inversaparsertext); return (potencia); }

"["				{ inversaparserlval.st = strdup(inversaparsertext); return (cor_a); }
"]"				{ inversaparserlval.st = strdup(inversaparsertext); return (cor_c); }
"("             { inversaparserlval.st = strdup(inversaparsertext); return (par_a); }
")"             { inversaparserlval.st = strdup(inversaparsertext); return (par_c); }
"{"				{ inversaparserlval.st = strdup(inversaparsertext); return (llave_a); }
"}"				{ inversaparserlval.st = strdup(inversaparsertext); return (llave_c); }
"="             { inversaparserlval.st = strdup(inversaparsertext); return (sig_igual); }
";"             { inversaparserlval.st = strdup(inversaparsertext); return (p_coma); }
":"				{ inversaparserlval.st = strdup(inversaparsertext); return (dos_p); }
","				{ inversaparserlval.st = strdup(inversaparsertext); return (coma); }
"<<"			{ inversaparserlval.st = strdup(inversaparsertext); return (doblemenor); }

{id}         			{ inversaparserlval.st = strdup(inversaparsertext); return (id); }
{numero}                { inversaparserlval.st = strdup(inversaparsertext); return (numero); }



[ \t\r]       { }
\n          {inversaparserlineno++; inversaparsercolno=1;}
 . {
 cout <<"Error léxico: "<< inversaparsertext << " Fila: " << inversaparserlineno << " Columna: " << inversaparsercolno<< endl ; return (ERROR);
 }

%%
