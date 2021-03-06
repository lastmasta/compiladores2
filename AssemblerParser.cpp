/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         assemblerparserparse
#define yylex           assemblerparserlex
#define yyerror         assemblerparsererror
#define yydebug         assemblerparserdebug
#define yynerrs         assemblerparsernerrs

#define yylval          assemblerparserlval
#define yychar          assemblerparserchar

/* Copy the first part of user declarations.  */
#line 1 "AssemblerParser.y" /* yacc.c:339  */


  #include "AssemblerScanner.h"
  #include <fstream>
  #include <stdio.h>
  #include <stdlib.h>
  #include <iostream>
  #include <QString>
  using namespace std;

  extern int assemblerparserlex(void);
  extern char *assemblerparsertext;
  extern int assemblerparserlineno;
  extern int assemblerparsercolno;
  extern FILE *Mainin;
  ofstream salidanasm;
  void assemblerparsererror(char*s);


void assemblerparsererror(const char *s) {
cout << "Error SINTACTICO en la fila: " << assemblerparserlineno << " y columna: " << assemblerparsercolno<< ": "<<assemblerparsertext << endl;
}

void Iniciar(){
  salidanasm.open("assembler.asm");
}



#line 104 "AssemblerParser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "AssemblerParser.h".  */
#ifndef YY_ASSEMBLERPARSER_ASSEMBLERPARSER_H_INCLUDED
# define YY_ASSEMBLERPARSER_ASSEMBLERPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int assemblerparserdebug;
#endif
/* "%code requires" blocks.  */
#line 31 "AssemblerParser.y" /* yacc.c:355  */

   #include "nodo.h"

#line 138 "AssemblerParser.cpp" /* yacc.c:355  */

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
#line 35 "AssemblerParser.y" /* yacc.c:355  */

char *st;
Nodo *nodo;

#line 203 "AssemblerParser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE assemblerparserlval;

int assemblerparserparse (void);

#endif /* !YY_ASSEMBLERPARSER_ASSEMBLERPARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 218 "AssemblerParser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   138,   138,   138,   140,   141,   143,   144,   145,   146,
     147,   148,   150,   152,   153,   156,   157,   157,   159,   160,
     160,   169,   169,   176,   177,   181,   186,   190,   191,   193,
     194,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   216,   224,
     232,   238,   243,   249,   251,   253,   273,   279,   285,   291,
     293,   296,   309,   323,   323,   323,   323,   325,   327,   329,
     329,   329,   329,   329,   329,   331,   337,   338,   339,   347
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ERROR", "stack_rsv", "heap_rsv",
  "include_rsv", "using_rsv", "int_rsv", "long_rsv", "void_rsv",
  "goto_rsv", "if_rsv", "char_rsv", "main_rsv", "iostream_rsv",
  "namespace_rsv", "std_rsv", "ptr", "ptrH", "return_rsv", "cout_rsv",
  "endl_rsv", "esIgual", "noigual", "mayor", "menor", "mayorigual",
  "menorigual", "mas", "menos", "por", "divOp", "potencia", "numeral",
  "cor_a", "cor_c", "par_a", "par_c", "llave_a", "llave_c", "sig_igual",
  "p_coma", "coma", "dos_p", "doblemenor", "id", "numero", "$accept",
  "INICIO", "$@1", "INSTRUCCIONES", "TRESDIRECCIONES", "DECTEMPORALES",
  "TEMPORALES_LIST", "DECMETODOS", "$@2", "DECMETODO", "$@3", "$@4",
  "DECPUNTEROS", "DECSTACK", "DECHEAP", "INCLUDES", "CUERPOMETODO",
  "INSTRUCCIONESMETODO", "OBTENERDESTACK", "OBTENERDEHEAP", "ASIGSTACK",
  "ASIGHEAP", "LABEL", "SALTONOCOND", "SALTOCOND", "CAMBIOVIRTUAL",
  "CAMBIODEAMBITO", "REGRESODEAMBITO", "TEMPASIG", "TEMPOP", "OP",
  "FUNCALL", "RETURN", "OPREL", "AUMENTARHEAP", "IMPRIMIR", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -61

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-61)))

