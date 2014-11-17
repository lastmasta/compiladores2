%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include "MainParser.h"
#include "nodo.h"
#include <iostream>
  #include <fstream>

using namespace std;

    extern ofstream errores;
    int mainparsercolno = 0;
    #define YY_USER_ACTION { mainparsercolno += mainparserleng; }
%}




id   			[a-zA-Z]([a-zA-Z|0-9])*
numero          [0-9]+
comentariomulti [/][*][^*/]*[*][/]
comentario      [/][/][^\n]*
string_token	\"(\\.|[^\\"])*\"
caracter_token  '([^'\\\n]|\\.)'



%%

"traer"				{ mainparserlval.st = strdup(mainparsertext); return(traer_rsv); }
"clase"    			{ mainparserlval.st = strdup(mainparsertext); return(clase_rsv); }
"extiende"    		{ mainparserlval.st = strdup(mainparsertext); return(extiende_rsv); }
"para_todos"    	{ mainparserlval.st = strdup(mainparsertext); return(paratodos_rsv); }
"protegido"    		{ mainparserlval.st = strdup(mainparsertext); return(protegido_rsv); }
"privado"    		{ mainparserlval.st = strdup(mainparsertext); return(privado_rsv); }
"decattr"			{ mainparserlval.st = strdup(mainparsertext); return(decattr_rsv); }
"entero"			{ mainparserlval.st = strdup(mainparsertext); return(entero_rsv); }
"bool"				{ mainparserlval.st = strdup(mainparsertext); return(bool_rsv); }
"caracter"			{ mainparserlval.st = strdup(mainparsertext); return(caracter_rsv); }
"cadena"			{ mainparserlval.st = strdup(mainparsertext); return(cadena_rsv); }
"ninguno"			{ mainparserlval.st = strdup(mainparsertext); return(ninguno_rsv); }
"def"				{ mainparserlval.st = strdup(mainparsertext); return(def_rsv); }
"retornar"			{ mainparserlval.st = strdup(mainparsertext); return(retornar_rsv); }
"ref"				{ mainparserlval.st = strdup(mainparsertext); return (ref_rsv); }
"si_cumple"			{ mainparserlval.st = strdup(mainparsertext); return (si_cumple_rsv); }
"sino_intente"		{ mainparserlval.st = strdup(mainparsertext); return (sino_intente); }
"sino_cumple"		{ mainparserlval.st = strdup(mainparsertext); return (sino_cumple_rsv); }
"repetir_mientras"  { mainparserlval.st = strdup(mainparsertext); return (repetir_mientras_rsv); }
"detener"			{ mainparserlval.st = strdup(mainparsertext); return (detener_rsv); }
"decarr"			{ mainparserlval.st = strdup(mainparsertext); return (decarr_rsv); }
"true"				{ mainparserlval.st = strdup(mainparsertext); return (true_rsv); }
"false"				{ mainparserlval.st = strdup(mainparsertext); return (false_rsv); }
"imprimir"			{ mainparserlval.st = strdup(mainparsertext); return (imprimir_rsv); }
"instanciar"		{ mainparserlval.st = strdup(mainparsertext); return (instanciar_rsv); }
"este"				{ mainparserlval.st = strdup(mainparsertext); return (este_rsv); }


"=="			{ mainparserlval.st = strdup(mainparsertext); return (esigual); }
"!="			{ mainparserlval.st = strdup(mainparsertext); return (noigual); }
">"				{ mainparserlval.st = strdup(mainparsertext); return (mayor); }
"<"				{ mainparserlval.st = strdup(mainparsertext); return (menor); }
">="			{ mainparserlval.st = strdup(mainparsertext); return (mayorigual); }
"<="			{ mainparserlval.st = strdup(mainparsertext); return (menorigual); }
"!¡"			{ mainparserlval.st = strdup(mainparsertext); return (esnulo); }
"||"			{ mainparserlval.st = strdup(mainparsertext); return (orOp); }
"&&"			{ mainparserlval.st = strdup(mainparsertext); return (andOp); }
"!"				{ mainparserlval.st = strdup(mainparsertext); return (notOp); }
"+"				{ mainparserlval.st = strdup(mainparsertext); return (mas); }
"-"				{ mainparserlval.st = strdup(mainparsertext); return (menos); }
"*"				{ mainparserlval.st = strdup(mainparsertext); return (por); }
"/"				{ mainparserlval.st = strdup(mainparsertext); return (divOp); }
"^"				{ mainparserlval.st = strdup(mainparsertext); return (potencia); }

"##"			{ mainparserlval.st = strdup(mainparsertext); return (numeralnumeral); }
"++"			{ mainparserlval.st = strdup(mainparsertext); return (masmas); }
"--"			{ mainparserlval.st = strdup(mainparsertext); return (menosmenos); }
"**"			{ mainparserlval.st = strdup(mainparsertext); return (porpor); }


"("             { mainparserlval.st = strdup(mainparsertext); return (par_a); }
")"             { mainparserlval.st = strdup(mainparsertext); return (par_c); }
"{"             { mainparserlval.st = strdup(mainparsertext); return (llave_a); }
"}"             { mainparserlval.st = strdup(mainparsertext); return (llave_c); }
","             { mainparserlval.st = strdup(mainparsertext); return (coma); }
"="             { mainparserlval.st = strdup(mainparsertext); return (sig_igual); }
";"             { mainparserlval.st = strdup(mainparsertext); return (p_coma); }
":"             { mainparserlval.st = strdup(mainparsertext); return (dos_p); }
"$$"			{ mainparserlval.st = strdup(mainparsertext); return (dolar); }
"\""			{ mainparserlval.st = strdup(mainparsertext); return (comillas); }
"."				{ mainparserlval.st = strdup(mainparsertext); return (punto); }


{id}         			{ mainparserlval.st = strdup(mainparsertext); return (id); }
{numero}                { mainparserlval.st = strdup(mainparsertext); return (numero); }
{string_token}			{ mainparserlval.st = strtok(mainparsertext, "\""); return(string_token); }
{caracter_token}		{ mainparserlval.st = strdup(mainparsertext); return(caracter_token); }
{comentariomulti}       { }
{comentario}            { }



[ \t\r]       { }
\n          {mainparserlineno++; mainparsercolno=0;}
 . {
 errores.open("errores.txt");
 errores <<"Error léxico: "<< mainparsertext << " Fila: " << mainparserlineno << " Columna: " << mainparsercolno<< endl ; return (ERROR);
 errores.close();
 }

%%
