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
  void mainparsererror(char*s);


void inicializar() {
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


void mainparsererror(const char *s) {
cout << "Error SINTACTICO en la fila: " << mainparserlineno << " y columna: " << mainparsercolno<< ": "<<mainparsertext << endl;
}



#line 120 "MainParser.cpp" /* yacc.c:339  */

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
#line 47 "MainParser.y" /* yacc.c:355  */

   #include "nodo.h"

#line 154 "MainParser.cpp" /* yacc.c:355  */

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
#line 51 "MainParser.y" /* yacc.c:355  */

char *st;
Nodo *nodo;

#line 235 "MainParser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE mainparserlval;

int mainparserparse (void);

#endif /* !YY_MAINPARSER_MAINPARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 250 "MainParser.cpp" /* yacc.c:358  */

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
#define YYLAST   563

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  271

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
       0,   200,   200,   207,   215,   222,   229,   241,   253,   259,
     265,   272,   281,   287,   293,   300,   306,   312,   317,   322,
     329,   339,   351,   362,   375,   381,   387,   393,   399,   405,
     411,   417,   423,   430,   436,   444,   456,   467,   478,   490,
     496,   502,   511,   524,   530,   536,   541,   546,   551,   556,
     561,   566,   571,   576,   581,   587,   593,   603,   614,   620,
     628,   636,   644,   646,   654,   662,   670,   678,   686,   694,
     702,   704,   712,   720,   728,   736,   744,   746,   747,   753,
     759,   760,   761,   763,   771,   780,   791,   797,   803,   809,
     818,   823,   832,   842,   852,   862,   872,   879,   886,   893,
     901,   911,   923,   928,   935,   943,   951,   956,   961,   968,
     973,   979,   985,   991,   997,  1003,  1011,  1018,  1029,  1034,
    1039,  1045,  1053,  1060,  1068,  1075,  1082,  1089,  1097,  1106,
    1113,  1122,  1131,  1140
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

#define YYPACT_NINF -157

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-157)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     150,  -157,  -157,  -157,   -10,    52,    57,  -157,    41,   150,
    -157,  -157,  -157,  -157,    79,    57,  -157,    14,   125,   -13,
      96,  -157,    57,   169,    57,   252,  -157,   138,   148,  -157,
     -13,   147,   363,   161,   167,  -157,  -157,  -157,  -157,   380,
     363,  -157,  -157,  -157,  -157,  -157,  -157,   180,   363,   363,
    -157,   179,     9,   195,   201,   279,   198,   363,   194,    27,
    -157,    11,    94,    88,  -157,   372,    25,  -157,  -157,  -157,
    -157,  -157,   214,   218,   223,   372,  -157,    -5,   500,   504,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,   189,  -157,
     499,  -157,   363,   216,    -6,   217,    45,   211,   226,   208,
     189,   236,  -157,    13,   295,   230,  -157,  -157,  -157,  -157,
     201,   357,   253,   248,  -157,   372,   372,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,  -157,
    -157,  -157,  -157,   227,   372,   265,   272,  -157,   386,  -157,
     283,   288,  -157,   289,  -157,   292,   293,   305,   294,   307,
     308,   185,   319,  -157,   499,  -157,   499,   306,   318,   320,
    -157,   264,  -157,  -157,  -157,  -157,   105,   334,   339,   310,
     343,   300,  -157,   297,   297,   297,   297,   297,   297,  -157,
     202,   202,   301,   301,   301,   279,   107,    -5,   372,   372,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,   279,  -157,  -157,
    -157,   279,  -157,   408,   421,   499,  -157,  -157,  -157,  -157,
      55,    90,  -157,   357,   326,  -157,  -157,   112,   341,  -157,
     279,   145,    17,    29,  -157,  -157,  -157,  -157,   434,  -157,
     236,  -157,   279,  -157,  -157,   123,  -157,  -157,   127,  -157,
     236,   336,   340,  -157,  -157,  -157,  -157,  -157,  -157,   499,
     499,   447,   460,   108,  -157,   358,   342,  -157,   108,  -157,
     372,   499,  -157,  -157,    38,   473,   346,  -157,   499,   486,
    -157
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,     9,    10,     0,     0,     2,     5,     0,     0,
      13,    14,     1,     4,     0,     3,    12,     0,     0,     0,
       0,    11,     0,     0,     0,     0,    16,     0,     0,    18,
       0,     0,     0,     0,     0,     6,    15,    17,    19,     0,
       0,    32,    27,    30,    29,    28,    31,     0,     0,     0,
       7,    20,     0,     0,     0,     0,     0,     0,     0,     0,
      40,     0,     0,    22,    25,     0,    78,    79,   104,   105,
      33,    34,     0,     0,     0,     0,    81,   106,    62,    70,
      76,    80,    21,   102,    82,   108,   118,   103,   107,   119,
       0,    41,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,    24,     0,     0,     0,    95,    92,    93,    94,
     115,     0,     0,     0,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
      96,    97,    98,     0,     0,     0,     0,    90,     0,    44,
       0,     0,    47,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,    39,     0,     0,     0,     0,
      26,     0,    23,    77,   120,   126,     0,   127,     0,     0,
     128,    59,    60,    63,    64,    65,    66,    67,    68,    69,
      71,    72,    73,    74,    75,     0,    56,    58,     0,     0,
      38,    43,    45,    46,    49,    50,    51,     0,    52,    53,
      54,     0,    55,     0,     0,     0,   127,   128,   114,   112,
       0,     0,   121,     0,     0,   122,   124,     0,     0,   117,
       0,   100,     0,     0,   116,   129,    36,    37,     0,   109,
       0,   110,     0,   125,   130,     0,   123,   131,     0,    57,
       0,     0,     0,    35,   111,   113,   132,   133,   101,     0,
       0,     0,     0,    83,    91,     0,     0,    84,     0,    88,
       0,     0,    85,    87,     0,     0,     0,    86,     0,     0,
      89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,   366,    24,   262,  -157,  -157,   369,   349,    -1,
    -157,  -157,   -53,   -59,   -29,  -157,  -157,   323,   299,   -25,
    -128,  -157,  -157,   -62,   435,   102,  -157,  -157,   130,  -157,
     144,  -157,  -157,   -83,  -157,  -140,  -102,  -156,  -157,  -157,
     -49,  -157,  -157,    -9,  -157,  -157,  -154,   -55,  -157,  -157
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    20,     9,    10,    25,    26,
      27,    28,   110,    64,    47,    76,    29,    59,    60,   138,
     139,   140,   141,    77,    78,    79,    80,   142,   257,   258,
     259,   143,   144,    81,   146,    82,    83,   162,   210,   211,
      84,   148,   149,   150,    86,    87,   166,   100,   152,    89
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      88,    63,   165,   103,   102,   209,    11,   145,    57,   168,
     191,    51,    22,   114,    56,   217,    95,    23,   163,    53,
      54,   208,   241,    57,    36,    57,    24,    58,    91,   104,
      13,    62,    93,    18,   242,   151,   105,    19,    36,    13,
      94,   147,    58,   266,    58,   219,    85,   115,   116,    88,
     157,   102,    12,   171,   172,   145,    88,   224,    94,    14,
     235,   225,   229,   153,   238,   115,   116,   165,   230,   115,
     116,   145,   187,   145,   244,   191,   191,     1,     2,     3,
     239,   115,   116,   151,   248,   106,   107,   108,   109,   147,
     115,   116,   245,    17,    62,    85,   101,   231,    65,   151,
     191,   151,    85,   232,   186,   147,    88,   147,    97,    67,
     212,   233,   165,    62,    88,   220,   165,   236,   213,    30,
     145,   145,   145,   191,   191,   213,   222,   223,   246,   203,
      88,   204,   247,   221,    70,    71,   213,   191,    98,    21,
     213,   191,    88,   255,   256,   145,    88,    37,   151,   151,
     151,    62,    85,   240,   147,   147,   147,    38,    88,    88,
      85,    40,   102,    88,    99,    88,   145,   145,   145,   145,
       1,     2,     3,   151,     4,    48,    85,    88,   145,   147,
     228,    49,   145,    32,    52,   145,   145,    55,    85,     1,
       2,     3,    85,   201,   151,   151,   151,   151,   264,    61,
     147,   147,   147,   147,    85,    85,   151,    62,    92,    85,
     151,    85,   147,   151,   151,   160,   147,    62,   111,   147,
     147,    90,   158,    85,   251,   252,   180,   181,   182,   183,
     184,   104,   112,    62,   113,   185,   265,   159,   105,   154,
     156,    41,   161,   269,   167,   129,   130,   131,   132,   129,
     130,   131,   132,    42,    43,    44,    45,   169,    46,   126,
     127,   128,   170,   124,   125,   126,   127,   128,    65,   188,
     161,   106,   107,   108,   109,    35,   189,    22,    66,    67,
      68,    69,    23,    65,    31,    33,    34,   106,   107,   108,
     109,    24,   192,    66,    67,    68,    69,   193,   194,    65,
     164,   195,   196,   198,    70,    71,    72,    73,    74,    66,
      67,    68,    69,   197,    65,   216,   199,   200,    75,    70,
      71,    72,    73,    74,    66,    67,    68,    69,   202,   205,
      65,   234,   206,    75,   207,    70,    71,    72,   214,    74,
      66,    67,    68,    69,   215,    65,   237,   218,   123,    75,
      70,    71,    72,   116,    74,    66,    67,    68,    69,   249,
     128,    65,   260,   250,    75,   261,    70,    71,    72,   268,
      74,    66,    67,    68,    69,    15,    65,    41,    16,    39,
      75,    70,    71,    72,    96,    74,    97,    67,   262,    42,
      43,    44,    45,   155,    46,    75,     0,    70,    71,    72,
     133,    74,   263,    50,     0,    22,     0,     0,     0,   190,
      23,    75,    70,    71,     0,     0,    98,     0,   134,    24,
     135,     0,   133,   136,   137,     0,    75,     0,    72,     0,
      74,   226,     0,     0,     0,   133,     0,     0,     0,     0,
     134,     0,   135,     0,   227,   136,   137,     0,   133,     0,
      72,     0,    74,   134,     0,   135,     0,   243,   136,   137,
       0,   133,     0,    72,     0,    74,   134,     0,   135,     0,
     253,   136,   137,     0,   133,     0,    72,     0,    74,   134,
       0,   135,     0,   254,   136,   137,     0,   133,     0,    72,
       0,    74,   134,     0,   135,     0,   267,   136,   137,     0,
     133,     0,    72,     0,    74,   134,     0,   135,     0,   270,
     136,   137,     0,   133,     0,    72,     0,    74,   134,     0,
     135,     0,     0,   136,   137,     0,     0,     0,    72,     0,
      74,   134,     0,   135,     0,     0,   136,   137,     0,     0,
       0,    72,     0,    74,     0,   117,   118,   119,   120,   121,
     122,   123,   173,   174,   175,   176,   177,   178,   179,   124,
     125,   126,   127,   128
};

