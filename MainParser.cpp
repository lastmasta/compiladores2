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
#define yyparse         mainparserparse
#define yylex           mainparserlex
#define yyerror         mainparsererror
#define yydebug         mainparserdebug
#define yynerrs         mainparsernerrs

#define yylval          mainparserlval
#define yychar          mainparserchar

/* Copy the first part of user declarations.  */
#line 1 "MainParser.y" /* yacc.c:339  */


  #include "MainScanner.h"
  #include "generadordecodigo.h"
  #include "GlobalGenerador.h"
  #include "graficadorast.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include <iostream>
  #include <fstream>
  #include "nodo.h"
  using namespace std;

  extern int mainparserlex(void);
  extern char *mainparsertext;
  extern int mainparserlineno;
  extern int mainparsercolno;
  extern FILE *Mainin;
  ofstream archivo3D;
  ofstream errores;
  void mainparsererror(char*s);


void inicializar() {
    errores.open("errores.txt");
    archivo3D.open("3D.cpp");
    archivo3D.flush();
    archivo3D.close();
    gdc.tabla.limpiar();
    gdc.etq = 0;
    gdc.tmp = 0;
    gdc.decMetodos = "";
    gdc.decIniciales = "";
    gdc.codigo3D = "";
    gdc.decMetodos+="void imprimir_cadena();|";
    gdc.decMetodos+="void imprimir_num();|";
    gdc.decMetodos+="void imprimir_caracter();|";
    gdc.generarImprimir();
}

TablaSimbolos *getTabla()
{
  TablaSimbolos *t = &gdc.tabla;
  return t;
}

void mainparsererror(const char *s) {
errores << "Error SINTACTICO en la fila: " << mainparserlineno << " y columna: " << mainparsercolno<< ": "<<mainparsertext << endl;
}



#line 127 "MainParser.cpp" /* yacc.c:339  */

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
   by #include "MainParser.h".  */
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
#line 55 "MainParser.y" /* yacc.c:355  */

   #include "nodo.h"

#line 161 "MainParser.cpp" /* yacc.c:355  */

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
#line 59 "MainParser.y" /* yacc.c:355  */

char *st;
Nodo *nodo;

#line 242 "MainParser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE mainparserlval;

int mainparserparse (void);

#endif /* !YY_MAINPARSER_MAINPARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 257 "MainParser.cpp" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   592

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  275

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   208,   208,   217,   227,   234,   241,   253,   265,   271,
     277,   284,   293,   299,   305,   312,   318,   324,   329,   334,
     341,   351,   363,   374,   387,   393,   399,   405,   411,   417,
     423,   429,   435,   442,   448,   456,   468,   479,   490,   500,
     503,   509,   515,   524,   537,   543,   549,   551,   556,   561,
     566,   571,   576,   581,   586,   591,   596,   602,   607,   611,
     621,   632,   638,   646,   654,   662,   664,   672,   680,   688,
     696,   704,   712,   720,   722,   730,   738,   746,   754,   762,
     764,   765,   771,   777,   778,   779,   781,   789,   798,   809,
     815,   821,   827,   836,   841,   850,   860,   870,   880,   890,
     897,   904,   911,   919,   929,   941,   946,   953,   961,   969,
     974,   979,   986,   991,   997,  1003,  1009,  1015,  1021,  1029,
    1036,  1047,  1052,  1057,  1063,  1071,  1078,  1086,  1093,  1100,
    1107,  1115,  1124,  1131,  1140,  1149,  1158
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ERROR", "par_a", "par_c", "llave_a",
  "llave_c", "sig_igual", "p_coma", "dos_p", "punto", "comillas", "coma",
  "id", "numero", "string_token", "caracter_token", "clase_rsv",
  "extiende_rsv", "paratodos_rsv", "protegido_rsv", "privado_rsv", "dolar",
  "traer_rsv", "decattr_rsv", "entero_rsv", "bool_rsv", "caracter_rsv",
  "cadena_rsv", "def_rsv", "ninguno_rsv", "retornar_rsv", "ref_rsv",
  "si_cumple_rsv", "sino_intente", "sino_cumple_rsv",
  "repetir_mientras_rsv", "detener_rsv", "decarr_rsv", "true_rsv",
  "false_rsv", "imprimir_rsv", "instanciar_rsv", "este_rsv", "esigual",
  "noigual", "mayor", "menor", "mayorigual", "menorigual", "esnulo",
  "orOp", "andOp", "notOp", "mas", "menos", "por", "divOp", "potencia",
  "numeralnumeral", "masmas", "menosmenos", "porpor", "$accept", "INICIO",
  "CLASE_LIST", "CLASE", "TIPO_ACCESO", "EXTIENDE", "IMPORT_LIST",
  "IMPORT", "CUERPO_CLASE", "SENTENCIAS_CLASE", "DECATR", "DECARRATR",
  "DIMLIST", "DIM", "TIPO", "BOOL", "DECMETODO", "PARAMLIST", "PARAM",
  "INSTRUCCIONES", "SENTENCIAS", "DECVAR", "RETORNO", "EXPLOG",
  "EXPRESION", "EXPMAT", "EXP", "IF", "ELSE", "ELSEIFLIST", "ELSEIF",
  "DETENER", "CICLO", "OPSIMP", "DECARRVAR", "ASIGNACION", "VALOR",
  "INICIAR_ARR", "LISTA_ASIG_ARR", "ASIGLIST", "ARR_ACCESO", "ASIG_ARR",
  "VAR_ASIG", "FUNCALL", "IMPRIMIR", "INSTANCIAR", "PARAMS",
  "ACCESOATRIBUTO", "MODIFATRIBUTO", "ACCESOMETODO", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318
};
# endif

