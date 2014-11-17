/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_MAINPARSER_MAINPARSER_H_INCLUDED
# define YY_MAINPARSER_MAINPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int mainparserdebug;
#endif
/* "%code requires" blocks.  */
#line 55 "MainParser.y" /* yacc.c:1909  */

   #include "nodo.h"

#line 48 "MainParser.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ERROR = 258,
    par_a = 259,
    par_c = 260,
    llave_a = 261,
    llave_c = 262,
    sig_igual = 263,
    p_coma = 264,
    dos_p = 265,
    punto = 266,
    comillas = 267,
    coma = 268,
    id = 269,
    numero = 270,
    string_token = 271,
    caracter_token = 272,
    clase_rsv = 273,
    extiende_rsv = 274,
    paratodos_rsv = 275,
    protegido_rsv = 276,
    privado_rsv = 277,
    dolar = 278,
    traer_rsv = 279,
    decattr_rsv = 280,
    entero_rsv = 281,
    bool_rsv = 282,
    caracter_rsv = 283,
    cadena_rsv = 284,
    def_rsv = 285,
    ninguno_rsv = 286,
    retornar_rsv = 287,
    ref_rsv = 288,
    si_cumple_rsv = 289,
    sino_intente = 290,
    sino_cumple_rsv = 291,
    repetir_mientras_rsv = 292,
    detener_rsv = 293,
    decarr_rsv = 294,
    true_rsv = 295,
    false_rsv = 296,
    imprimir_rsv = 297,
    instanciar_rsv = 298,
    este_rsv = 299,
    esigual = 300,
    noigual = 301,
    mayor = 302,
    menor = 303,
    mayorigual = 304,
    menorigual = 305,
    esnulo = 306,
    orOp = 307,
    andOp = 308,
    notOp = 309,
    mas = 310,
    menos = 311,
    por = 312,
    divOp = 313,
    potencia = 314,
    numeralnumeral = 315,
    masmas = 316,
    menosmenos = 317,
    porpor = 318
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 59 "MainParser.y" /* yacc.c:1909  */

char *st;
Nodo *nodo;

#line 129 "MainParser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE mainparserlval;

int mainparserparse (void);

#endif /* !YY_MAINPARSER_MAINPARSER_H_INCLUDED  */