static const yytype_int16 yycheck[] =
{
      55,    54,   104,    65,    63,   161,    16,    90,    14,   111,
     138,    40,    25,    75,     5,   169,     5,    30,     5,    48,
      49,   161,     5,    14,    25,    14,    39,    33,    57,     4,
       6,     6,     5,    19,     5,    90,    11,    23,    39,    15,
      13,    90,    33,     5,    33,   185,    55,    52,    53,   104,
       5,   110,     0,   115,   116,   138,   111,   197,    13,    18,
     214,   201,     7,    92,   218,    52,    53,   169,    13,    52,
      53,   154,   134,   156,   230,   203,   204,    20,    21,    22,
     220,    52,    53,   138,   240,    60,    61,    62,    63,   138,
      52,    53,   232,    14,     6,   104,     8,     7,     4,   154,
     228,   156,   111,    13,   133,   154,   161,   156,    14,    15,
       5,   213,   214,     6,   169,     8,   218,     5,    13,    23,
     203,   204,   205,   251,   252,    13,   188,   189,     5,   154,
     185,   156,     5,   186,    40,    41,    13,   265,    44,    14,
      13,   269,   197,    35,    36,   228,   201,     9,   203,   204,
     205,     6,   161,     8,   203,   204,   205,     9,   213,   214,
     169,    14,   221,   218,    62,   220,   249,   250,   251,   252,
      20,    21,    22,   228,    24,    14,   185,   232,   261,   228,
     205,    14,   265,    14,     4,   268,   269,     8,   197,    20,
      21,    22,   201,     8,   249,   250,   251,   252,   260,     4,
     249,   250,   251,   252,   213,   214,   261,     6,    14,   218,
     265,   220,   261,   268,   269,     7,   265,     6,     4,   268,
     269,    23,    11,   232,   249,   250,   124,   125,   126,   127,
     128,     4,    14,     6,    11,     8,   261,    11,    11,    23,
      23,    14,     6,   268,    14,    60,    61,    62,    63,    60,
      61,    62,    63,    26,    27,    28,    29,     4,    31,    57,
      58,    59,    14,    55,    56,    57,    58,    59,     4,     4,
       6,    60,    61,    62,    63,    23,     4,    25,    14,    15,
      16,    17,    30,     4,    22,    23,    24,    60,    61,    62,
      63,    39,     9,    14,    15,    16,    17,     9,     9,     4,
       5,     9,     9,     9,    40,    41,    42,    43,    44,    14,
      15,    16,    17,     8,     4,     5,     9,     9,    54,    40,
      41,    42,    43,    44,    14,    15,    16,    17,     9,    23,
       4,     5,    14,    54,    14,    40,    41,    42,     4,    44,
      14,    15,    16,    17,     5,     4,     5,     4,    51,    54,
      40,    41,    42,    53,    44,    14,    15,    16,    17,    23,
      59,     4,     4,    23,    54,    23,    40,    41,    42,    23,
      44,    14,    15,    16,    17,     9,     4,    14,     9,    30,
      54,    40,    41,    42,    61,    44,    14,    15,   258,    26,
      27,    28,    29,    94,    31,    54,    -1,    40,    41,    42,
      14,    44,   258,    23,    -1,    25,    -1,    -1,    -1,    23,
      30,    54,    40,    41,    -1,    -1,    44,    -1,    32,    39,
      34,    -1,    14,    37,    38,    -1,    54,    -1,    42,    -1,
      44,    23,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      32,    -1,    34,    -1,    23,    37,    38,    -1,    14,    -1,
      42,    -1,    44,    32,    -1,    34,    -1,    23,    37,    38,
      -1,    14,    -1,    42,    -1,    44,    32,    -1,    34,    -1,
      23,    37,    38,    -1,    14,    -1,    42,    -1,    44,    32,
      -1,    34,    -1,    23,    37,    38,    -1,    14,    -1,    42,
      -1,    44,    32,    -1,    34,    -1,    23,    37,    38,    -1,
      14,    -1,    42,    -1,    44,    32,    -1,    34,    -1,    23,
      37,    38,    -1,    14,    -1,    42,    -1,    44,    32,    -1,
      34,    -1,    -1,    37,    38,    -1,    -1,    -1,    42,    -1,
      44,    32,    -1,    34,    -1,    -1,    37,    38,    -1,    -1,
      -1,    42,    -1,    44,    -1,    45,    46,    47,    48,    49,
      50,    51,   117,   118,   119,   120,   121,   122,   123,    55,
      56,    57,    58,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    22,    24,    65,    66,    67,    68,    70,
      71,    16,     0,    67,    18,    66,    71,    14,    19,    23,
      69,    14,    25,    30,    39,    72,    73,    74,    75,    80,
      23,    68,    14,    68,    68,    23,    73,     9,     9,    72,
      14,    14,    26,    27,    28,    29,    31,    78,    14,    14,
      23,    78,     4,    78,    78,     8,     5,    14,    33,    81,
      82,     4,     6,    76,    77,     4,    14,    15,    16,    17,
      40,    41,    42,    43,    44,    54,    79,    87,    88,    89,
      90,    97,    99,   100,   104,   107,   108,   109,   111,   113,
      23,    78,    14,     5,    13,     5,    81,    14,    44,    89,
     111,     8,    77,    87,     4,    11,    60,    61,    62,    63,
      76,     4,    14,    11,    87,    52,    53,    45,    46,    47,
      48,    49,    50,    51,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    14,    32,    34,    37,    38,    83,    84,
      85,    86,    91,    95,    96,    97,    98,   104,   105,   106,
     107,   111,   112,    78,    23,    82,    23,     5,    11,    11,
       7,     6,   101,     5,     5,   100,   110,    14,   100,     4,
      14,    87,    87,    88,    88,    88,    88,    88,    88,    88,
      89,    89,    89,    89,    89,     8,    78,    87,     4,     4,
      23,    84,     9,     9,     9,     9,     9,     8,     9,     9,
       9,     8,     9,    83,    83,    23,    14,    14,    99,   101,
     102,   103,     5,    13,     4,     5,     5,   110,     4,    99,
       8,    76,    87,    87,    99,    99,    23,    23,    83,     7,
      13,     7,    13,   100,     5,   110,     5,     5,   110,    99,
       8,     5,     5,    23,   101,    99,     5,     5,   101,    23,
      23,    83,    83,    23,    23,    35,    36,    92,    93,    94,
       4,    23,    92,    94,    87,    83,     5,    23,    23,    83,
      23
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      68,    69,    70,    70,    71,    72,    72,    73,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    78,    78,    78,
      78,    78,    78,    79,    79,    80,    80,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    85,    85,    86,    87,
      87,    87,    87,    88,    88,    88,    88,    88,    88,    88,
      88,    89,    89,    89,    89,    89,    89,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    92,    93,    93,    94,
      95,    96,    97,    97,    97,    97,    97,    97,    97,    97,
      98,    98,    99,    99,   100,   100,   100,   100,   100,   101,
     101,   102,   102,   103,   103,   104,   105,   106,   107,   107,
     107,   107,   108,   109,   109,   110,   110,   111,   111,   112,
     113,   113,   113,   113
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     6,     7,     1,     1,
       1,     2,     2,     1,     2,     2,     1,     2,     1,     2,
       4,     6,     5,     7,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,    10,     9,     9,     8,     3,
       1,     2,     3,     2,     1,     2,     2,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     4,     2,     3,
       3,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     1,     3,     1,     1,
       1,     1,     1,     7,     8,     9,     4,     2,     1,     7,
       1,     7,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     5,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     1,     3,     1,     2,     3,     3,     1,     1,
       3,     4,     4,     5,     4,     3,     1,     3,     3,     3,
       5,     5,     6,     6
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
#line 200 "MainParser.y" /* yacc.c:1646  */
    {
                        Nodo* nodo = new Nodo("INICIO");
                        nodo->AgregarHijo((yyvsp[0].nodo));
                        GraficadorAST* ga = new GraficadorAST();
                        ga->Graficar(nodo);
                        gdc.AgregarAbol(nodo);
                      }
#line 1592 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 207 "MainParser.y" /* yacc.c:1646  */
    {
                                    Nodo* nodo = new Nodo("INICIO");
                                    nodo->AgregarHijo((yyvsp[-1].nodo));
                                    nodo->AgregarHijo((yyvsp[0].nodo));
                                    GraficadorAST* ga = new GraficadorAST();
                                    ga->Graficar(nodo);
                                    gdc.AgregarAbol(nodo);
                                  }
#line 1605 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 215 "MainParser.y" /* yacc.c:1646  */
    {
                            Nodo* nodo = new Nodo("CLASE_LIST");
                            nodo->AgregarHijo((yyvsp[-1].nodo));
                            nodo->AgregarHijo((yyvsp[0].nodo));
                            (yyval.nodo) = nodo;
                            }
#line 1616 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 222 "MainParser.y" /* yacc.c:1646  */
    {
                        Nodo* nodo = new Nodo("CLASE_LIST");
                        nodo->AgregarHijo((yyvsp[0].nodo));
                        (yyval.nodo) = nodo;
                      }
#line 1626 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 229 "MainParser.y" /* yacc.c:1646  */
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
#line 1642 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 241 "MainParser.y" /* yacc.c:1646  */
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
#line 1658 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 253 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("TIPO_ACCESO");
                                Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                nodo->AgregarHijo(val);
                                (yyval.nodo) = nodo;
                              }