#define YYPACT_NINF -162

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-162)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     206,  -162,  -162,  -162,    11,    34,   134,  -162,    30,   206,
    -162,  -162,  -162,  -162,    31,   134,  -162,    66,    46,   362,
      49,  -162,  -162,   134,    83,   134,   363,  -162,    87,   112,
    -162,   362,    61,   554,   102,   110,  -162,  -162,  -162,  -162,
     443,   554,  -162,  -162,  -162,  -162,  -162,  -162,   140,   554,
     554,  -162,   131,     6,   144,   157,   267,   156,   554,   167,
      12,  -162,     9,   400,   105,  -162,   381,    32,  -162,  -162,
    -162,  -162,  -162,   182,   174,   191,   381,  -162,    81,   296,
     198,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,   490,
    -162,   535,  -162,   554,   184,     4,   197,    16,    80,   203,
     211,   490,   215,  -162,    27,   274,   218,  -162,  -162,  -162,
    -162,   157,   366,   231,   222,  -162,   381,   381,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   400,   400,   400,
    -162,  -162,  -162,  -162,   229,   233,   381,   236,   238,  -162,
     395,  -162,   237,   249,  -162,   263,  -162,   268,   271,   284,
     288,   289,   295,   188,   297,  -162,   535,  -162,   535,   282,
     298,   303,  -162,   259,  -162,  -162,  -162,  -162,    17,   318,
     321,   315,   319,   280,  -162,   276,   276,   276,   276,   276,
     276,  -162,   135,   135,   279,   279,   279,  -162,   267,   161,
      81,   381,   381,   229,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,   267,  -162,  -162,  -162,   267,  -162,   420,   433,   535,
    -162,  -162,  -162,  -162,    75,   107,  -162,   366,   320,  -162,
    -162,    39,   335,  -162,   267,   169,    57,    78,  -162,  -162,
    -162,  -162,   446,  -162,   215,  -162,   267,  -162,  -162,    42,
    -162,  -162,    65,  -162,   215,   325,   330,  -162,  -162,  -162,
    -162,  -162,  -162,   535,   535,   471,   484,   175,  -162,   350,
     340,  -162,   175,  -162,   381,   535,  -162,  -162,   132,   497,
     344,  -162,   535,   522,  -162
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,     9,    10,     0,     0,     2,     5,     0,     0,
      13,    14,     1,     4,     0,     3,    12,     0,     0,     0,
       0,    11,    39,     0,     0,     0,     0,    16,     0,     0,
      18,     0,     0,     0,     0,     0,     6,    15,    17,    19,
       0,     0,    32,    27,    30,    29,    28,    31,     0,     0,
       0,     7,    20,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,    22,    25,     0,    81,    82,   107,
     108,    33,    34,     0,     0,     0,     0,    84,   109,    65,
      73,    79,    83,    21,   105,    85,   111,   121,   106,   110,
     122,     0,    42,     0,     0,     0,     0,     0,    81,     0,
       0,     0,     0,    24,     0,     0,     0,    98,    95,    96,
      97,   118,     0,     0,     0,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     102,    99,   100,   101,    46,     0,     0,     0,     0,    93,
       0,    45,     0,     0,    49,     0,    50,     0,     0,     0,
       0,     0,     0,     0,     0,    43,     0,    40,     0,     0,
       0,     0,    26,     0,    23,    80,   123,   129,     0,   130,
       0,     0,   131,    62,    63,    66,    67,    68,    69,    70,
      71,    72,    74,    75,    76,    77,    78,    58,     0,    59,
      61,     0,     0,     0,    38,    44,    47,    48,    51,    52,
      53,     0,    54,    55,    56,     0,    57,     0,     0,     0,
     130,   131,   117,   115,     0,     0,   124,     0,     0,   125,
     127,     0,     0,   120,     0,   103,     0,     0,   119,   132,
      36,    37,     0,   112,     0,   113,     0,   128,   133,     0,
     126,   134,     0,    60,     0,     0,     0,    35,   114,   116,
     135,   136,   104,     0,     0,     0,     0,    86,    94,     0,
       0,    87,     0,    91,     0,     0,    88,    90,     0,     0,
       0,    89,     0,     0,    92
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,   349,    13,   262,  -162,  -162,   359,   341,     0,
    -162,  -162,   -54,   -60,   -34,  -162,  -162,   309,   278,   -20,
    -109,  -162,  -162,   -63,   468,   -61,  -162,  -162,   116,  -162,
     122,  -162,  -162,   -82,  -162,  -155,  -100,  -157,  -162,  -162,
     -50,  -162,  -162,     7,  -162,  -162,  -161,   -56,  -162,  -162
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    20,     9,    10,    26,    27,
      28,    29,   111,    65,    48,    77,    30,    60,    61,   140,
     141,   142,   143,    78,    79,    80,    81,   144,   261,   262,
     263,   145,   146,    82,   148,    83,    84,   164,   214,   215,
      85,   150,   151,   152,    87,    88,   168,   101,   154,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      89,    64,   100,   104,   103,   167,   213,    52,   212,   147,
     221,    57,   170,   115,    96,    54,    55,    94,    58,    13,
      58,   159,   216,    58,    92,    95,    37,    11,    13,    95,
     217,   195,   165,   223,    12,   153,   105,    59,    63,    59,
      37,   149,    59,   106,   240,    17,   228,   250,    14,    89,
     229,   103,   217,   173,   174,   217,    89,   239,   147,   155,
      21,   242,   245,    86,   182,   183,   184,   185,   186,   243,
     251,   167,    31,   190,   147,    41,   147,   248,   217,   116,
     117,   249,   233,   246,   153,    18,    63,   252,   234,    19,
     149,   160,   107,   108,   109,   110,    38,    33,   195,   195,
     153,   189,   153,     1,     2,     3,   149,    89,   149,   116,
     117,    63,    86,   102,   235,    89,    49,   237,   167,    86,
     236,    39,   167,   195,    50,   147,   147,   147,   226,   227,
     116,   117,    89,   116,   117,   225,   207,   270,   208,    56,
     107,   108,   109,   110,    53,    89,   195,   195,    62,    89,
     147,   153,   153,   153,     1,     2,     3,   149,   149,   149,
     195,    89,    89,    63,   195,   103,    89,    63,    89,   224,
      86,   147,   147,   147,   147,    63,   153,   244,    86,    91,
      89,    93,   149,   147,   116,   117,   112,   147,   113,   232,
     147,   147,   127,   128,   129,    86,   205,   153,   153,   153,
     153,   268,   114,   149,   149,   149,   149,   156,    86,   153,
     259,   260,    86,   153,   161,   149,   153,   153,   162,   149,
     158,   163,   149,   149,    86,    86,     1,     2,     3,    86,
       4,    86,   169,   255,   256,   171,   172,   105,   187,    63,
     191,   188,   192,    86,   106,   269,   196,    42,   130,   131,
     132,   133,   273,   125,   126,   127,   128,   129,   197,    43,
      44,    45,    46,    66,    47,   163,   125,   126,   127,   128,
     129,    66,   198,    67,    68,    69,    70,   199,    66,   166,
     200,    67,    68,    69,    70,    32,    34,    35,    67,    68,
      69,    70,   201,   107,   108,   109,   110,   202,   203,    71,
      72,    73,    74,    75,   204,   209,   206,    71,    72,    73,
      74,    75,   210,    76,    71,    72,    73,   211,    75,    66,
     220,    76,   218,   222,    66,   238,   219,   124,    76,    67,
      68,    69,    70,   117,    67,    68,    69,    70,   129,    66,
     241,   118,   119,   120,   121,   122,   123,   124,   253,    67,
      68,    69,    70,   254,   264,    71,    72,    73,    15,    75,
      71,    72,    73,   265,    75,    22,    22,   272,    16,    76,
      66,    97,    40,   157,    76,    71,    72,    73,   266,    75,
      67,    68,    69,    70,   267,    66,    36,    23,    23,    76,
       0,     0,    24,    24,     0,    98,    68,     0,   193,     0,
       0,    25,    25,     0,    66,     0,    71,    72,    73,   135,
      75,     0,     0,     0,    98,    68,     0,     0,   194,     0,
      76,    71,    72,   193,     0,    99,     0,   136,     0,   137,
       0,     0,   138,   139,   135,    76,   193,    73,     0,    75,
      71,    72,     0,   230,    99,     0,    22,   135,     0,   193,
       0,     0,   136,     0,   137,     0,   231,   138,   139,     0,
     135,     0,    73,     0,    75,   136,    51,   137,    23,   247,
     138,   139,     0,    24,   193,    73,     0,    75,   136,     0,
     137,     0,    25,   138,   139,   135,     0,   193,    73,     0,
      75,     0,     0,     0,   257,     0,     0,     0,   135,     0,
     193,     0,     0,   136,     0,   137,     0,   258,   138,   139,
       0,   135,     0,    73,     0,    75,   136,     0,   137,     0,
     271,   138,   139,     0,     0,   193,    73,     0,    75,   136,
       0,   137,     0,     0,   138,   139,   135,     0,   134,    73,
       0,    75,     0,     0,     0,   274,     0,     0,     0,   135,
     130,   131,   132,   133,   136,     0,   137,     0,     0,   138,
     139,     0,     0,     0,    73,     0,    75,   136,    42,   137,
       0,     0,   138,   139,     0,     0,     0,    73,     0,    75,
      43,    44,    45,    46,     0,    47,   175,   176,   177,   178,
     179,   180,   181
};

