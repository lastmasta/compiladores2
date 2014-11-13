%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include "AssemblerParser.h"
#include "errores.h"
#include <iostream>

using namespace std;

    int assemblerparsercolno = 0;
    #define YY_USER_ACTION { assemblerparsercolno += assemblerparserleng; }
%}




id   			[a-zA-Z]([a-zA-Z|0-9|"_"])*
numero          [0-9]+



%%

"Stack"				{ assemblerparserlval.st = strdup(assemblerparsertext); return(stack_rsv); }
"Heap"				{assemblerparserlval.st = strdup(assemblerparsertext); return(heap_rsv);}
"include"			{assemblerparserlval.st = strdup(assemblerparsertext); return(include_rsv); }
"using"				{assemblerparserlval.st = strdup(assemblerparsertext); return(using_rsv); }
"int"				{assemblerparserlval.st = strdup(assemblerparsertext); return(int_rsv); }
"long"				{assemblerparserlval.st = strdup(assemblerparsertext); return(long_rsv); }
"void"				{assemblerparserlval.st = strdup(assemblerparsertext); return(void_rsv); }
"goto"				{assemblerparserlval.st = strdup(assemblerparsertext); return(goto_rsv); }
"if"				{assemblerparserlval.st = strdup(assemblerparsertext); return(if_rsv); }
"char"				{assemblerparserlval.st = strdup(assemblerparsertext); return(char_rsv); }
"main"				{assemblerparserlval.st = strdup(assemblerparsertext); return(main_rsv); }
"<iostream>"		{assemblerparserlval.st = strdup(assemblerparsertext); return(iostream_rsv); }
"namespace"			{assemblerparserlval.st = strdup(assemblerparsertext); return(namespace_rsv); }
"std"				{assemblerparserlval.st = strdup(assemblerparsertext); return(std_rsv); }
"ptr"				{assemblerparserlval.st = strdup(assemblerparsertext); return(ptr); }
"ptrH"				{assemblerparserlval.st = strdup(assemblerparsertext); return(ptrH); }
"return"			{assemblerparserlval.st = strdup(assemblerparsertext); return(return_rsv); }
"cout"				{assemblerparserlval.st = strdup(assemblerparsertext); return(cout_rsv); }
"endl"				{assemblerparserlval.st = strdup(assemblerparsertext); return(endl_rsv); }

"#"				{ assemblerparserlval.st = strdup(assemblerparsertext); return (numeral); }
"=="			{ assemblerparserlval.st = strdup(assemblerparsertext); return (esIgual); }
"!="			{ assemblerparserlval.st = strdup(assemblerparsertext); return (noigual); }
">"				{ assemblerparserlval.st = strdup(assemblerparsertext); return (mayor); }
"<"				{ assemblerparserlval.st = strdup(assemblerparsertext); return (menor); }
">="			{ assemblerparserlval.st = strdup(assemblerparsertext); return (mayorigual); }
"<="			{ assemblerparserlval.st = strdup(assemblerparsertext); return (menorigual); }
"+"				{ assemblerparserlval.st = strdup(assemblerparsertext); return (mas); }
"-"				{ assemblerparserlval.st = strdup(assemblerparsertext); return (menos); }
"*"				{ assemblerparserlval.st = strdup(assemblerparsertext); return (por); }
"/"				{ assemblerparserlval.st = strdup(assemblerparsertext); return (divOp); }
"^"				{ assemblerparserlval.st = strdup(assemblerparsertext); return (potencia); }

"["				{ assemblerparserlval.st = strdup(assemblerparsertext); return (cor_a); }
"]"				{ assemblerparserlval.st = strdup(assemblerparsertext); return (cor_c); }
"("             { assemblerparserlval.st = strdup(assemblerparsertext); return (par_a); }
")"             { assemblerparserlval.st = strdup(assemblerparsertext); return (par_c); }
"{"				{ assemblerparserlval.st = strdup(assemblerparsertext); return (llave_a); }
"}"				{ assemblerparserlval.st = strdup(assemblerparsertext); return (llave_c); }
"="             { assemblerparserlval.st = strdup(assemblerparsertext); return (sig_igual); }
";"             { assemblerparserlval.st = strdup(assemblerparsertext); return (p_coma); }
":"				{ assemblerparserlval.st = strdup(assemblerparsertext); return (dos_p); }
","				{ assemblerparserlval.st = strdup(assemblerparsertext); return (coma); }
"<<"			{ assemblerparserlval.st = strdup(assemblerparsertext); return (doblemenor); }

{id}         			{ assemblerparserlval.st = strdup(assemblerparsertext); return (id); }
{numero}                { assemblerparserlval.st = strdup(assemblerparsertext); return (numero); }



[ \t\r]       { }
\n          {assemblerparserlineno++; assemblerparsercolno=1;}
 . {
 cout <<"Error léxico: "<< assemblerparsertext << " Fila: " << assemblerparserlineno << " Columna: " << assemblerparsercolno<< endl ; return (ERROR);
 }

%%