#line 1669 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 259 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("TIPO_ACCESO");
                                Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                nodo->AgregarHijo(val);
                                (yyval.nodo) = nodo;
                              }
#line 1680 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 265 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("TIPO_ACCESO");
                                Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                nodo->AgregarHijo(val);
                                (yyval.nodo) = nodo;
                              }
#line 1691 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 272 "MainParser.y" /* yacc.c:1646  */
    {
                                    Nodo* nodo = new Nodo("EXTIENDE");
                                    Nodo* id = new Nodo("ID");
                                    Nodo* n = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                    id->AgregarHijo(n);
                                    nodo->AgregarHijo(id);
                                    (yyval.nodo) = nodo;
                                  }
#line 1704 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 281 "MainParser.y" /* yacc.c:1646  */
    {
                          Nodo* nodo = new Nodo("IMPORT_LIST");
                          nodo->AgregarHijo((yyvsp[-1].nodo));
                          nodo->AgregarHijo((yyvsp[0].nodo));
                          (yyval.nodo) = nodo;
                        }
#line 1715 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 287 "MainParser.y" /* yacc.c:1646  */
    {
                          Nodo* nodo = new Nodo("IMPORT_LIST");
                          nodo->AgregarHijo((yyvsp[0].nodo));
                          (yyval.nodo) = nodo;
                        }