static const yytype_int16 yycheck[] =
{
      56,    55,    63,    66,    64,   105,   163,    41,   163,    91,
     171,     5,   112,    76,     5,    49,    50,     5,    14,     6,
      14,     5,     5,    14,    58,    13,    26,    16,    15,    13,
      13,   140,     5,   188,     0,    91,     4,    33,     6,    33,
      40,    91,    33,    11,     5,    14,   201,     5,    18,   105,
     205,   111,    13,   116,   117,    13,   112,   218,   140,    93,
      14,   222,     5,    56,   125,   126,   127,   128,   129,   224,
       5,   171,    23,   136,   156,    14,   158,   234,    13,    52,
      53,   236,     7,     5,   140,    19,     6,   244,    13,    23,
     140,    11,    60,    61,    62,    63,     9,    14,   207,   208,
     156,   135,   158,    20,    21,    22,   156,   163,   158,    52,
      53,     6,   105,     8,     7,   171,    14,   217,   218,   112,
      13,     9,   222,   232,    14,   207,   208,   209,   191,   192,
      52,    53,   188,    52,    53,   189,   156,     5,   158,     8,
      60,    61,    62,    63,     4,   201,   255,   256,     4,   205,
     232,   207,   208,   209,    20,    21,    22,   207,   208,   209,
     269,   217,   218,     6,   273,   225,   222,     6,   224,     8,
     163,   253,   254,   255,   256,     6,   232,     8,   171,    23,
     236,    14,   232,   265,    52,    53,     4,   269,    14,   209,
     272,   273,    57,    58,    59,   188,     8,   253,   254,   255,
     256,   264,    11,   253,   254,   255,   256,    23,   201,   265,
      35,    36,   205,   269,    11,   265,   272,   273,     7,   269,
      23,     6,   272,   273,   217,   218,    20,    21,    22,   222,
      24,   224,    14,   253,   254,     4,    14,     4,     9,     6,
       4,     8,     4,   236,    11,   265,     9,    14,    60,    61,
      62,    63,   272,    55,    56,    57,    58,    59,     9,    26,
      27,    28,    29,     4,    31,     6,    55,    56,    57,    58,
      59,     4,     9,    14,    15,    16,    17,     9,     4,     5,
       9,    14,    15,    16,    17,    23,    24,    25,    14,    15,
      16,    17,     8,    60,    61,    62,    63,     9,     9,    40,
      41,    42,    43,    44,     9,    23,     9,    40,    41,    42,
      43,    44,    14,    54,    40,    41,    42,    14,    44,     4,
       5,    54,     4,     4,     4,     5,     5,    51,    54,    14,
      15,    16,    17,    53,    14,    15,    16,    17,    59,     4,
       5,    45,    46,    47,    48,    49,    50,    51,    23,    14,
      15,    16,    17,    23,     4,    40,    41,    42,     9,    44,
      40,    41,    42,    23,    44,     3,     3,    23,     9,    54,
       4,    62,    31,    95,    54,    40,    41,    42,   262,    44,
      14,    15,    16,    17,   262,     4,    23,    25,    25,    54,
      -1,    -1,    30,    30,    -1,    14,    15,    -1,     3,    -1,
      -1,    39,    39,    -1,     4,    -1,    40,    41,    42,    14,
      44,    -1,    -1,    -1,    14,    15,    -1,    -1,    23,    -1,
      54,    40,    41,     3,    -1,    44,    -1,    32,    -1,    34,
      -1,    -1,    37,    38,    14,    54,     3,    42,    -1,    44,
      40,    41,    -1,    23,    44,    -1,     3,    14,    -1,     3,
      -1,    -1,    32,    -1,    34,    -1,    23,    37,    38,    -1,
      14,    -1,    42,    -1,    44,    32,    23,    34,    25,    23,
      37,    38,    -1,    30,     3,    42,    -1,    44,    32,    -1,
      34,    -1,    39,    37,    38,    14,    -1,     3,    42,    -1,
      44,    -1,    -1,    -1,    23,    -1,    -1,    -1,    14,    -1,
       3,    -1,    -1,    32,    -1,    34,    -1,    23,    37,    38,
      -1,    14,    -1,    42,    -1,    44,    32,    -1,    34,    -1,
      23,    37,    38,    -1,    -1,     3,    42,    -1,    44,    32,
      -1,    34,    -1,    -1,    37,    38,    14,    -1,     3,    42,
      -1,    44,    -1,    -1,    -1,    23,    -1,    -1,    -1,    14,
      60,    61,    62,    63,    32,    -1,    34,    -1,    -1,    37,
      38,    -1,    -1,    -1,    42,    -1,    44,    32,    14,    34,
      -1,    -1,    37,    38,    -1,    -1,    -1,    42,    -1,    44,
      26,    27,    28,    29,    -1,    31,   118,   119,   120,   121,
     122,   123,   124
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    22,    24,    65,    66,    67,    68,    70,
      71,    16,     0,    67,    18,    66,    71,    14,    19,    23,
      69,    14,     3,    25,    30,    39,    72,    73,    74,    75,
      80,    23,    68,    14,    68,    68,    23,    73,     9,     9,
      72,    14,    14,    26,    27,    28,    29,    31,    78,    14,
      14,    23,    78,     4,    78,    78,     8,     5,    14,    33,
      81,    82,     4,     6,    76,    77,     4,    14,    15,    16,
      17,    40,    41,    42,    43,    44,    54,    79,    87,    88,
      89,    90,    97,    99,   100,   104,   107,   108,   109,   111,
     113,    23,    78,    14,     5,    13,     5,    81,    14,    44,
      89,   111,     8,    77,    87,     4,    11,    60,    61,    62,
      63,    76,     4,    14,    11,    87,    52,    53,    45,    46,
      47,    48,    49,    50,    51,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     3,    14,    32,    34,    37,    38,
      83,    84,    85,    86,    91,    95,    96,    97,    98,   104,
     105,   106,   107,   111,   112,    78,    23,    82,    23,     5,
      11,    11,     7,     6,   101,     5,     5,   100,   110,    14,
     100,     4,    14,    87,    87,    88,    88,    88,    88,    88,
      88,    88,    89,    89,    89,    89,    89,     9,     8,    78,
      87,     4,     4,     3,    23,    84,     9,     9,     9,     9,
       9,     8,     9,     9,     9,     8,     9,    83,    83,    23,
      14,    14,    99,   101,   102,   103,     5,    13,     4,     5,
       5,   110,     4,    99,     8,    76,    87,    87,    99,    99,
      23,    23,    83,     7,    13,     7,    13,   100,     5,   110,
       5,     5,   110,    99,     8,     5,     5,    23,   101,    99,
       5,     5,   101,    23,    23,    83,    83,    23,    23,    35,
      36,    92,    93,    94,     4,    23,    92,    94,    87,    83,
       5,    23,    23,    83,    23
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      68,    69,    70,    70,    71,    72,    72,    73,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    78,    78,    78,
      78,    78,    78,    79,    79,    80,    80,    80,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    85,
      85,    86,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    89,    89,    89,    89,
      90,    90,    90,    90,    90,    90,    91,    91,    91,    92,
      93,    93,    94,    95,    96,    97,    97,    97,    97,    97,
      97,    97,    97,    98,    98,    99,    99,   100,   100,   100,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   105,
     106,   107,   107,   107,   107,   108,   109,   109,   110,   110,
     111,   111,   112,   113,   113,   113,   113
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     6,     7,     1,     1,
       1,     2,     2,     1,     2,     2,     1,     2,     1,     2,
       4,     6,     5,     7,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,    10,     9,     9,     8,     1,
       3,     1,     2,     3,     2,     1,     1,     2,     2,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       4,     2,     3,     3,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     7,     8,     9,     4,
       2,     1,     7,     1,     7,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     5,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     1,     3,     1,     2,     3,
       3,     1,     1,     3,     4,     4,     5,     4,     3,     1,
       3,     3,     3,     5,     5,     6,     6
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
#line 208 "MainParser.y" /* yacc.c:1646  */
    {
                        errores.close();
                        Nodo* nodo = new Nodo("INICIO");
                        nodo->AgregarHijo((yyvsp[0].nodo));
                        GraficadorAST* ga = new GraficadorAST();
                        ga->Graficar(nodo);
                        gdc.AgregarAbol(nodo);
                        
                      }
#line 1607 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 217 "MainParser.y" /* yacc.c:1646  */
    {
                                    errores.close();
                                    Nodo* nodo = new Nodo("INICIO");
                                    nodo->AgregarHijo((yyvsp[-1].nodo));
                                    nodo->AgregarHijo((yyvsp[0].nodo));
                                    GraficadorAST* ga = new GraficadorAST();
                                    ga->Graficar(nodo);
                                    gdc.AgregarAbol(nodo);
                                    
                                  }
#line 1622 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 227 "MainParser.y" /* yacc.c:1646  */
    {
                            Nodo* nodo = new Nodo("CLASE_LIST");
                            nodo->AgregarHijo((yyvsp[-1].nodo));
                            nodo->AgregarHijo((yyvsp[0].nodo));
                            (yyval.nodo) = nodo;
                            }
#line 1633 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 234 "MainParser.y" /* yacc.c:1646  */
    {
                        Nodo* nodo = new Nodo("CLASE_LIST");
                        nodo->AgregarHijo((yyvsp[0].nodo));
                        (yyval.nodo) = nodo;
                      }
#line 1643 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 241 "MainParser.y" /* yacc.c:1646  */
    {
                                                                              Nodo* nodo = new Nodo("CLASE");
                                                                              nodo->AgregarHijo((yyvsp[-5].nodo));

                                                                              Nodo* id = new Nodo("ID");
                                                                              Nodo* n = new Nodo(QString::fromStdString((yyvsp[-3].st)));
                                                                              id->AgregarHijo(n);
                                                                              nodo->AgregarHijo(id);
                                                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                                                              (yyval.nodo) = nodo;
                                                                            }
#line 1659 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 253 "MainParser.y" /* yacc.c:1646  */
    {
                                                                              Nodo* nodo = new Nodo("CLASE");
                                                                              nodo->AgregarHijo((yyvsp[-6].nodo));
                                                                              Nodo* id = new Nodo("ID");
                                                                              Nodo* n = new Nodo(QString::fromStdString((yyvsp[-4].st)));
                                                                              id->AgregarHijo(n);
                                                                              nodo->AgregarHijo(id);
                                                                              nodo->AgregarHijo((yyvsp[-3].nodo));
                                                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                                                              (yyval.nodo) = nodo;
                                                                            }
#line 1675 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 265 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("TIPO_ACCESO");
                                Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                nodo->AgregarHijo(val);
                                (yyval.nodo) = nodo;
                              }