#define YYTABLE_NINF -17

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -61,    39,    -1,   -61,    41,   -14,     8,    40,    15,   -61,
     -61,    55,    55,   -61,   -61,   -61,   -61,    69,    14,    46,
     -61,   -12,    54,    56,    73,   -61,    78,    50,   -61,   -61,
      51,    52,    57,   -61,    59,    60,    61,   -61,    58,    63,
     -61,    64,    67,   -61,    62,    65,    72,    74,   -61,   -61,
      71,    75,    76,     6,   -61,   -61,   -61,   -61,   -61,    48,
      48,    68,    79,    70,    81,    80,    82,    77,    66,   -61,
      10,    -2,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,    16,
      83,    84,    85,    86,   101,   103,    89,     4,    87,    -4,
     -61,   -61,   -61,   -61,    90,    92,   -61,    47,    53,    91,
     -61,   -61,   120,    93,    94,    99,   100,   108,    97,    49,
      98,   102,   104,   -61,   -61,   -61,   -61,   -61,   -61,    95,
     105,   106,   107,   109,   122,   -61,    96,   110,   111,   -61,
     -61,   -61,   -61,   -61,    30,   -61,   113,    38,   112,   115,
     118,   119,   116,   121,   128,   129,   124,   125,   126,   127,
     130,   131,   135,   -61,   -61,   -61,    19,   -61,   132,   133,
     -61,   -61,   -61,   -61,   -61,   -61,   134,   -61,   148,   -61,
     -61,   136,   137,   -61,   -61
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    16,     1,     0,     0,     0,     0,     3,     5,
       8,     7,     0,     9,    10,    11,     6,     0,     0,     0,
      14,     0,     0,     0,     0,     4,     0,     0,    15,    17,
       0,     0,     0,    12,     0,     0,     0,    27,     0,     0,
      28,     0,     0,    13,     0,     0,     0,     0,    23,    24,
       0,     0,     0,     0,    25,    26,    21,    19,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    22,    29,    20,     0,     0,    54,     0,     0,     0,
      68,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    73,    70,    69,    71,    72,     0,
       0,     0,     0,     0,     0,    67,     0,     0,     0,    59,
      63,    64,    65,    66,     0,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,    58,    75,     0,    79,     0,     0,
      56,    61,    62,    50,    51,    52,     0,    76,     0,    48,
      49,     0,     0,    55,    78
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   -61,   -61,   140,   -61,   -61,   -61,   -61,   139,
     -61,   -61,   -61,   -61,   -61,   -61,    37,   -60,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     8,     9,    10,    21,    11,    12,    28,
      60,    59,    13,    14,    15,    16,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
     144,    85,    86,   129,    87,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     115,   116,    61,    62,    18,    19,     4,     5,     6,    63,
      64,   102,    22,    23,   117,   118,    65,    66,    67,    68,
      61,    62,     4,     5,     6,   -16,   111,    63,    64,   102,
      33,    34,    20,     7,    65,    66,    67,    68,   101,     3,
      69,   112,   119,   120,    70,    57,    24,    98,    58,     7,
     113,    99,    61,    62,   100,    31,   103,    17,    69,    63,
      64,   177,    70,    26,   178,    27,    65,    66,    67,    68,
     123,   124,   125,   126,   127,   128,   157,   158,   140,   141,
     142,   143,   130,   131,   160,   161,    30,    32,    37,    35,
      69,    36,    38,    40,    70,    46,    39,    89,    50,    41,
      47,    51,     0,    90,    42,    43,    48,    44,    45,    49,
      52,    97,    53,    54,    91,    56,    92,    55,    93,   108,
     132,    94,   109,    95,    96,   114,   121,   106,   122,   104,
     105,   110,   107,   133,   136,   137,   135,   138,   134,   139,
     145,   148,   154,   146,   153,   147,   176,   152,    25,     0,
     162,    29,   149,   150,   151,     0,   155,   163,   156,   159,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     182,     0,   174,   175,   179,   180,     0,     0,   183,   184,
     181
};