#line 1725 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 293 "MainParser.y" /* yacc.c:1646  */
    {
                                          Nodo* nodo = new Nodo("IMPORT");
                                          Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                          nodo->AgregarHijo(val);
                                          (yyval.nodo) = nodo;
                                        }
#line 1736 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 300 "MainParser.y" /* yacc.c:1646  */
    {
                                  Nodo* nodo = new Nodo("CUERPO_CLASE");
                                  nodo->AgregarHijo((yyvsp[-1].nodo));
                                  nodo->AgregarHijo((yyvsp[0].nodo));
                                  (yyval.nodo) = nodo;
                                }
#line 1747 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 306 "MainParser.y" /* yacc.c:1646  */
    {
                                  Nodo* nodo = new Nodo("CUERPO_CLASE");
                                  nodo->AgregarHijo((yyvsp[0].nodo));
                                  (yyval.nodo) = nodo;
                                }
#line 1757 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 312 "MainParser.y" /* yacc.c:1646  */
    {
                                    Nodo* nodo = new Nodo("SENTENCIAS_CLASE");
                                    nodo->AgregarHijo((yyvsp[-1].nodo));
                                    (yyval.nodo) = nodo;
                                  }
#line 1767 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 317 "MainParser.y" /* yacc.c:1646  */
    {
                                    Nodo* nodo = new Nodo("SENTENCIAS_CLASE");
                                    nodo->AgregarHijo((yyvsp[0].nodo));
                                    (yyval.nodo) = nodo;
                                  }
#line 1777 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 322 "MainParser.y" /* yacc.c:1646  */
    {
                                    Nodo* nodo = new Nodo("SENTENCIAS_CLASE");
                                    nodo->AgregarHijo((yyvsp[-1].nodo));
                                    (yyval.nodo) = nodo;
                                  }
#line 1787 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 329 "MainParser.y" /* yacc.c:1646  */
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
#line 1802 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 339 "MainParser.y" /* yacc.c:1646  */
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
#line 1818 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 351 "MainParser.y" /* yacc.c:1646  */
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
#line 1834 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 362 "MainParser.y" /* yacc.c:1646  */
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
#line 1851 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 375 "MainParser.y" /* yacc.c:1646  */
    {
                          Nodo* nodo = new Nodo("DIMLIST");
                          nodo->AgregarHijo((yyvsp[-1].nodo));
                          nodo->AgregarHijo((yyvsp[0].nodo));
                          (yyval.nodo) = nodo;
                        }