#line 1686 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 271 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("TIPO_ACCESO");
                                Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                nodo->AgregarHijo(val);
                                (yyval.nodo) = nodo;
                              }
#line 1697 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 277 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("TIPO_ACCESO");
                                Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                nodo->AgregarHijo(val);
                                (yyval.nodo) = nodo;
                              }
#line 1708 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 284 "MainParser.y" /* yacc.c:1646  */
    {
                                    Nodo* nodo = new Nodo("EXTIENDE");
                                    Nodo* id = new Nodo("ID");
                                    Nodo* n = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                    id->AgregarHijo(n);
                                    nodo->AgregarHijo(id);
                                    (yyval.nodo) = nodo;
                                  }
#line 1721 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 293 "MainParser.y" /* yacc.c:1646  */
    {
                          Nodo* nodo = new Nodo("IMPORT_LIST");
                          nodo->AgregarHijo((yyvsp[-1].nodo));
                          nodo->AgregarHijo((yyvsp[0].nodo));
                          (yyval.nodo) = nodo;
                        }
#line 1732 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 299 "MainParser.y" /* yacc.c:1646  */
    {
                          Nodo* nodo = new Nodo("IMPORT_LIST");
                          nodo->AgregarHijo((yyvsp[0].nodo));
                          (yyval.nodo) = nodo;
                        }
#line 1742 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 305 "MainParser.y" /* yacc.c:1646  */
    {
                                          Nodo* nodo = new Nodo("IMPORT");
                                          Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                          nodo->AgregarHijo(val);
                                          (yyval.nodo) = nodo;
                                        }
#line 1753 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 312 "MainParser.y" /* yacc.c:1646  */
    {
                                  Nodo* nodo = new Nodo("CUERPO_CLASE");
                                  nodo->AgregarHijo((yyvsp[-1].nodo));
                                  nodo->AgregarHijo((yyvsp[0].nodo));
                                  (yyval.nodo) = nodo;
                                }
#line 1764 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 318 "MainParser.y" /* yacc.c:1646  */
    {
                                  Nodo* nodo = new Nodo("CUERPO_CLASE");
                                  nodo->AgregarHijo((yyvsp[0].nodo));
                                  (yyval.nodo) = nodo;
                                }
#line 1774 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 324 "MainParser.y" /* yacc.c:1646  */
    {
                                    Nodo* nodo = new Nodo("SENTENCIAS_CLASE");
                                    nodo->AgregarHijo((yyvsp[-1].nodo));
                                    (yyval.nodo) = nodo;
                                  }
#line 1784 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 329 "MainParser.y" /* yacc.c:1646  */
    {
                                    Nodo* nodo = new Nodo("SENTENCIAS_CLASE");
                                    nodo->AgregarHijo((yyvsp[0].nodo));
                                    (yyval.nodo) = nodo;
                                  }
#line 1794 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 334 "MainParser.y" /* yacc.c:1646  */
    {
                                    Nodo* nodo = new Nodo("SENTENCIAS_CLASE");
                                    nodo->AgregarHijo((yyvsp[-1].nodo));
                                    (yyval.nodo) = nodo;
                                  }
#line 1804 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 341 "MainParser.y" /* yacc.c:1646  */
    {
                                                                  Nodo* nodo = new Nodo("DECATR");
                                                                  nodo->AgregarHijo((yyvsp[-2].nodo));
                                                                  Nodo* id = new Nodo("ID");
                                                                  Nodo* n = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                                                  id->AgregarHijo(n);
                                                                  nodo->AgregarHijo(id);
                                                                  nodo->AgregarHijo((yyvsp[0].nodo));
                                                                  (yyval.nodo) = nodo;
                                                                }
#line 1819 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 351 "MainParser.y" /* yacc.c:1646  */
    {
                                                                  Nodo* nodo = new Nodo("DECATR");
                                                                  nodo->AgregarHijo((yyvsp[-4].nodo));
                                                                  Nodo* id = new Nodo("ID");
                                                                  Nodo* n = new Nodo(QString::fromStdString((yyvsp[-3].st)));
                                                                  id->AgregarHijo(n);
                                                                  nodo->AgregarHijo(id);
                                                                  nodo->AgregarHijo((yyvsp[-2].nodo));
                                                                  nodo->AgregarHijo((yyvsp[0].nodo));
                                                                  (yyval.nodo) = nodo;
                                                                }
#line 1835 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 363 "MainParser.y" /* yacc.c:1646  */
    {
                                                                              Nodo* nodo = new Nodo("DECARRATR");
                                                                              nodo->AgregarHijo((yyvsp[-3].nodo));
                                                                              Nodo* id = new Nodo("ID");
                                                                              Nodo* n = new Nodo(QString::fromStdString((yyvsp[-2].st)));
                                                                              id->AgregarHijo(n);
                                                                              nodo->AgregarHijo(id);
                                                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                                                              nodo->AgregarHijo((yyvsp[0].nodo));
                                                                              (yyval.nodo) = nodo;
                                                                            }
