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

#ifndef YY_INVERSAPARSER_INVERSAPARSER_H_INCLUDED
# define YY_INVERSAPARSER_INVERSAPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int inversaparserdebug;
#endif
/* "%code requires" blocks.  */
#line 36 "InversaParser.y" /* yacc.c:1909  */

   #include "nodo.h"

#line 48 "InversaParser.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ERROR = 258,
    stack_rsv = 259,
    heap_rsv = 260,
    include_rsv = 261,
    using_rsv = 262,
    int_rsv = 263,
    long_rsv = 264,
    void_rsv = 265,
    goto_rsv = 266,
    if_rsv = 267,
    char_rsv = 268,
    main_rsv = 269,
    iostream_rsv = 270,
    namespace_rsv = 271,
    std_rsv = 272,
    ptr = 273,
    ptrH = 274,
    return_rsv = 275,
    cout_rsv = 276,
    endl_rsv = 277,
    esIgual = 278,
    noigual = 279,
    mayor = 280,
    menor = 281,
    mayorigual = 282,
    menorigual = 283,
    mas = 284,
    menos = 285,
    por = 286,
    divOp = 287,
    potencia = 288,
    numeral = 289,
    cor_a = 290,
    cor_c = 291,
    par_a = 292,
    par_c = 293,
    llave_a = 294,
    llave_c = 295,
    sig_igual = 296,
    p_coma = 297,
    coma = 298,
    dos_p = 299,
    doblemenor = 300,
    id = 301,
    numero = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 40 "InversaParser.y" /* yacc.c:1909  */

char *st;
Nodo *nodo;

#line 113 "InversaParser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE inversaparserlval;

int inversaparserparse (void);

#endif /* !YY_INVERSAPARSER_INVERSAPARSER_H_INCLUDED  */