#line 1862 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 381 "MainParser.y" /* yacc.c:1646  */
    {
                  Nodo* nodo = new Nodo("DIMLIST");
                  nodo->AgregarHijo((yyvsp[0].nodo));
                  (yyval.nodo) = nodo;
                }
#line 1872 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 387 "MainParser.y" /* yacc.c:1646  */
    {
                                    Nodo* nodo = new Nodo("DIM");
                                    nodo->AgregarHijo((yyvsp[-1].nodo));
                                    (yyval.nodo) = nodo;
                                    }
#line 1882 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 393 "MainParser.y" /* yacc.c:1646  */
    {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
            nodo->AgregarHijo(val);
            (yyval.nodo) = nodo;
          }
#line 1893 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 399 "MainParser.y" /* yacc.c:1646  */
    {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
            nodo->AgregarHijo(val);
            (yyval.nodo) = nodo;
          }
#line 1904 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 405 "MainParser.y" /* yacc.c:1646  */
    {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
            nodo->AgregarHijo(val);
            (yyval.nodo) = nodo;
          }
#line 1915 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 411 "MainParser.y" /* yacc.c:1646  */
    {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
            nodo->AgregarHijo(val);
            (yyval.nodo) = nodo;
          }
#line 1926 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 417 "MainParser.y" /* yacc.c:1646  */
    {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
            nodo->AgregarHijo(val);
            (yyval.nodo) = nodo;
          }
#line 1937 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 423 "MainParser.y" /* yacc.c:1646  */
    {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString((yyvsp[0].st)));
            nodo->AgregarHijo(val);
            (yyval.nodo) = nodo;
          }
#line 1948 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 430 "MainParser.y" /* yacc.c:1646  */
    {
                  Nodo* nodo = new Nodo("BOOL");
                  Nodo* val = new Nodo("true");
                  nodo->AgregarHijo(val);
                  (yyval.nodo) = nodo;
                }
#line 1959 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 436 "MainParser.y" /* yacc.c:1646  */
    {
                  Nodo* nodo = new Nodo("BOOL");
                  Nodo* val = new Nodo("false");
                  nodo->AgregarHijo(val);
                  (yyval.nodo) = nodo;
                }
#line 1970 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 444 "MainParser.y" /* yacc.c:1646  */
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
#line 1987 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 456 "MainParser.y" /* yacc.c:1646  */
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
#line 2003 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 467 "MainParser.y" /* yacc.c:1646  */
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
#line 2019 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 478 "MainParser.y" /* yacc.c:1646  */
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
#line 2034 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 490 "MainParser.y" /* yacc.c:1646  */
    {
                                    Nodo* nodo = new Nodo("PARAMLIST");
                                    nodo->AgregarHijo((yyvsp[-2].nodo));
                                    nodo->AgregarHijo((yyvsp[0].nodo));
                                    (yyval.nodo) = nodo;
                                  }
#line 2045 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 496 "MainParser.y" /* yacc.c:1646  */
    {
                    Nodo* nodo = new Nodo("PARAMLIST");
                    nodo->AgregarHijo((yyvsp[0].nodo));
                    (yyval.nodo) = nodo;
          }
#line 2055 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 502 "MainParser.y" /* yacc.c:1646  */
    {
                    Nodo* nodo = new Nodo("PARAM");
                    Nodo* id = new Nodo("ID");
                    Nodo* n = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                    id->AgregarHijo(n);
                    nodo->AgregarHijo(id);
                    nodo->AgregarHijo((yyvsp[0].nodo));
                    (yyval.nodo) = nodo;
                  }
#line 2069 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 511 "MainParser.y" /* yacc.c:1646  */
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
#line 2085 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 524 "MainParser.y" /* yacc.c:1646  */
    {
                                          Nodo* nodo = new Nodo("INSTRUCCIONES");
                                          nodo->AgregarHijo((yyvsp[-1].nodo));
                                          nodo->AgregarHijo((yyvsp[0].nodo));
                                          (yyval.nodo) = nodo;
                            }
#line 2096 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 530 "MainParser.y" /* yacc.c:1646  */
    {
                            Nodo* nodo = new Nodo("INSTRUCCIONES");
                            nodo->AgregarHijo((yyvsp[0].nodo));
                            (yyval.nodo) = nodo;
                            }
#line 2106 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 536 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2116 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 541 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2126 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 546 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[0].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2136 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 551 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[0].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2146 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 556 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2156 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 561 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2166 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 566 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2176 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 571 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2186 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 576 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2196 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 581 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2206 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 587 "MainParser.y" /* yacc.c:1646  */
    {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                      (yyval.nodo) = nodo;
                                    }
#line 2216 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 593 "MainParser.y" /* yacc.c:1646  */
    {
                  Nodo* nodo = new Nodo("DECVAR");
                  Nodo* id = new Nodo("ID");
                  Nodo* n = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                  id->AgregarHijo(n);
                  nodo->AgregarHijo(id);
                  nodo->AgregarHijo((yyvsp[0].nodo));
                  (yyval.nodo) = nodo;
                }
#line 2230 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 603 "MainParser.y" /* yacc.c:1646  */
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
#line 2245 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 614 "MainParser.y" /* yacc.c:1646  */
    {
                                  Nodo* nodo = new Nodo("RETORNO");
                                  nodo->AgregarHijo((yyvsp[0].nodo));
                                  (yyval.nodo) = nodo;
                                }
#line 2255 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 620 "MainParser.y" /* yacc.c:1646  */
    {
                    Nodo* nodo = new Nodo("EXPLOG");
                    Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                    nodo->AgregarHijo((yyvsp[-2].nodo));
                    nodo->AgregarHijo(op);
                    nodo->AgregarHijo((yyvsp[0].nodo));
                    (yyval.nodo) = nodo;
            }