#line 1851 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 374 "MainParser.y" /* yacc.c:1646  */
    {
                                                                              Nodo* nodo = new Nodo("DECARRATR");
                                                                              nodo->AgregarHijo((yyvsp[-5].nodo));
                                                                              Nodo* id = new Nodo("ID");
                                                                              Nodo* n = new Nodo(QString::fromStdString((yyvsp[-4].st)));
                                                                              id->AgregarHijo(n);
                                                                              nodo->AgregarHijo(id);
                                                                              nodo->AgregarHijo((yyvsp[-3].nodo));
                                                                              nodo->AgregarHijo((yyvsp[-2].nodo));
                                                                              nodo->AgregarHijo((yyvsp[0].nodo));
                                                                              (yyval.nodo) = nodo;
                                                                            }
#line 1868 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 387 "MainParser.y" /* yacc.c:1646  */
    {
                          Nodo* nodo = new Nodo("DIMLIST");
                          nodo->AgregarHijo((yyvsp[-1].nodo));
                          nodo->AgregarHijo((yyvsp[0].nodo));
                          (yyval.nodo) = nodo;
                        }
#line 1879 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 393 "MainParser.y" /* yacc.c:1646  */
    {
                  Nodo* nodo = new Nodo("DIMLIST");
                  nodo->AgregarHijo((yyvsp[0].nodo));
                  (yyval.nodo) = nodo;
                }
#line 1889 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 399 "MainParser.y" /* yacc.c:1646  */
    {
                                    Nodo* nodo = new Nodo("DIM");
                                    nodo->AgregarHijo((yyvsp[-1].nodo));
                                    (yyval.nodo) = nodo;
                                    }
#line 1899 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 405 "MainParser.y" /* yacc.c:1646  */
    {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
            nodo->AgregarHijo(val);
            (yyval.nodo) = nodo;
          }
#line 1910 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 411 "MainParser.y" /* yacc.c:1646  */
    {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
            nodo->AgregarHijo(val);
            (yyval.nodo) = nodo;
          }
#line 1921 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 417 "MainParser.y" /* yacc.c:1646  */
    {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
            nodo->AgregarHijo(val);
            (yyval.nodo) = nodo;
          }
#line 1932 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 423 "MainParser.y" /* yacc.c:1646  */
    {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
            nodo->AgregarHijo(val);
            (yyval.nodo) = nodo;
          }
#line 1943 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 429 "MainParser.y" /* yacc.c:1646  */
    {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
            nodo->AgregarHijo(val);
            (yyval.nodo) = nodo;
          }
#line 1954 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 435 "MainParser.y" /* yacc.c:1646  */
    {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
            nodo->AgregarHijo(val);
            (yyval.nodo) = nodo;
          }
#line 1965 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 442 "MainParser.y" /* yacc.c:1646  */
    {
                  Nodo* nodo = new Nodo("BOOL");
                  Nodo* val = new Nodo("true");
                  nodo->AgregarHijo(val);
                  (yyval.nodo) = nodo;
                }
#line 1976 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 448 "MainParser.y" /* yacc.c:1646  */
    {
                  Nodo* nodo = new Nodo("BOOL");
                  Nodo* val = new Nodo("false");
                  nodo->AgregarHijo(val);
                  (yyval.nodo) = nodo;
                }
#line 1987 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 456 "MainParser.y" /* yacc.c:1646  */
    {
                                                                                          Nodo* nodo = new Nodo("DECMETODO");
                                                                                          nodo->AgregarHijo((yyvsp[-8].nodo));
                                                                                          Nodo* id = new Nodo("ID");
                                                                                          Nodo* n = new Nodo(QString::fromStdString((yyvsp[-7].st)));
                                                                                          id->AgregarHijo(n);
                                                                                          nodo->AgregarHijo(id);
                                                                                          nodo->AgregarHijo((yyvsp[-6].nodo));
                                                                                          nodo->AgregarHijo((yyvsp[-4].nodo));
                                                                                          nodo->AgregarHijo((yyvsp[-1].nodo));
                                                                                          (yyval.nodo) = nodo;
                                                                                        }
#line 2004 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 468 "MainParser.y" /* yacc.c:1646  */
    {
                                                                              Nodo* nodo = new Nodo("DECMETODO");
                                                                              Nodo* id = new Nodo("ID");
                                                                              Nodo* n = new Nodo(QString::fromStdString((yyvsp[-7].st)));
                                                                              id->AgregarHijo(n);
                                                                              nodo->AgregarHijo(id);
                                                                              nodo->AgregarHijo((yyvsp[-6].nodo));
                                                                              nodo->AgregarHijo((yyvsp[-4].nodo));
                                                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                                                              (yyval.nodo) = nodo;
                                                                          }
#line 2020 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 479 "MainParser.y" /* yacc.c:1646  */
    {
                                                                              Nodo* nodo = new Nodo("DECMETODO");
                                                                              nodo->AgregarHijo((yyvsp[-7].nodo));
                                                                              Nodo* id = new Nodo("ID");
                                                                              Nodo* n = new Nodo(QString::fromStdString((yyvsp[-6].st)));
                                                                              id->AgregarHijo(n);
                                                                              nodo->AgregarHijo(id);
                                                                              nodo->AgregarHijo((yyvsp[-5].nodo));
                                                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                                                              (yyval.nodo) = nodo;
                                                                            }
#line 2036 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 490 "MainParser.y" /* yacc.c:1646  */
    {
                                                                  Nodo* nodo = new Nodo("DECMETODO");
                                                                  Nodo* id = new Nodo("ID");
                                                                  Nodo* n = new Nodo(QString::fromStdString((yyvsp[-6].st)));
                                                                  id->AgregarHijo(n);
                                                                  nodo->AgregarHijo(id);
                                                                  nodo->AgregarHijo((yyvsp[-5].nodo));
                                                                  nodo->AgregarHijo((yyvsp[-1].nodo));
                                                                  (yyval.nodo) = nodo;
                                                                }
#line 2051 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 500 "MainParser.y" /* yacc.c:1646  */
    {YYERROR;}
#line 2057 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 503 "MainParser.y" /* yacc.c:1646  */
    {
                                    Nodo* nodo = new Nodo("PARAMLIST");
                                    nodo->AgregarHijo((yyvsp[-2].nodo));
                                    nodo->AgregarHijo((yyvsp[0].nodo));
                                    (yyval.nodo) = nodo;
                                  }
#line 2068 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 509 "MainParser.y" /* yacc.c:1646  */
    {
                    Nodo* nodo = new Nodo("PARAMLIST");
                    nodo->AgregarHijo((yyvsp[0].nodo));
                    (yyval.nodo) = nodo;
          }
#line 2078 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 515 "MainParser.y" /* yacc.c:1646  */
    {
                    Nodo* nodo = new Nodo("PARAM");
                    Nodo* id = new Nodo("ID");
                    Nodo* n = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                    id->AgregarHijo(n);
                    nodo->AgregarHijo(id);
                    nodo->AgregarHijo((yyvsp[0].nodo));
                    (yyval.nodo) = nodo;
                  }
#line 2092 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 524 "MainParser.y" /* yacc.c:1646  */
    {
                            Nodo* nodo = new Nodo("REFPARAM");
                            Nodo* ref = new Nodo("ref");
                            Nodo* id = new Nodo("ID");
                            Nodo* n = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                            id->AgregarHijo(n);
                            nodo->AgregarHijo(ref);
                            nodo->AgregarHijo(id);
                            nodo->AgregarHijo((yyvsp[0].nodo));
                            (yyval.nodo) = nodo;
                          }