static const yytype_int8 yycheck[] =
{
       4,     5,     4,     5,    18,    19,     7,     8,     9,    11,
      12,    71,     4,     5,    18,    19,    18,    19,    20,    21,
       4,     5,     7,     8,     9,    10,    22,    11,    12,    89,
      42,    43,    46,    34,    18,    19,    20,    21,    40,     0,
      42,    37,    46,    47,    46,    39,     6,    37,    42,    34,
      46,    41,     4,     5,    44,    41,    40,    16,    42,    11,
      12,    42,    46,     8,    45,    10,    18,    19,    20,    21,
      23,    24,    25,    26,    27,    28,    46,    47,    29,    30,
      31,    32,    29,    30,    46,    47,    17,    41,    15,    35,
      42,    35,    14,    42,    46,    37,    46,    60,    36,    47,
      37,    36,    -1,    35,    47,    46,    42,    47,    47,    42,
      38,    45,    38,    42,    35,    39,    46,    42,    37,    18,
      29,    41,    19,    41,    47,    38,    36,    42,    36,    46,
      46,    42,    46,    13,    35,    35,    42,    29,    45,    42,
      42,    46,    46,    41,    22,    41,    11,    38,     8,    -1,
      38,    12,    47,    47,    47,    -1,    46,    42,    47,    46,
      42,    42,    46,    42,    36,    36,    42,    42,    42,    42,
      22,    -1,    42,    42,    42,    42,    -1,    -1,    42,    42,
      46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    50,     0,     7,     8,     9,    34,    51,    52,
      53,    55,    56,    60,    61,    62,    63,    16,    18,    19,
      46,    54,     4,     5,     6,    52,     8,    10,    57,    57,
      17,    41,    41,    42,    43,    35,    35,    15,    14,    46,
      42,    47,    47,    46,    47,    47,    37,    37,    42,    42,
      36,    36,    38,    38,    42,    42,    39,    39,    42,    59,
      58,     4,     5,    11,    12,    18,    19,    20,    21,    42,
      46,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    79,    80,    82,    83,    64,
      35,    35,    46,    37,    41,    41,    47,    45,    37,    41,
      44,    40,    65,    40,    46,    46,    42,    46,    18,    19,
      42,    22,    37,    46,    38,     4,     5,    18,    19,    46,
      47,    36,    36,    23,    24,    25,    26,    27,    28,    81,
      29,    30,    29,    13,    45,    42,    35,    35,    29,    42,
      29,    30,    31,    32,    78,    42,    41,    41,    46,    47,
      47,    47,    38,    22,    46,    46,    47,    46,    47,    46,
      46,    47,    38,    42,    42,    42,    46,    42,    36,    36,
      42,    42,    42,    42,    42,    42,    11,    42,    45,    42,
      42,    46,    22,    42,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    50,    49,    51,    51,    52,    52,    52,    52,
      52,    52,    53,    54,    54,    55,    56,    55,    57,    58,
      57,    59,    57,    60,    60,    61,    62,    63,    63,    64,
      64,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    66,    67,
      68,    69,    69,    70,    71,    72,    73,    74,    75,    76,
      76,    77,    77,    78,    78,    78,    78,    79,    80,    81,
      81,    81,    81,    81,    81,    82,    83,    83,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     2,     0,     2,     5,     0,
       8,     0,     8,     5,     5,     6,     6,     3,     4,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     7,     7,
       7,     7,     7,     2,     3,     9,     6,     6,     6,     4,
       4,     6,     6,     1,     1,     1,     1,     4,     3,     1,
       1,     1,     1,     1,     1,     6,     7,     3,     9,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 138 "AssemblerParser.y" /* yacc.c:1646  */
    {Iniciar();}
#line 1422 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 138 "AssemblerParser.y" /* yacc.c:1646  */
    { cout << "Final de la gramatica" << endl; salidanasm.close(); }
#line 1428 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 152 "AssemblerParser.y" /* yacc.c:1646  */
    { salidanasm << "    " << (yyvsp[0].st) << " : resd 1" << endl; }
#line 1434 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 153 "AssemblerParser.y" /* yacc.c:1646  */
    {  
                              salidanasm << "    " << (yyvsp[0].st) << " : resd 1" << endl; }
#line 1441 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 157 "AssemblerParser.y" /* yacc.c:1646  */
    { salidanasm << "section .text" << endl; salidanasm << "global _start" << endl; salidanasm << "extern printf" << endl; }
#line 1447 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 160 "AssemblerParser.y" /* yacc.c:1646  */
    { salidanasm << (yyvsp[-3].st) << ":" << endl; 
                                                  salidanasm << "    pusha" << endl;
                                                   }
#line 1455 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 164 "AssemblerParser.y" /* yacc.c:1646  */
    {
                                                                        salidanasm << "    popa" << endl;
                                                                        salidanasm << "    ret" << endl;
                                                                      }
#line 1464 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 169 "AssemblerParser.y" /* yacc.c:1646  */
    {salidanasm << "_start:" << endl;}
#line 1470 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 169 "AssemblerParser.y" /* yacc.c:1646  */
    {
                                                                                                                                                  salidanasm << "    exit:" << endl;
                                                                                                                                                  salidanasm << "    mov eax, 1" << endl;
                                                                                                                                                  salidanasm << "    mov ebx, 0" << endl;
                                                                                                                                                  salidanasm << "    int 80h" << endl; 
                                                                                                                                                  }
#line 1481 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 176 "AssemblerParser.y" /* yacc.c:1646  */
    { salidanasm << "section .data" << endl; salidanasm << "    ptr: dw 0" << endl; }
#line 1487 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 177 "AssemblerParser.y" /* yacc.c:1646  */
    {
                                                        salidanasm << "    ptrH: dw 0" << endl;  
                                                      }
#line 1495 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 181 "AssemblerParser.y" /* yacc.c:1646  */
    {
                                                              salidanasm << "section .bss" << endl; 
                                                              salidanasm << "    Stack: resd 10000" << endl;
                                                              }
#line 1504 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 186 "AssemblerParser.y" /* yacc.c:1646  */
    {
                                                              salidanasm << "    Heap: resd 10000" << endl;
                                                            }
#line 1512 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 216 "AssemblerParser.y" /* yacc.c:1646  */
    {
                                                                  salidanasm << "    mov ebx, [Stack]" << endl;
                                                                  salidanasm << "    mov eax, " << (yyvsp[-2].st) << endl;
                                                                  salidanasm << "    mov ecx, [ebx + eax]" << endl;
                                                                  salidanasm << "    mov eax, ecx" << endl;
                                                                  salidanasm << "    mov ["<< (yyvsp[-6].st) << "], eax" << endl;
                                                                  }
#line 1524 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 224 "AssemblerParser.y" /* yacc.c:1646  */
    {
                                                                  salidanasm << "    mov ebx, [Heap]" << endl;
                                                                  salidanasm << "    mov eax, " << (yyvsp[-2].st) << endl;
                                                                  salidanasm << "    mov ecx, [ebx + eax]" << endl;
                                                                  salidanasm << "    mov eax, ecx" << endl;
                                                                  salidanasm << "    mov ["<< (yyvsp[-6].st) << "], eax" << endl;
                                                                  }
#line 1536 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 232 "AssemblerParser.y" /* yacc.c:1646  */
    {
                                                                salidanasm << "    mov ebx, [Stack]" << endl; 
                                                                salidanasm << "    mov eax, " << (yyvsp[-4].st) << endl;
                                                                salidanasm << "    mov ecx, " << (yyvsp[-1].st) << endl;
                                                                salidanasm << "    mov[ebx + eax], ecx" << endl; }
#line 1546 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 238 "AssemblerParser.y" /* yacc.c:1646  */
    {
                                                                salidanasm << "    mov ebx, [Heap]" << endl; 
                                                                salidanasm << "    mov eax, " << (yyvsp[-4].st) << endl;
                                                                salidanasm << "    mov ecx, " << (yyvsp[-1].st) << endl;
                                                                salidanasm << "    mov[ebx + eax], ecx" << endl; }
#line 1556 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 243 "AssemblerParser.y" /* yacc.c:1646  */
    {
                                                                salidanasm << "    mov ebx, [Heap]" << endl; 
                                                                salidanasm << "    mov eax, " << (yyvsp[-4].st) << endl;
                                                                salidanasm << "    mov ecx, " << (yyvsp[-1].st) << endl;
                                                                salidanasm << "    mov[ebx + eax], ecx" << endl; }
#line 1566 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 249 "AssemblerParser.y" /* yacc.c:1646  */
    {salidanasm << "    " << (yyvsp[-1].st) << ":" << endl;}
#line 1572 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 251 "AssemblerParser.y" /* yacc.c:1646  */
    {salidanasm << "    JMP " << (yyvsp[-1].st) << endl; }
#line 1578 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 253 "AssemblerParser.y" /* yacc.c:1646  */
    {
                                                                        QString oprel = (yyvsp[-5].st);
                                                                        salidanasm << "    mov eax, " << (yyvsp[-6].st) << endl;
                                                                        salidanasm << "    mov ebx, " << (yyvsp[-4].st) << endl;
                                                                        salidanasm << "    cmp eax, ebx" << endl;
                                                                        if(oprel == "==") {
                                                                          salidanasm << "    JE " << (yyvsp[-1].st) << endl;
                                                                        } else if (oprel == "!="){
                                                                          salidanasm << "    JNE " << (yyvsp[-1].st) << endl;
                                                                        } else if (oprel == ">"){
                                                                          salidanasm << "    JG " << (yyvsp[-1].st) << endl;
                                                                        } else if (oprel == ">="){
                                                                          salidanasm << "    JGE " << (yyvsp[-1].st) << endl;
                                                                        } else if (oprel == "<"){
                                                                          salidanasm << "    JL " << (yyvsp[-1].st) << endl;
                                                                        } else if (oprel == "<="){
                                                                          salidanasm << "    JLE " << (yyvsp[-1].st) << endl;
                                                                        }
                                                                    }
#line 1602 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 273 "AssemblerParser.y" /* yacc.c:1646  */
    {
                                                      salidanasm << "    mov eax, ptr" << endl;
                                                      salidanasm << "    add eax, "<< (yyvsp[-1].st) << endl;  
                                                      salidanasm << "    mov [" << (yyvsp[-5].st) << "], eax" << endl;
                                                      }
#line 1612 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 279 "AssemblerParser.y" /* yacc.c:1646  */
    {
                                                      salidanasm << "    mov eax, ptr" << endl;
                                                      salidanasm << "    add eax, "<< (yyvsp[-1].st) << endl;  
                                                      salidanasm << "    mov [ptr], eax" << endl;
                                                      }
#line 1622 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 285 "AssemblerParser.y" /* yacc.c:1646  */
    {
                                                      salidanasm << "    mov eax, ptr" << endl;
                                                      salidanasm << "    sub eax, "<< (yyvsp[-1].st) << endl;  
                                                      salidanasm << "    mov [ptr], eax" << endl;
                                                      }
#line 1632 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 291 "AssemblerParser.y" /* yacc.c:1646  */
    {  salidanasm << "    mov eax, ptrH" << endl;
                                              salidanasm << "    mov [" << (yyvsp[-3].st) << "], eax" << endl; }
#line 1639 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 293 "AssemblerParser.y" /* yacc.c:1646  */
    {salidanasm << "    mov eax, " << (yyvsp[-1].st) << endl;
                                              salidanasm << "    mov [" << (yyvsp[-3].st) << "], eax" << endl; }
#line 1646 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 296 "AssemblerParser.y" /* yacc.c:1646  */
    {salidanasm << "    mov eax, " << (yyvsp[-3].st) << endl;
                                              QString op = (yyvsp[-2].st);
                                              if(op == "+") {
                                                salidanasm << "    add eax, " << (yyvsp[-1].st) << endl;
                                              } else if(op=="-"){
                                                salidanasm << "    sub eax, " << (yyvsp[-1].st) << endl;
                                              } else if(op=="*"){
                                                salidanasm << "    mul " << (yyvsp[-1].st) << endl;
                                              } else if (op=="/"){
                                                salidanasm << "   div " << (yyvsp[-1].st) << endl;
                                              }
                                              salidanasm << "    mov [" << (yyvsp[-5].st) << "], eax" << endl;
                                              }
#line 1664 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 309 "AssemblerParser.y" /* yacc.c:1646  */
    {salidanasm << "    mov eax, " << (yyvsp[-3].st) << endl;
                                              QString op = (yyvsp[-2].st);
                                              if(op == "+") {
                                                salidanasm << "    add eax, " << (yyvsp[-1].st) << endl;
                                              } else if(op=="-"){
                                                salidanasm << "    sub eax, " << (yyvsp[-1].st) << endl;
                                              } else if(op=="*"){
                                                salidanasm << "    mul " << (yyvsp[-1].st) << endl;
                                              } else if (op=="/"){
                                                salidanasm << "   div " << (yyvsp[-1].st) << endl;
                                              }
                                              salidanasm << "    mov [" << (yyvsp[-5].st) << "], eax" << endl;
                                              }
#line 1682 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 323 "AssemblerParser.y" /* yacc.c:1646  */
    {(yyval.st) = (yyvsp[0].st);}
#line 1688 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 323 "AssemblerParser.y" /* yacc.c:1646  */
    {(yyval.st) = (yyvsp[0].st);}
#line 1694 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 323 "AssemblerParser.y" /* yacc.c:1646  */
    {(yyval.st) = (yyvsp[0].st);}
#line 1700 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 323 "AssemblerParser.y" /* yacc.c:1646  */
    {(yyval.st) = (yyvsp[0].st);}
#line 1706 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 325 "AssemblerParser.y" /* yacc.c:1646  */
    {salidanasm << "    call " << (yyvsp[-3].st) << endl;}
#line 1712 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 329 "AssemblerParser.y" /* yacc.c:1646  */
    {(yyval.st) = (yyvsp[0].st);}
#line 1718 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 329 "AssemblerParser.y" /* yacc.c:1646  */
    {(yyval.st) = (yyvsp[0].st);}
#line 1724 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 329 "AssemblerParser.y" /* yacc.c:1646  */
    {(yyval.st) = (yyvsp[0].st);}
#line 1730 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 329 "AssemblerParser.y" /* yacc.c:1646  */
    {(yyval.st) = (yyvsp[0].st);}
#line 1736 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 329 "AssemblerParser.y" /* yacc.c:1646  */
    {(yyval.st) = (yyvsp[0].st);}
#line 1742 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 329 "AssemblerParser.y" /* yacc.c:1646  */
    {(yyval.st) = (yyvsp[0].st);}
#line 1748 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 331 "AssemblerParser.y" /* yacc.c:1646  */
    {
                                                      salidanasm << "    mov eax, ptrH" << endl;
                                                      salidanasm << "    add eax, " << (yyvsp[-1].st) << endl;  
                                                      salidanasm << "    mov [ptrH], eax" << endl;
                                                      }
#line 1758 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 339 "AssemblerParser.y" /* yacc.c:1646  */
    {  salidanasm << "    mov eax, 4" << endl;
                                                                                        salidanasm << "    mov ebx, 1" << endl;
                                                                                        salidanasm << "    mov ecx, " << (yyvsp[-3].st) << endl;
                                                                                        salidanasm << "    mov edx, 100" << endl; 
                                                                                        salidanasm << "    int 80h" << endl;
                                                                                        
                                                                                         }
#line 1770 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 347 "AssemblerParser.y" /* yacc.c:1646  */
    {                      salidanasm << "    mov eax, 4" << endl;
                                                                                        salidanasm << "    mov ebx, 1" << endl;
                                                                                        salidanasm << "    mov ecx, " << (yyvsp[-3].st) << endl;
                                                                                        salidanasm << "    mov edx, 100" << endl; 
                                                                                        salidanasm << "    int 80h" << endl;
                                                                                         }
#line 1781 "AssemblerParser.cpp" /* yacc.c:1646  */
    break;


#line 1785 "AssemblerParser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 354 "AssemblerParser.y" /* yacc.c:1906  */