#line 2268 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 628 "MainParser.y" /* yacc.c:1646  */
    {
                    Nodo* nodo = new Nodo("EXPLOG");
                    Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                    nodo->AgregarHijo((yyvsp[-2].nodo));
                    nodo->AgregarHijo(op);
                    nodo->AgregarHijo((yyvsp[0].nodo));
                    (yyval.nodo) = nodo;
            }
#line 2281 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 636 "MainParser.y" /* yacc.c:1646  */
    {
                Nodo* nodo = new Nodo("EXPLOG");
                Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                nodo->AgregarHijo(op);
                nodo->AgregarHijo((yyvsp[0].nodo));
                (yyval.nodo) = nodo;
            }
#line 2293 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 644 "MainParser.y" /* yacc.c:1646  */
    {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2299 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 646 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2312 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 654 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2325 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 662 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2338 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 670 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2351 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 678 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2364 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 686 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2377 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 694 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2390 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 702 "MainParser.y" /* yacc.c:1646  */
    {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2396 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 704 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPMAT");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2409 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 712 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPMAT");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2422 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 720 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPMAT");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2435 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 728 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPMAT");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2448 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 736 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("EXPMAT");
                                        Nodo* op = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                                        nodo->AgregarHijo((yyvsp[-2].nodo));
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2461 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 744 "MainParser.y" /* yacc.c:1646  */
    {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2467 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 746 "MainParser.y" /* yacc.c:1646  */
    {(yyval.nodo) = (yyvsp[-1].nodo);}
#line 2473 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 747 "MainParser.y" /* yacc.c:1646  */
    {
                      Nodo* nodo = new Nodo("ID");
                      Nodo* id = new Nodo(QString::fromStdString((yyvsp[0].st)));
                      nodo->AgregarHijo(id);
                      (yyval.nodo) = nodo;
                    }
#line 2484 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 753 "MainParser.y" /* yacc.c:1646  */
    {
                      Nodo* nodo = new Nodo("NUM");
                      Nodo* num = new Nodo(QString::fromStdString((yyvsp[0].st)));
                      nodo->AgregarHijo(num);
                      (yyval.nodo) = nodo;
                    }
#line 2495 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 759 "MainParser.y" /* yacc.c:1646  */
    {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2501 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 760 "MainParser.y" /* yacc.c:1646  */
    {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2507 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 761 "MainParser.y" /* yacc.c:1646  */
    {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2513 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 763 "MainParser.y" /* yacc.c:1646  */
    {
                                                                                                                                  Nodo* nodo = new Nodo("IF");
                                                                                                                                  Nodo* cond = new Nodo("COND");
                                                                                                                                  cond->AgregarHijo((yyvsp[-4].nodo));
                                                                                                                                  nodo->AgregarHijo(cond);
                                                                                                                                  nodo->AgregarHijo((yyvsp[-1].nodo));
                                                                                                                                  (yyval.nodo) = nodo;
                                                                                                                                  }
#line 2526 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 771 "MainParser.y" /* yacc.c:1646  */
    {
                                                                                                                                  Nodo* nodo = new Nodo("IF");
                                                                                                                                  Nodo* cond = new Nodo("COND");
                                                                                                                                  cond->AgregarHijo((yyvsp[-5].nodo));
                                                                                                                                  nodo->AgregarHijo(cond);
                                                                                                                                  nodo->AgregarHijo((yyvsp[-2].nodo));
                                                                                                                                  nodo->AgregarHijo((yyvsp[0].nodo));
                                                                                                                                  (yyval.nodo) = nodo;
                                                                                                                                  }
#line 2540 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 780 "MainParser.y" /* yacc.c:1646  */
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
#line 2555 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 791 "MainParser.y" /* yacc.c:1646  */
    {
                                                        Nodo* nodo = new Nodo("ELSE");
                                                        nodo->AgregarHijo((yyvsp[-1].nodo));
                                                        (yyval.nodo) = nodo;
                                                    }
#line 2565 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 797 "MainParser.y" /* yacc.c:1646  */
    {
                                  Nodo* nodo = new Nodo("ELSEIFLIST");
                                  nodo->AgregarHijo((yyvsp[-1].nodo));
                                  nodo->AgregarHijo((yyvsp[0].nodo));
                                  (yyval.nodo) = nodo;
                      }
#line 2576 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 803 "MainParser.y" /* yacc.c:1646  */
    {
                      Nodo* nodo = new Nodo("ELSEIFLIST");
                      nodo->AgregarHijo((yyvsp[0].nodo));
                      (yyval.nodo) = nodo;
                      }
#line 2586 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 809 "MainParser.y" /* yacc.c:1646  */
    {
                                                                              Nodo* nodo = new Nodo("ELSEIF");
                                                                              Nodo* cond = new Nodo("COND");
                                                                              cond->AgregarHijo((yyvsp[-4].nodo));
                                                                              nodo->AgregarHijo(cond);
                                                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                                                              (yyval.nodo) = nodo;
                                                                            }
#line 2599 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 818 "MainParser.y" /* yacc.c:1646  */
    {Nodo* nodo = new Nodo("DETENER");
                            (yyval.nodo) = nodo;
                          }
#line 2607 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 823 "MainParser.y" /* yacc.c:1646  */
    {
                                                                                      Nodo* nodo = new Nodo("CICLO");
                                                                                      Nodo* cond = new Nodo("COND");
                                                                                      cond->AgregarHijo((yyvsp[-4].nodo));
                                                                                      nodo->AgregarHijo(cond);
                                                                                      nodo->AgregarHijo((yyvsp[-1].nodo));
                                                                                      (yyval.nodo) = nodo;
                                                                                    }
#line 2620 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 832 "MainParser.y" /* yacc.c:1646  */
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
#line 2635 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 842 "MainParser.y" /* yacc.c:1646  */
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
#line 2650 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 852 "MainParser.y" /* yacc.c:1646  */
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
#line 2665 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 862 "MainParser.y" /* yacc.c:1646  */
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
#line 2680 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 872 "MainParser.y" /* yacc.c:1646  */
    {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                              Nodo* op = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                              nodo->AgregarHijo(op);
                                              (yyval.nodo) = nodo;
                                            }
#line 2692 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 879 "MainParser.y" /* yacc.c:1646  */
    {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                              Nodo* op = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                              nodo->AgregarHijo(op);
                                              (yyval.nodo) = nodo;
                                            }
#line 2704 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 886 "MainParser.y" /* yacc.c:1646  */
    {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                              Nodo* op = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                              nodo->AgregarHijo(op);
                                              (yyval.nodo) = nodo;
                                            }
#line 2716 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 893 "MainParser.y" /* yacc.c:1646  */
    {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                              Nodo* op = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                              nodo->AgregarHijo(op);
                                              (yyval.nodo) = nodo;
                                            }
#line 2728 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 901 "MainParser.y" /* yacc.c:1646  */
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
#line 2743 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 911 "MainParser.y" /* yacc.c:1646  */
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
#line 2759 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 923 "MainParser.y" /* yacc.c:1646  */
    {
                      Nodo* nodo = new Nodo("ASIGNACION");
                      nodo->AgregarHijo((yyvsp[0].nodo));
                      (yyval.nodo) = nodo;
                    }
#line 2769 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 928 "MainParser.y" /* yacc.c:1646  */
    {
              Nodo* nodo = new Nodo("ASIGNACION");
              nodo->AgregarHijo((yyvsp[0].nodo));
              (yyval.nodo) = nodo;
            }
#line 2779 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 935 "MainParser.y" /* yacc.c:1646  */
    {
                        Nodo* nodo = new Nodo("VALOR");
                        Nodo* n1 = new Nodo("CADENA");
                        Nodo* n1h = new Nodo(QString::fromStdString((yyvsp[0].st)));
                        n1->AgregarHijo(n1h);
                        nodo->AgregarHijo(n1);
                        (yyval.nodo) = nodo;
                        }
#line 2792 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 943 "MainParser.y" /* yacc.c:1646  */
    {
                        Nodo* nodo = new Nodo("VALOR");
                        Nodo* n1 = new Nodo("CHAR");
                        Nodo* n1h = new Nodo(QString::fromStdString((yyvsp[0].st)));
                        n1->AgregarHijo(n1h);
                        nodo->AgregarHijo(n1);
                        (yyval.nodo) = nodo;
                        }
#line 2805 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 951 "MainParser.y" /* yacc.c:1646  */
    {
                    Nodo* nodo = new Nodo("VALOR");
                    nodo->AgregarHijo((yyvsp[0].nodo));
                    (yyval.nodo) = nodo;
                  }
#line 2815 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 956 "MainParser.y" /* yacc.c:1646  */
    {
                        Nodo* nodo = new Nodo("VALOR");
                        nodo->AgregarHijo((yyvsp[0].nodo));
                        (yyval.nodo) = nodo;
                      }
#line 2825 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 961 "MainParser.y" /* yacc.c:1646  */
    {
                  Nodo* nodo = new Nodo("VALOR");
                  nodo->AgregarHijo((yyvsp[0].nodo));
                  (yyval.nodo) = nodo;
                }
#line 2835 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 968 "MainParser.y" /* yacc.c:1646  */
    {
                                              Nodo* nodo = new Nodo("INICIAR_ARR");
                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                              (yyval.nodo) = nodo;
                                            }
#line 2845 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 973 "MainParser.y" /* yacc.c:1646  */
    {
                                              Nodo* nodo = new Nodo("INICIAR_ARR");
                                              nodo->AgregarHijo((yyvsp[-1].nodo));
                                              (yyval.nodo) = nodo;
                                            }
#line 2855 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 979 "MainParser.y" /* yacc.c:1646  */
    {
                                                    Nodo* nodo = new Nodo("LISTA_ASIG_ARR");
                                                    nodo->AgregarHijo((yyvsp[-2].nodo));
                                                    nodo->AgregarHijo((yyvsp[0].nodo));
                                                    (yyval.nodo) = nodo;
                                                  }
#line 2866 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 985 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("LISTA_ASIG_ARR");
                                nodo->AgregarHijo((yyvsp[0].nodo));
                                (yyval.nodo) = nodo;
                              }
#line 2876 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 991 "MainParser.y" /* yacc.c:1646  */
    {
                                            Nodo* nodo = new Nodo("ASIGLIST");
                                            nodo->AgregarHijo((yyvsp[-2].nodo));
                                            nodo->AgregarHijo((yyvsp[0].nodo));
                                            (yyval.nodo) = nodo;
                                          }
#line 2887 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 997 "MainParser.y" /* yacc.c:1646  */
    {
                              Nodo* nodo = new Nodo("ASIGLIST");
                              nodo->AgregarHijo((yyvsp[0].nodo));
                              (yyval.nodo) = nodo;
                            }
#line 2897 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1003 "MainParser.y" /* yacc.c:1646  */
    {
                              Nodo* nodo = new Nodo("ARR_ACCESO");
                              Nodo* n1 = new Nodo(QString::fromStdString((yyvsp[-1].st)));
                              nodo->AgregarHijo(n1);
                              nodo->AgregarHijo((yyvsp[0].nodo));
                              (yyval.nodo) = nodo;
                            }
#line 2909 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1011 "MainParser.y" /* yacc.c:1646  */
    {
                                                Nodo* nodo = new Nodo("ASIG_ARR");
                                                nodo->AgregarHijo((yyvsp[-2].nodo));
                                                nodo->AgregarHijo((yyvsp[0].nodo));
                                                (yyval.nodo) = nodo;
                                              }
#line 2920 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1018 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("VAR_ASIG");
                                        Nodo* n1 = new Nodo(QString::fromStdString((yyvsp[-2].st)));
                                        nodo->AgregarHijo(n1);
                                        nodo->AgregarHijo((yyvsp[0].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2932 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1029 "MainParser.y" /* yacc.c:1646  */
    {
                          Nodo* nodo = new Nodo("FUNCALL");
                          nodo->AgregarHijo((yyvsp[0].nodo));
                          (yyval.nodo) = nodo;
                            }
#line 2942 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1034 "MainParser.y" /* yacc.c:1646  */
    {
                              Nodo* nodo = new Nodo("FUNCALL");
                              nodo->AgregarHijo((yyvsp[0].nodo));
                              (yyval.nodo) = nodo;
                            }
#line 2952 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1039 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("FUNCALL");
                                Nodo* n1 = new Nodo(QString::fromStdString((yyvsp[-2].st)));
                                nodo->AgregarHijo(n1);
                                (yyval.nodo) = nodo;
                              }
#line 2963 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1045 "MainParser.y" /* yacc.c:1646  */
    {
                                        Nodo* nodo = new Nodo("FUNCALL");
                                        Nodo* n1 = new Nodo(QString::fromStdString((yyvsp[-3].st)));
                                        nodo->AgregarHijo(n1);
                                        nodo->AgregarHijo((yyvsp[-1].nodo));
                                        (yyval.nodo) = nodo;
                                      }
#line 2975 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1053 "MainParser.y" /* yacc.c:1646  */
    {
                                                  Nodo* nodo = new Nodo("IMPRIMIR");
                                                  nodo->AgregarHijo((yyvsp[-1].nodo));
                                                  (yyval.nodo) = nodo;
                                              }
#line 2985 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1060 "MainParser.y" /* yacc.c:1646  */
    {
                                                            Nodo* nodo = new Nodo("INSTANCIAR");
                                                            Nodo* constructor = new Nodo(QString::fromStdString((yyvsp[-3].st)));
                                                            nodo->AgregarHijo(constructor);
                                                            nodo->AgregarHijo((yyvsp[-1].nodo));
                                                            (yyval.nodo) = nodo;
                                                      }
#line 2997 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1068 "MainParser.y" /* yacc.c:1646  */
    {
                                                                Nodo* nodo = new Nodo("INSTANCIAR");
                                                                Nodo* constructor = new Nodo(QString::fromStdString((yyvsp[-2].st)));
                                                                nodo->AgregarHijo(constructor);
                                                                (yyval.nodo) = nodo;
                                                              }
#line 3008 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1075 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("PARAMS");
                                nodo->AgregarHijo((yyvsp[-2].nodo));
                                nodo->AgregarHijo((yyvsp[0].nodo));
                                (yyval.nodo) = nodo;
                              }
#line 3019 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1082 "MainParser.y" /* yacc.c:1646  */
    {
                    Nodo* nodo = new Nodo("PARAMS");
                    nodo->AgregarHijo((yyvsp[0].nodo));
                    (yyval.nodo) = nodo;
                  }
#line 3029 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1089 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("ACCESOATRIBUTO");
                                Nodo* n1 = new Nodo(QString::fromStdString((yyvsp[-2].st)));
                                Nodo* n2 = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                nodo->AgregarHijo(n1);
                                nodo->AgregarHijo(n2);
                                (yyval.nodo) = nodo;
                              }
#line 3042 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1097 "MainParser.y" /* yacc.c:1646  */
    {
                                Nodo* nodo = new Nodo("ACCESOATRIBUTO");
                                Nodo* n1 = new Nodo("este");
                                Nodo* n2 = new Nodo(QString::fromStdString((yyvsp[0].st)));
                                nodo->AgregarHijo(n1);
                                nodo->AgregarHijo(n2);
                                (yyval.nodo) = nodo;
                              }
#line 3055 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1106 "MainParser.y" /* yacc.c:1646  */
    {
                                                      Nodo* nodo = new Nodo("MODIFATRIBUTO");
                                                      nodo->AgregarHijo((yyvsp[-2].nodo));
                                                      nodo->AgregarHijo((yyvsp[0].nodo));
                                                      (yyval.nodo)=nodo;
                                                    }
#line 3066 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1113 "MainParser.y" /* yacc.c:1646  */
    {
                                         Nodo* nodo = new Nodo("ACCESOMETODO");
                                         Nodo* n1 = new Nodo(QString::fromStdString((yyvsp[-4].st)));
                                         Nodo* n2 = new Nodo(QString::fromStdString((yyvsp[-2].st)));
                                         nodo->AgregarHijo(n1);
                                         nodo->AgregarHijo(n2);
                                         (yyval.nodo) = nodo;
                                         }
#line 3079 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1122 "MainParser.y" /* yacc.c:1646  */
    {
                                                Nodo* nodo = new Nodo("ACCESOMETODO");
                                                Nodo* n1 = new Nodo("este");
                                                Nodo* n2 = new Nodo(QString::fromStdString((yyvsp[-2].st)));
                                                nodo->AgregarHijo(n1);
                                                nodo->AgregarHijo(n2);
                                                (yyval.nodo) = nodo;
                                              }
#line 3092 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1131 "MainParser.y" /* yacc.c:1646  */
    {
                                                Nodo* nodo = new Nodo("ACCESOMETODO");
                                                Nodo* n1 = new Nodo(QString::fromStdString((yyvsp[-5].st)));
                                                Nodo* n2 = new Nodo(QString::fromStdString((yyvsp[-3].st)));
                                                nodo->AgregarHijo(n1);
                                                nodo->AgregarHijo(n2);
                                                nodo->AgregarHijo((yyvsp[-1].nodo));
                                                (yyval.nodo) = nodo;
                                              }
#line 3106 "MainParser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1140 "MainParser.y" /* yacc.c:1646  */
    {
                                                    Nodo* nodo = new Nodo("ACCESOMETODO");
                                                    Nodo* n1 = new Nodo("este");
                                                    Nodo* n2 = new Nodo(QString::fromStdString((yyvsp[-3].st)));
                                                    nodo->AgregarHijo(n1);
                                                    nodo->AgregarHijo(n2);
                                                    nodo->AgregarHijo((yyvsp[-1].nodo));
                                                    (yyval.nodo) = nodo;
                                              }
#line 3120 "MainParser.cpp" /* yacc.c:1646  */
    break;


#line 3124 "MainParser.cpp" /* yacc.c:1646  */
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
#line 1153 "MainParser.y" /* yacc.c:1906  */