#line 2108 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 537 "MainParser.y" /* yacc.c:1646  */
    {
                                          Nodo* nodo = new Nodo("INSTRUCCIONES");
                                          nodo->AgregarHijo((yyvsp[-1].nodo));
                                          nodo->AgregarHijo((yyvsp[0].nodo));
                                          (yyval.nodo) = nodo;
                            }
#line 2119 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 543 "MainParser.y" /* yacc.c:1646  */
    {
                            Nodo* nodo = new Nodo("INSTRUCCIONES");
                            nodo->AgregarHijo((yyvsp[0].nodo));
                            (yyval.nodo) = nodo;
                            }
#line 2129 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 549 "MainParser.y" /* yacc.c:1646  */
    {YYERROR;}
#line 2135 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 551 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2145 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 556 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2155 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 561 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[0].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2165 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 566 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[0].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2175 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 571 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2185 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 576 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2195 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 581 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2205 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 586 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2215 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 591 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2225 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 596 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2235 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 602 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2245 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 607 "MainParser.y" /* yacc.c:1646  */
    { YYERROR; }
#line 2251 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 611 "MainParser.y" /* yacc.c:1646  */
    {
                  Nodo* nodo = new Nodo("DECVAR");
                  Nodo* id = new Nodo("ID");
                  Nodo* n = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                  id->AgregarHijo(n);
                  nodo->AgregarHijo(id);
                  nodo->AgregarHijo((yyvsp[0].nodo));
                  (yyval.nodo) = nodo;
                }
#line 2265 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 621 "MainParser.y" /* yacc.c:1646  */
    {
                                          Nodo* nodo = new Nodo("DECVAR");
                                          Nodo* id = new Nodo("ID");
                                          Nodo* n = new Nodo(QString::fromStdString((yyvsp[-3].st)));
                                          id->AgregarHijo(n);
                                          nodo->AgregarHijo(id);
                                          nodo->AgregarHijo((yyvsp[-2].nodo));
                                          nodo->AgregarHijo((yyvsp[0].nodo));
                                          (yyval.nodo) = nodo;
                                        }
#line 2280 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 632 "MainParser.y" /* yacc.c:1646  */
    {
                                  Nodo* nodo = new Nodo("RETORNO");
                                  nodo->AgregarHijo((yyvsp[0].nodo));
                                  (yyval.nodo) = nodo;
                                }
#line 2290 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 638 "MainParser.y" /* yacc.c:1646  */
    {
                    Nodo* nodo = new Nodo("EXPLOG");
                    Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                    nodo->AgregarHijo((yyvsp[-2].nodo));
                    nodo->AgregarHijo(op);
                    nodo->AgregarHijo((yyvsp[0].nodo));
                    (yyval.nodo) = nodo;
            }
#line 2303 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 646 "MainParser.y" /* yacc.c:1646  */
    {
                    Nodo* nodo = new Nodo("EXPLOG");
                    Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                    nodo->AgregarHijo((yyvsp[-2].nodo));
                    nodo->AgregarHijo(op);
                    nodo->AgregarHijo((yyvsp[0].nodo));
                    (yyval.nodo) = nodo;
            }
#line 2316 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 654 "MainParser.y" /* yacc.c:1646  */
    {
                Nodo* nodo = new Nodo("EXPLOG");
                Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                nodo->AgregarHijo(op);
                nodo->AgregarHijo((yyvsp[0].nodo));
                (yyval.nodo) = nodo;
            }
#line 2328 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 662 "MainParser.y" /* yacc.c:1646  */
    {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2334 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 664 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2347 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 672 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2360 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 680 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2373 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 688 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2386 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 696 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2399 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 704 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2412 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 712 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2425 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 720 "MainParser.y" /* yacc.c:1646  */
    {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2431 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 722 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPMAT");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2444 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 730 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPMAT");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2457 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 738 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPMAT");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2470 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 746 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPMAT");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2483 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 754 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPMAT");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2496 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 762 "MainParser.y" /* yacc.c:1646  */
    {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2502 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 764 "MainParser.y" /* yacc.c:1646  */
    {(yyval.nodo) = (yyvsp[-1].nodo);}
#line 2508 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 765 "MainParser.y" /* yacc.c:1646  */
    {
                      Nodo* nodo = new Nodo("ID");
                      Nodo* id = new Nodo(QString::fromStdString((yyvsp[0].st)));
                      nodo->AgregarHijo(id);
                      (yyval.nodo) = nodo;
                    }
#line 2519 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 771 "MainParser.y" /* yacc.c:1646  */
    {
                      Nodo* nodo = new Nodo("NUM");
                      Nodo* num = new Nodo(QString::fromStdString((yyvsp[0].st)));
                      nodo->AgregarHijo(num);
                      (yyval.nodo) = nodo;
                    }
#line 2530 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 777 "MainParser.y" /* yacc.c:1646  */
    {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2536 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 778 "MainParser.y" /* yacc.c:1646  */
    {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2542 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 779 "MainParser.y" /* yacc.c:1646  */
    {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2548 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 781 "MainParser.y" /* yacc.c:1646  */
    {
                                                                                                                                  Nodo* nodo = new Nodo("IF");
                                                                                                                                  Nodo* cond = new Nodo("COND");
                                                                                                                                  cond->AgregarHijo((yyvsp[-4].nodo));
                                                                                                                                  nodo->AgregarHijo(cond);
                                                                                                                                  nodo->AgregarHijo((yyvsp[-1].nodo));
                                                                                                                                  (yyval.nodo) = nodo;
                                                                                                                                  }
#line 2561 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 789 "MainParser.y" /* yacc.c:1646  */
    {
                                                                                                                                  Nodo* nodo = new Nodo("IF");
                                                                                                                                  Nodo* cond = new Nodo("COND");
                                                                                                                                  cond->AgregarHijo((yyvsp[-5].nodo));
                                                                                                                                  nodo->AgregarHijo(cond);
                                                                                                                                  nodo->AgregarHijo((yyvsp[-2].nodo));
                                                                                                                                  nodo->AgregarHijo((yyvsp[0].nodo));
                                                                                                                                  (yyval.nodo) = nodo;
                                                                                                                                  }
#line 2575 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 798 "MainParser.y" /* yacc.c:1646  */
    {
                                                                                                                                  Nodo* nodo = new Nodo("IF");
                                                                                                                                  Nodo* cond = new Nodo("COND");
                                                                                                                                  cond->AgregarHijo((yyvsp[-6].nodo));
                                                                                                                                  nodo->AgregarHijo(cond);
                                                                                                                                  nodo->AgregarHijo((yyvsp[-3].nodo));
                                                                                                                                  nodo->AgregarHijo((yyvsp[-1].nodo));
                                                                                                                                  nodo->AgregarHijo((yyvsp[0].nodo));
                                                                                                                                  (yyval.nodo) = nodo;
                                                                                                                                  }
#line 2590 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 809 "MainParser.y" /* yacc.c:1646  */
    {
                                                        Nodo* nodo = new Nodo("ELSE");
                                                        nodo->AgregarHijo((yyvsp[-1].nodo));
                                                        (yyval.nodo) = nodo;
                                                    }
#line 2600 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 815 "MainParser.y" /* yacc.c:1646  */
    {
                                  Nodo* nodo = new Nodo("ELSEIFLIST");
                                  nodo->AgregarHijo((yyvsp[-1].nodo));
                                  nodo->AgregarHijo((yyvsp[0].nodo));
                                  (yyval.nodo) = nodo;
                      }
#line 2611 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 821 "MainParser.y" /* yacc.c:1646  */
    {
                      Nodo* nodo = new Nodo("ELSEIFLIST");
                      nodo->AgregarHijo((yyvsp[0].nodo));
                      (yyval.nodo) = nodo;
                      }
#line 2621 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 827 "MainParser.y" /* yacc.c:1646  */
    {
                                                                              Nodo* nodo = new Nodo("ELSEIF");
                                                                              Nodo* cond = new Nodo("COND");
                                                                              cond->AgregarHijo((yyvsp[-4].nodo));
                                                                              nodo->AgregarHijo(cond);
                                                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                                                              (yyval.nodo) = nodo;
                                                                            }
#line 2634 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 836 "MainParser.y" /* yacc.c:1646  */
    {Nodo* nodo = new Nodo("DETENER");
                            (yyval.nodo) = nodo;
                          }
#line 2642 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 841 "MainParser.y" /* yacc.c:1646  */
    {
                                                                                      Nodo* nodo = new Nodo("CICLO");
                                                                                      Nodo* cond = new Nodo("COND");
                                                                                      cond->AgregarHijo((yyvsp[-4].nodo));
                                                                                      nodo->AgregarHijo(cond);
                                                                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                                                                      (yyval.nodo) = nodo;
                                                                                    }
#line 2655 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 850 "MainParser.y" /* yacc.c:1646  */
    {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              Nodo* id = new Nodo("ID");
                                              Nodo* n = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                              id->AgregarHijo(n);
                                              Nodo* op = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                              nodo->AgregarHijo(id);
                                              nodo->AgregarHijo(op);
                                              (yyval.nodo) = nodo;
                                            }
#line 2670 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 860 "MainParser.y" /* yacc.c:1646  */
    {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              Nodo* id = new Nodo("ID");
                                              Nodo* n = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                              id->AgregarHijo(n);
                                              Nodo* op = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                              nodo->AgregarHijo(id);
                                              nodo->AgregarHijo(op);
                                              (yyval.nodo) = nodo;
                                            }
#line 2685 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 870 "MainParser.y" /* yacc.c:1646  */
    {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              Nodo* id = new Nodo("ID");
                                              Nodo* n = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                              id->AgregarHijo(n);
                                              Nodo* op = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                              nodo->AgregarHijo(id);
                                              nodo->AgregarHijo(op);
                                              (yyval.nodo) = nodo;
                                            }
#line 2700 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 880 "MainParser.y" /* yacc.c:1646  */
    {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              Nodo* id = new Nodo("ID");
                                              Nodo* n = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                              id->AgregarHijo(n);
                                              Nodo* op = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                              nodo->AgregarHijo(id);
                                              nodo->AgregarHijo(op);
                                              (yyval.nodo) = nodo;
                                            }
#line 2715 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 890 "MainParser.y" /* yacc.c:1646  */
    {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                              Nodo* op = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                              nodo->AgregarHijo(op);
                                              (yyval.nodo) = nodo;
                                            }
#line 2727 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 897 "MainParser.y" /* yacc.c:1646  */
    {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                              Nodo* op = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                              nodo->AgregarHijo(op);
                                              (yyval.nodo) = nodo;
                                            }
#line 2739 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 904 "MainParser.y" /* yacc.c:1646  */
    {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                              Nodo* op = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                              nodo->AgregarHijo(op);
                                              (yyval.nodo) = nodo;
                                            }
#line 2751 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 911 "MainParser.y" /* yacc.c:1646  */
    {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                              Nodo* op = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                              nodo->AgregarHijo(op);
                                              (yyval.nodo) = nodo;
                                            }
#line 2763 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 919 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("DECARRVAR");
                                Nodo* id = new Nodo("ID");
                                Nodo* n = new Nodo(QString::fromStdString((yyvsp[-2].st)));
                                id->AgregarHijo(n);
                                nodo->AgregarHijo(id);
                                nodo->AgregarHijo((yyvsp[-1].nodo));
                                nodo->AgregarHijo((yyvsp[0].nodo));
                                (yyval.nodo) = nodo;
                              }
#line 2778 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 929 "MainParser.y" /* yacc.c:1646  */
    {
                                                      Nodo* nodo = new Nodo("DECARRVAR");
                                                      Nodo* id = new Nodo("ID");
                                                      Nodo* n = new Nodo(QString::fromStdString((yyvsp[-4].st)));
                                                      id->AgregarHijo(n);
                                                      nodo->AgregarHijo(id);
                                                      nodo->AgregarHijo((yyvsp[-3].nodo));
                                                      nodo->AgregarHijo((yyvsp[-2].nodo));
                                                      nodo->AgregarHijo((yyvsp[0].nodo));
                                                      (yyval.nodo) = nodo;
                                                    }
#line 2794 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 941 "MainParser.y" /* yacc.c:1646  */
    {
                      Nodo* nodo = new Nodo("ASIGNACION");
                      nodo->AgregarHijo((yyvsp[0].nodo));
                      (yyval.nodo) = nodo;
                    }
#line 2804 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 946 "MainParser.y" /* yacc.c:1646  */
    {
              Nodo* nodo = new Nodo("ASIGNACION");
              nodo->AgregarHijo((yyvsp[0].nodo));
              (yyval.nodo) = nodo;
            }
#line 2814 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 953 "MainParser.y" /* yacc.c:1646  */
    {
                        Nodo* nodo = new Nodo("VALOR");
                        Nodo* n1 = new Nodo("CADENA");
                        Nodo* n1h = new Nodo(QString::fromStdString((yyvsp[0].st)));
                        n1->AgregarHijo(n1h);
                        nodo->AgregarHijo(n1);
                        (yyval.nodo) = nodo;
                        }
#line 2827 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 961 "MainParser.y" /* yacc.c:1646  */
    {
                        Nodo* nodo = new Nodo("VALOR");
                        Nodo* n1 = new Nodo("CHAR");
                        Nodo* n1h = new Nodo(QString::fromStdString((yyvsp[0].st)));
                        n1->AgregarHijo(n1h);
                        nodo->AgregarHijo(n1);
                        (yyval.nodo) = nodo;
                        }
#line 2840 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 969 "MainParser.y" /* yacc.c:1646  */
    {
                    Nodo* nodo = new Nodo("VALOR");
                    nodo->AgregarHijo((yyvsp[0].nodo));
                    (yyval.nodo) = nodo;
                  }
#line 2850 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 974 "MainParser.y" /* yacc.c:1646  */
    {
                        Nodo* nodo = new Nodo("VALOR");
                        nodo->AgregarHijo((yyvsp[0].nodo));
                        (yyval.nodo) = nodo;
                      }
#line 2860 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 979 "MainParser.y" /* yacc.c:1646  */
    {
                  Nodo* nodo = new Nodo("VALOR");
                  nodo->AgregarHijo((yyvsp[0].nodo));
                  (yyval.nodo) = nodo;
                }
#line 2870 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 986 "MainParser.y" /* yacc.c:1646  */
    {
                                              Nodo* nodo = new Nodo("INICIAR_ARR");
                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                              (yyval.nodo) = nodo;
                                            }
#line 2880 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 991 "MainParser.y" /* yacc.c:1646  */
    {
                                              Nodo* nodo = new Nodo("INICIAR_ARR");
                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                              (yyval.nodo) = nodo;
                                            }
#line 2890 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 997 "MainParser.y" /* yacc.c:1646  */
    {
                                                    Nodo* nodo = new Nodo("LISTA_ASIG_ARR");
                                                    nodo->AgregarHijo((yyvsp[-2].nodo));
                                                    nodo->AgregarHijo((yyvsp[0].nodo));
                                                    (yyval.nodo) = nodo;
                                                  }
#line 2901 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1003 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("LISTA_ASIG_ARR");
                                nodo->AgregarHijo((yyvsp[0].nodo));
                                (yyval.nodo) = nodo;
                              }
#line 2911 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1009 "MainParser.y" /* yacc.c:1646  */
    {
                                            Nodo* nodo = new Nodo("ASIGLIST");
                                            nodo->AgregarHijo((yyvsp[-2].nodo));
                                            nodo->AgregarHijo((yyvsp[0].nodo));
                                            (yyval.nodo) = nodo;
                                          }
#line 2922 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1015 "MainParser.y" /* yacc.c:1646  */
    {
                              Nodo* nodo = new Nodo("ASIGLIST");
                              nodo->AgregarHijo((yyvsp[0].nodo));
                              (yyval.nodo) = nodo;
                            }
#line 2932 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1021 "MainParser.y" /* yacc.c:1646  */
    {
                              Nodo* nodo = new Nodo("ARR_ACCESO");
                              Nodo* n1 = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                              nodo->AgregarHijo(n1);
                              nodo->AgregarHijo((yyvsp[0].nodo));
                              (yyval.nodo) = nodo;
                            }
#line 2944 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1029 "MainParser.y" /* yacc.c:1646  */
    {
                                                Nodo* nodo = new Nodo("ASIG_ARR");
                                                nodo->AgregarHijo((yyvsp[-2].nodo));
                                                nodo->AgregarHijo((yyvsp[0].nodo));
                                                (yyval.nodo) = nodo;
                                              }
#line 2955 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1036 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("VAR_ASIG");
                                        Nodo* n1 = new Nodo(QString::fromStdString((yyvsp[-2].st)));
                                        nodo->AgregarHijo(n1);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2967 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1047 "MainParser.y" /* yacc.c:1646  */
    {
                          Nodo* nodo = new Nodo("FUNCALL");
                          nodo->AgregarHijo((yyvsp[0].nodo));
                          (yyval.nodo) = nodo;
                            }
#line 2977 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1052 "MainParser.y" /* yacc.c:1646  */
    {
                              Nodo* nodo = new Nodo("FUNCALL");
                              nodo->AgregarHijo((yyvsp[0].nodo));
                              (yyval.nodo) = nodo;
                            }
#line 2987 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1057 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("FUNCALL");
                                Nodo* n1 = new Nodo(QString::fromStdString((yyvsp[-2].st)));
                                nodo->AgregarHijo(n1);
                                (yyval.nodo) = nodo;
                              }
#line 2998 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1063 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("FUNCALL");
                                        Nodo* n1 = new Nodo(QString::fromStdString((yyvsp[-3].st)));
                                        nodo->AgregarHijo(n1);
                                        nodo->AgregarHijo((yyvsp[-1].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 3010 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1071 "MainParser.y" /* yacc.c:1646  */
    {
                                                  Nodo* nodo = new Nodo("IMPRIMIR");
                                                  nodo->AgregarHijo((yyvsp[-1].nodo));
                                                  (yyval.nodo) = nodo;
                                              }
#line 3020 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1078 "MainParser.y" /* yacc.c:1646  */
    {
                                                            Nodo* nodo = new Nodo("INSTANCIAR");
                                                            Nodo* constructor = new Nodo(QString::fromStdString((yyvsp[-3].st)));
                                                            nodo->AgregarHijo(constructor);
                                                            nodo->AgregarHijo((yyvsp[-1].nodo));
                                                            (yyval.nodo) = nodo;
                                                      }
#line 3032 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1086 "MainParser.y" /* yacc.c:1646  */
    {
                                                                Nodo* nodo = new Nodo("INSTANCIAR");
                                                                Nodo* constructor = new Nodo(QString::fromStdString((yyvsp[-2].st)));
                                                                nodo->AgregarHijo(constructor);
                                                                (yyval.nodo) = nodo;
                                                              }
#line 3043 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1093 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("PARAMS");
                                nodo->AgregarHijo((yyvsp[-2].nodo));
                                nodo->AgregarHijo((yyvsp[0].nodo));
                                (yyval.nodo) = nodo;
                              }
#line 3054 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1100 "MainParser.y" /* yacc.c:1646  */
    {
                    Nodo* nodo = new Nodo("PARAMS");
                    nodo->AgregarHijo((yyvsp[0].nodo));
                    (yyval.nodo) = nodo;
                  }
#line 3064 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1107 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("ACCESOATRIBUTO");
                                Nodo* n1 = new Nodo(QString::fromStdString((yyvsp[-2].st)));
                                Nodo* n2 = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                nodo->AgregarHijo(n1);
                                nodo->AgregarHijo(n2);
                                (yyval.nodo) = nodo;
                              }
#line 3077 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1115 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("ACCESOATRIBUTO");
                                Nodo* n1 = new Nodo("este");
                                Nodo* n2 = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                nodo->AgregarHijo(n1);
                                nodo->AgregarHijo(n2);
                                (yyval.nodo) = nodo;
                              }
#line 3090 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1124 "MainParser.y" /* yacc.c:1646  */
    {
                                                      Nodo* nodo = new Nodo("MODIFATRIBUTO");
                                                      nodo->AgregarHijo((yyvsp[-2].nodo));
                                                      nodo->AgregarHijo((yyvsp[0].nodo));
                                                      (yyval.nodo)=nodo;
                                                    }
#line 3101 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1131 "MainParser.y" /* yacc.c:1646  */
    {
                                         Nodo* nodo = new Nodo("ACCESOMETODO");
                                         Nodo* n1 = new Nodo(QString::fromStdString((yyvsp[-4].st)));
                                         Nodo* n2 = new Nodo(QString::fromStdString((yyvsp[-2].st)));
                                         nodo->AgregarHijo(n1);
                                         nodo->AgregarHijo(n2);
                                         (yyval.nodo) = nodo;
                                         }
#line 3114 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1140 "MainParser.y" /* yacc.c:1646  */
    {
                                                Nodo* nodo = new Nodo("ACCESOMETODO");
                                                Nodo* n1 = new Nodo("este");
                                                Nodo* n2 = new Nodo(QString::fromStdString((yyvsp[-2].st)));
                                                nodo->AgregarHijo(n1);
                                                nodo->AgregarHijo(n2);
                                                (yyval.nodo) = nodo;
                                              }
#line 3127 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1149 "MainParser.y" /* yacc.c:1646  */
    {
                                                Nodo* nodo = new Nodo("ACCESOMETODO");
                                                Nodo* n1 = new Nodo(QString::fromStdString((yyvsp[-5].st)));
                                                Nodo* n2 = new Nodo(QString::fromStdString((yyvsp[-3].st)));
                                                nodo->AgregarHijo(n1);
                                                nodo->AgregarHijo(n2);
                                                nodo->AgregarHijo((yyvsp[-1].nodo));
                                                (yyval.nodo) = nodo;
                                              }
#line 3141 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1158 "MainParser.y" /* yacc.c:1646  */
    {
                                                    Nodo* nodo = new Nodo("ACCESOMETODO");
                                                    Nodo* n1 = new Nodo("este");
                                                    Nodo* n2 = new Nodo(QString::fromStdString((yyvsp[-3].st)));
                                                    nodo->AgregarHijo(n1);
                                                    nodo->AgregarHijo(n2);
                                                    nodo->AgregarHijo((yyvsp[-1].nodo));
                                                    (yyval.nodo) = nodo;
                                              }
#line 3155 "MainParser.cpp" /* yacc.c:1646  */
    break;


#line 3159 "MainParser.cpp" /* yacc.c:1646  */
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
#line 1171 "MainParser.y" /* yacc.c:1906  */


