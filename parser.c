/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arith.h"

  void yyerror(char *msg);    /* forward declaration */
  /* exported by the lexer (made with flex) */
  extern int yylex(void);
  extern char *yytext;
  extern void showErrorLine();
  extern void initLexer(FILE *f);
  extern void finalizeLexer();
  int varEnvironment = 0;
  int arrEnvironment = 0;
  int scanEnvironment = 0;
  int paramEnvironment = 0;
  int ifGuardEnv = 0;
  int whileGuardEnv = 0;
  int varParamEnv = 0;
  int functionEnv = 0;
  int procedureEnv = 0;
  int procCallEnv = 0;
  int assignmentEnv = 0;
  int assignmentArrEnv = 0;
  int functionCallEnv = 0;
  int specEnvironment = 0;
  int ifEnvironment = 0;
  int varTrue = 0;
  int lhsArrayEnv = 0;
  int temp;
  int temp2 = 0;
  int arithIntTemp;
  int arithIntTemp2;
  int intConstFlag = 0;
  int realConstFlag = 0;
  int constantInt = 0;
  int writeEnvironment = 0;
  double constantReal = 0.0;
  int intFlag = 0;
  int firstAssignmentFlag = 0;
  int lhsArrayFlag = 0;
  int rhsGuard = 0;
  int inBrackFlag = 0;
  char *tempIden;
  char* temp2Iden;
  char* temp3Iden;

#line 120 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_CONST = 4,                      /* CONST  */
  YYSYMBOL_VAR = 5,                        /* VAR  */
  YYSYMBOL_ARRAY = 6,                      /* ARRAY  */
  YYSYMBOL_RANGE = 7,                      /* RANGE  */
  YYSYMBOL_OF = 8,                         /* OF  */
  YYSYMBOL_SKIP = 9,                       /* SKIP  */
  YYSYMBOL_READLN = 10,                    /* READLN  */
  YYSYMBOL_WRITELN = 11,                   /* WRITELN  */
  YYSYMBOL_FUNCTION = 12,                  /* FUNCTION  */
  YYSYMBOL_PROCEDURE = 13,                 /* PROCEDURE  */
  YYSYMBOL_BEGINTOK = 14,                  /* BEGINTOK  */
  YYSYMBOL_ENDTOK = 15,                    /* ENDTOK  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_THEN = 18,                      /* THEN  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_DO = 21,                        /* DO  */
  YYSYMBOL_RELOPLT = 22,                   /* RELOPLT  */
  YYSYMBOL_RELOPLEQ = 23,                  /* RELOPLEQ  */
  YYSYMBOL_RELOPEQ = 24,                   /* RELOPEQ  */
  YYSYMBOL_RELOPNEQ = 25,                  /* RELOPNEQ  */
  YYSYMBOL_RELOPGEQ = 26,                  /* RELOPGEQ  */
  YYSYMBOL_RELOPGT = 27,                   /* RELOPGT  */
  YYSYMBOL_INTEGER = 28,                   /* INTEGER  */
  YYSYMBOL_REAL = 29,                      /* REAL  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_NOT = 32,                       /* NOT  */
  YYSYMBOL_DIV = 33,                       /* DIV  */
  YYSYMBOL_MOD = 34,                       /* MOD  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_IDENTIFIER = 39,                /* IDENTIFIER  */
  YYSYMBOL_REALNUMBER = 40,                /* REALNUMBER  */
  YYSYMBOL_INTNUMBER = 41,                 /* INTNUMBER  */
  YYSYMBOL_INTRANGE = 42,                  /* INTRANGE  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* '.'  */
  YYSYMBOL_45_ = 45,                       /* ':'  */
  YYSYMBOL_46_ = 46,                       /* ','  */
  YYSYMBOL_47_ = 47,                       /* '['  */
  YYSYMBOL_48_ = 48,                       /* ']'  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_program = 52,                   /* program  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_54_2 = 54,                      /* $@2  */
  YYSYMBOL_ConstDecl = 55,                 /* ConstDecl  */
  YYSYMBOL_NumericValue = 56,              /* NumericValue  */
  YYSYMBOL_VarDecl = 57,                   /* VarDecl  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_IdentifierList = 59,            /* IdentifierList  */
  YYSYMBOL_TypeSpec = 60,                  /* TypeSpec  */
  YYSYMBOL_61_4 = 61,                      /* $@4  */
  YYSYMBOL_BasicType = 62,                 /* BasicType  */
  YYSYMBOL_FuncProcDecl = 63,              /* FuncProcDecl  */
  YYSYMBOL_SubProgDecl = 64,               /* SubProgDecl  */
  YYSYMBOL_SubProgHeading = 65,            /* SubProgHeading  */
  YYSYMBOL_66_5 = 66,                      /* $@5  */
  YYSYMBOL_67_6 = 67,                      /* $@6  */
  YYSYMBOL_68_7 = 68,                      /* $@7  */
  YYSYMBOL_PossibleParameters = 69,        /* PossibleParameters  */
  YYSYMBOL_Parameters = 70,                /* Parameters  */
  YYSYMBOL_71_8 = 71,                      /* $@8  */
  YYSYMBOL_72_9 = 72,                      /* $@9  */
  YYSYMBOL_ParameterList = 73,             /* ParameterList  */
  YYSYMBOL_ParamList = 74,                 /* ParamList  */
  YYSYMBOL_75_10 = 75,                     /* $@10  */
  YYSYMBOL_CompoundStatement = 76,         /* CompoundStatement  */
  YYSYMBOL_OptionalStatements = 77,        /* OptionalStatements  */
  YYSYMBOL_StatementList = 78,             /* StatementList  */
  YYSYMBOL_Statement = 79,                 /* Statement  */
  YYSYMBOL_80_11 = 80,                     /* $@11  */
  YYSYMBOL_81_12 = 81,                     /* $@12  */
  YYSYMBOL_82_13 = 82,                     /* $@13  */
  YYSYMBOL_83_14 = 83,                     /* $@14  */
  YYSYMBOL_84_15 = 84,                     /* $@15  */
  YYSYMBOL_85_16 = 85,                     /* $@16  */
  YYSYMBOL_86_17 = 86,                     /* $@17  */
  YYSYMBOL_Lhs = 87,                       /* Lhs  */
  YYSYMBOL_88_18 = 88,                     /* $@18  */
  YYSYMBOL_ProcedureCall = 89,             /* ProcedureCall  */
  YYSYMBOL_90_19 = 90,                     /* $@19  */
  YYSYMBOL_91_20 = 91,                     /* $@20  */
  YYSYMBOL_92_21 = 92,                     /* $@21  */
  YYSYMBOL_Guard = 93,                     /* Guard  */
  YYSYMBOL_94_22 = 94,                     /* $@22  */
  YYSYMBOL_95_23 = 95,                     /* $@23  */
  YYSYMBOL_96_24 = 96,                     /* $@24  */
  YYSYMBOL_97_25 = 97,                     /* $@25  */
  YYSYMBOL_BoolAtom = 98,                  /* BoolAtom  */
  YYSYMBOL_99_26 = 99,                     /* $@26  */
  YYSYMBOL_100_27 = 100,                   /* $@27  */
  YYSYMBOL_Relop = 101,                    /* Relop  */
  YYSYMBOL_ArithExprList = 102,            /* ArithExprList  */
  YYSYMBOL_103_28 = 103,                   /* $@28  */
  YYSYMBOL_ArithExpr = 104,                /* ArithExpr  */
  YYSYMBOL_105_29 = 105,                   /* $@29  */
  YYSYMBOL_106_30 = 106,                   /* $@30  */
  YYSYMBOL_107_31 = 107,                   /* $@31  */
  YYSYMBOL_108_32 = 108,                   /* $@32  */
  YYSYMBOL_109_33 = 109,                   /* $@33  */
  YYSYMBOL_110_34 = 110,                   /* $@34  */
  YYSYMBOL_111_35 = 111,                   /* $@35  */
  YYSYMBOL_112_36 = 112,                   /* $@36  */
  YYSYMBOL_113_37 = 113,                   /* $@37  */
  YYSYMBOL_114_38 = 114,                   /* $@38  */
  YYSYMBOL_115_39 = 115                    /* $@39  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   184

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      49,    50,    37,    35,    46,    36,    44,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    43,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
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
      39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    77,    77,    81,    77,    85,    87,    90,    91,    94,
      94,    95,    98,   101,   106,   107,   107,   112,   116,   122,
     123,   126,   129,   129,   130,   130,   130,   133,   134,   137,
     137,   137,   140,   141,   144,   144,   145,   148,   151,   152,
     155,   156,   159,   159,   160,   161,   162,   163,   163,   163,
     163,   163,   164,   164,   164,   167,   168,   168,   171,   172,
     172,   173,   173,   174,   174,   177,   178,   178,   179,   179,
     180,   180,   181,   181,   184,   184,   184,   187,   188,   189,
     190,   191,   192,   195,   196,   196,   199,   214,   214,   234,
     234,   240,   258,   265,   265,   269,   269,   270,   270,   271,
     271,   272,   272,   273,   273,   274,   274,   275,   275,   275
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "CONST",
  "VAR", "ARRAY", "RANGE", "OF", "SKIP", "READLN", "WRITELN", "FUNCTION",
  "PROCEDURE", "BEGINTOK", "ENDTOK", "ASSIGN", "IF", "THEN", "ELSE",
  "WHILE", "DO", "RELOPLT", "RELOPLEQ", "RELOPEQ", "RELOPNEQ", "RELOPGEQ",
  "RELOPGT", "INTEGER", "REAL", "AND", "OR", "NOT", "DIV", "MOD", "'+'",
  "'-'", "'*'", "'/'", "IDENTIFIER", "REALNUMBER", "INTNUMBER", "INTRANGE",
  "';'", "'.'", "':'", "','", "'['", "']'", "'('", "')'", "$accept",
  "program", "$@1", "$@2", "ConstDecl", "NumericValue", "VarDecl", "$@3",
  "IdentifierList", "TypeSpec", "$@4", "BasicType", "FuncProcDecl",
  "SubProgDecl", "SubProgHeading", "$@5", "$@6", "$@7",
  "PossibleParameters", "Parameters", "$@8", "$@9", "ParameterList",
  "ParamList", "$@10", "CompoundStatement", "OptionalStatements",
  "StatementList", "Statement", "$@11", "$@12", "$@13", "$@14", "$@15",
  "$@16", "$@17", "Lhs", "$@18", "ProcedureCall", "$@19", "$@20", "$@21",
  "Guard", "$@22", "$@23", "$@24", "$@25", "BoolAtom", "$@26", "$@27",
  "Relop", "ArithExprList", "$@28", "ArithExpr", "$@29", "$@30", "$@31",
  "$@32", "$@33", "$@34", "$@35", "$@36", "$@37", "$@38", "$@39", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-110)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-109)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,    -9,    33,    26,  -110,  -110,  -110,    37,    48,    94,
      95,   122,    14,    -2,    96,  -110,  -110,   118,    90,  -110,
    -110,  -110,    91,  -110,    25,    97,    98,     8,    99,  -110,
     118,  -110,     3,   100,    89,  -110,  -110,    92,   101,  -110,
    -110,    -3,  -110,   125,   102,  -110,   126,  -110,  -110,  -110,
     104,  -110,  -110,   103,  -110,  -110,  -110,   107,    89,  -110,
    -110,   -20,   -20,   106,   105,  -110,     8,  -110,   108,  -110,
       1,    57,   112,  -110,    -4,    -4,  -110,  -110,    64,  -110,
      -4,    64,    -4,    -4,  -110,    -4,   137,  -110,    51,   113,
    -110,   114,  -110,   -26,  -110,  -110,   109,    30,   111,   115,
     110,   -20,   -20,  -110,  -110,   130,    87,   140,    24,   116,
      30,   117,    96,     3,     1,   119,  -110,   120,   121,  -110,
     127,   128,   129,   131,   124,   138,   141,    -4,    -4,  -110,
    -110,   -16,   -20,   -20,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,     8,  -110,  -110,   132,    56,  -110,  -110,  -110,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    30,
      55,  -110,  -110,   142,     8,    -4,  -110,   166,     3,    70,
     133,    30,   143,    80,    19,    13,    93,    30,   134,   157,
      30,  -110,  -110,  -110,  -110,  -110,  -110,    57,     8,  -110,
    -110
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     2,     6,    11,     0,    20,
       0,     0,     3,     0,     0,    22,    24,     0,     0,    11,
       8,     7,     0,    12,     0,     0,     0,    39,     0,    19,
       9,     5,     0,     0,     0,    25,    46,     0,     0,    47,
      52,    58,    45,     0,    38,    40,     0,    44,     4,    21,
       0,    17,    18,     0,    14,    13,    29,     0,    28,    61,
      63,    74,    74,     0,     0,    37,     0,    42,     0,    10,
       0,     0,     0,    27,   105,   105,    66,    72,    48,    65,
     105,    53,   105,   105,    41,   105,     0,    34,     0,    30,
      32,     0,    26,    86,    92,    91,    84,    83,     0,     0,
      84,    74,    74,    70,    68,     0,    93,     0,    93,    84,
      43,     0,     0,     0,     0,     0,    23,     0,     0,    62,
       0,     0,     0,     0,     0,     0,     0,   105,   105,    64,
      67,     0,    74,    74,    49,    77,    78,    79,    80,    81,
      82,    75,     0,    57,    60,     0,     0,    36,    33,    31,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   106,
      93,    73,    71,    69,     0,   105,    54,     0,     0,    93,
      84,    85,    94,    96,    98,   100,   102,   104,     0,     0,
      76,    15,    35,    88,    90,   109,    50,     0,     0,    16,
      51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,  -110,  -110,  -110,  -110,   158,  -110,   -12,  -109,
    -110,   -70,  -110,  -110,  -110,  -110,  -110,  -110,  -110,   123,
    -110,  -110,  -110,    65,  -110,    -6,  -110,  -110,   -66,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,   -59,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,   -67,  -110,   -75,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     6,    17,     7,    22,     9,    11,    88,    53,
     187,    54,    12,    18,    19,    25,    26,    58,    72,    57,
      70,   115,    89,    90,   112,    42,    43,    44,    45,    85,
      61,   105,   164,   188,    62,   107,    46,    63,    47,    64,
      74,    75,    78,   101,   133,   132,   102,    79,    80,   165,
     141,    96,   120,    97,   117,   118,   121,   122,   123,   124,
     125,   126,    98,    99,   178
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      84,    91,    24,    81,   147,   106,    87,   108,   100,    50,
     110,    28,    76,   -55,   103,   104,   109,    36,    37,    38,
       1,   -87,    27,   -89,    49,    39,    15,    16,    40,    77,
       3,    51,    52,     4,   161,    93,    94,    95,    20,    21,
      23,     8,   130,   131,   -56,  -107,   -59,    41,   -93,   -95,
     -97,   -99,   159,   160,   -93,   -95,   -97,  -101,  -103,   182,
     -95,   -97,   -99,  -101,  -103,   -93,   -95,   -97,   -99,     5,
      32,    33,   143,   162,   163,   169,   166,   171,   172,   173,
     174,   175,   176,   177,   170,    51,    52,    10,  -101,  -103,
     180,   -95,   -97,   -99,   103,   104,   113,    33,   179,    -9,
     146,   168,    33,  -101,  -103,  -108,   -95,   -97,   -99,   135,
     136,   137,   138,   139,   140,   -93,   -95,   189,   183,    13,
    -101,  -103,   190,   -95,   -97,   -99,  -101,    14,   -93,   -95,
     -97,   -99,    27,    29,    31,    23,    34,    35,    56,    55,
      65,    59,    67,    48,   111,    66,    69,   127,   134,    86,
      60,    68,    71,    82,    83,    92,   114,   116,   145,   119,
     129,   142,   156,   153,   128,   154,   144,   150,   155,   149,
     151,   157,   103,   152,   181,   158,   186,    30,   -93,   148,
     167,    73,     0,   184,   185
};

static const yytype_int16 yycheck[] =
{
      66,    71,    14,    62,   113,    80,     5,    82,    75,     6,
      85,    17,    32,    16,    30,    31,    83,     9,    10,    11,
       3,    47,    14,    49,    30,    17,    12,    13,    20,    49,
      39,    28,    29,     0,    50,    39,    40,    41,    40,    41,
      39,     4,   101,   102,    47,    49,    49,    39,    35,    36,
      37,    38,   127,   128,    35,    36,    37,    33,    34,   168,
      36,    37,    38,    33,    34,    35,    36,    37,    38,    43,
      45,    46,    48,   132,   133,   150,   142,   152,   153,   154,
     155,   156,   157,   158,   151,    28,    29,    39,    33,    34,
     165,    36,    37,    38,    30,    31,    45,    46,   164,     5,
     112,    45,    46,    33,    34,    50,    36,    37,    38,    22,
      23,    24,    25,    26,    27,    35,    36,   187,    48,    24,
      33,    34,   188,    36,    37,    38,    33,     5,    35,    36,
      37,    38,    14,    43,    43,    39,    39,    39,    49,    39,
      15,    49,    16,    44,     7,    43,    43,    36,    18,    41,
      49,    47,    45,    47,    49,    43,    43,    43,    41,    50,
      50,    21,    38,    35,    49,    36,    50,    47,    37,    50,
      49,    33,    30,    46,     8,    34,    19,    19,    35,   114,
      48,    58,    -1,    50,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    52,    39,     0,    43,    53,    55,     4,    57,
      39,    58,    63,    24,     5,    12,    13,    54,    64,    65,
      40,    41,    56,    39,    59,    66,    67,    14,    76,    43,
      57,    43,    45,    46,    39,    39,     9,    10,    11,    17,
      20,    39,    76,    77,    78,    79,    87,    89,    44,    76,
       6,    28,    29,    60,    62,    39,    49,    70,    68,    49,
      49,    81,    85,    88,    90,    15,    43,    16,    47,    43,
      71,    45,    69,    70,    91,    92,    32,    49,    93,    98,
      99,    93,    47,    49,    79,    80,    41,     5,    59,    73,
      74,    62,    43,    39,    40,    41,   102,   104,   113,   114,
     102,    94,    97,    30,    31,    82,   104,    86,   104,   102,
     104,     7,    75,    45,    43,    72,    43,   105,   106,    50,
     103,   107,   108,   109,   110,   111,   112,    36,    49,    50,
      93,    93,    96,    95,    18,    22,    23,    24,    25,    26,
      27,   101,    21,    48,    50,    41,    59,    60,    74,    50,
      47,    49,    46,    35,    36,    37,    38,    33,    34,   104,
     104,    50,    93,    93,    83,   100,    79,    48,    45,   104,
     102,   104,   104,   104,   104,   104,   104,   104,   115,    79,
     104,     8,    60,    48,    50,    50,    19,    61,    84,    62,
      79
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    53,    54,    52,    55,    55,    56,    56,    58,
      57,    57,    59,    59,    60,    61,    60,    62,    62,    63,
      63,    64,    66,    65,    67,    68,    65,    69,    69,    71,
      72,    70,    73,    73,    75,    74,    74,    76,    77,    77,
      78,    78,    80,    79,    79,    79,    79,    81,    82,    83,
      84,    79,    85,    86,    79,    87,    88,    87,    89,    90,
      89,    91,    89,    92,    89,    93,    94,    93,    95,    93,
      96,    93,    97,    93,    99,   100,    98,   101,   101,   101,
     101,   101,   101,   102,   103,   102,   104,   105,   104,   106,
     104,   104,   104,   107,   104,   108,   104,   109,   104,   110,
     104,   111,   104,   112,   104,   113,   104,   114,   115,   104
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,    10,     6,     0,     1,     1,     0,
       7,     0,     1,     3,     1,     0,     9,     1,     1,     3,
       0,     3,     0,     7,     0,     0,     6,     1,     0,     0,
       0,     5,     1,     3,     0,     5,     3,     3,     1,     0,
       1,     3,     0,     4,     1,     1,     1,     0,     0,     0,
       0,    10,     0,     0,     6,     1,     0,     5,     1,     0,
       5,     0,     5,     0,     5,     1,     0,     3,     0,     4,
       0,     4,     0,     4,     0,     0,     5,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     1,     0,     5,     0,
       5,     1,     1,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     3,     0,     0,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* $@1: %empty  */
#line 77 "parser.y"
                                            {printf("#include <stdio.h>\n\n");}
#line 1362 "parser.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 81 "parser.y"
                           {printf("int main() {\n");}
#line 1368 "parser.tab.c"
    break;

  case 4: /* program: PROGRAM IDENTIFIER ';' $@1 ConstDecl VarDecl FuncProcDecl $@2 CompoundStatement '.'  */
#line 82 "parser.y"
                               {printf("return 0;\n}");}
#line 1374 "parser.tab.c"
    break;

  case 5: /* ConstDecl: ConstDecl CONST IDENTIFIER RELOPEQ NumericValue ';'  */
#line 85 "parser.y"
                                                                         {if (intConstFlag) {printf("const int %s = %d;\n", (yyvsp[-3].strval), constantInt);} 
                                                                          else if (realConstFlag) {printf("const double %s = %f;\n", (yyvsp[-3].strval), constantReal);}}
#line 1381 "parser.tab.c"
    break;

  case 7: /* NumericValue: INTNUMBER  */
#line 90 "parser.y"
                               {intConstFlag = 1; constantInt = (yyvsp[0].ival);}
#line 1387 "parser.tab.c"
    break;

  case 8: /* NumericValue: REALNUMBER  */
#line 91 "parser.y"
                                {realConstFlag = 1; constantReal = (yyvsp[0].dval);}
#line 1393 "parser.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 94 "parser.y"
                             {varEnvironment = 1;}
#line 1399 "parser.tab.c"
    break;

  case 10: /* VarDecl: VarDecl $@3 VAR IdentifierList ':' TypeSpec ';'  */
#line 94 "parser.y"
                                                                                       {varEnvironment = 0;}
#line 1405 "parser.tab.c"
    break;

  case 12: /* IdentifierList: IDENTIFIER  */
#line 98 "parser.y"
                                                                            {{if (varEnvironment) {addVar((yyvsp[0].strval));}} if (varParamEnv) {addVarParam((yyvsp[0].strval));}
                                                                            else if (paramEnvironment) {addParam((yyvsp[0].strval));}
                                                                            else if (functionEnv || procedureEnv) {addFuncProcVar((yyvsp[0].strval));}}
#line 1413 "parser.tab.c"
    break;

  case 13: /* IdentifierList: IdentifierList ',' IDENTIFIER  */
#line 101 "parser.y"
                                                                            {{if (varEnvironment) {addVar((yyvsp[0].strval));}} if (varParamEnv) {addVarParam((yyvsp[0].strval));}
                                                                             else if (paramEnvironment) {addParam((yyvsp[0].strval));}
                                                                             else if (functionEnv || procedureEnv) {addFuncProcVar((yyvsp[0].strval));}}
#line 1421 "parser.tab.c"
    break;

  case 15: /* $@4: %empty  */
#line 107 "parser.y"
                                                                {arrEnvironment = 1;}
#line 1427 "parser.tab.c"
    break;

  case 16: /* TypeSpec: ARRAY '[' INTNUMBER RANGE INTNUMBER ']' OF $@4 BasicType  */
#line 107 "parser.y"
                                                                                                {if (varEnvironment && !(functionEnv || procedureEnv)) {printArr((yyvsp[-6].ival), (yyvsp[-4].ival), temp+2);}
                                                                                                 else if (paramEnvironment) {changeTypeArrParam((yyvsp[-6].ival), (yyvsp[-4].ival), temp);} 
                                                                                                 else if (functionEnv || procedureEnv) {printFuncVarArr((yyvsp[-6].ival), (yyvsp[-4].ival), temp);} arrEnvironment = 0;}
#line 1435 "parser.tab.c"
    break;

  case 17: /* BasicType: INTEGER  */
#line 112 "parser.y"
                                                                            {temp = 1; if (varEnvironment && !arrEnvironment && !(functionEnv|| procedureEnv)) {printVar(1);} 
                                                                              if (varParamEnv && !arrEnvironment) {changeTypeParam(1);}
                                                                              else if (paramEnvironment && !arrEnvironment) {changeTypeParam(1);}
                                                                              else if ((functionEnv || procedureEnv) && !arrEnvironment && !paramEnvironment) {printFuncVar(1);}}
#line 1444 "parser.tab.c"
    break;

  case 18: /* BasicType: REAL  */
#line 116 "parser.y"
                                                                            {temp = 2; if (varEnvironment && !arrEnvironment && !(functionEnv|| procedureEnv)) {printVar(2);} 
                                                                              if (varParamEnv && !arrEnvironment) {changeTypeParam(2);}
                                                                              else if (paramEnvironment && !arrEnvironment) {changeTypeParam(2);}
                                                                              else if ((functionEnv || procedureEnv) && !arrEnvironment && !paramEnvironment) {printFuncVar(2);}}
#line 1453 "parser.tab.c"
    break;

  case 21: /* SubProgDecl: SubProgHeading VarDecl CompoundStatement  */
#line 126 "parser.y"
                                                              { freeFuncVarArr(); freeParamArr(); printf("}\n"); functionEnv = 0; procedureEnv = 0;}
#line 1459 "parser.tab.c"
    break;

  case 22: /* $@5: %empty  */
#line 129 "parser.y"
                              {functionEnv = 1;}
#line 1465 "parser.tab.c"
    break;

  case 23: /* SubProgHeading: FUNCTION $@5 IDENTIFIER Parameters ':' BasicType ';'  */
#line 129 "parser.y"
                                                                                         {addFunc((yyvsp[-4].strval), temp); printFuncParams();}
#line 1471 "parser.tab.c"
    break;

  case 24: /* $@6: %empty  */
#line 130 "parser.y"
                               {procedureEnv = 1;}
#line 1477 "parser.tab.c"
    break;

  case 25: /* $@7: %empty  */
#line 130 "parser.y"
                                                              {printProcedureStart((yyvsp[0].strval));}
#line 1483 "parser.tab.c"
    break;

  case 26: /* SubProgHeading: PROCEDURE $@6 IDENTIFIER $@7 PossibleParameters ';'  */
#line 130 "parser.y"
                                                                                                                {printProcParams();}
#line 1489 "parser.tab.c"
    break;

  case 29: /* $@8: %empty  */
#line 137 "parser.y"
                          { paramEnvironment = 1;}
#line 1495 "parser.tab.c"
    break;

  case 30: /* $@9: %empty  */
#line 137 "parser.y"
                                                                 {paramEnvironment = 0;}
#line 1501 "parser.tab.c"
    break;

  case 34: /* $@10: %empty  */
#line 144 "parser.y"
                         {varParamEnv = 1;}
#line 1507 "parser.tab.c"
    break;

  case 35: /* ParamList: VAR $@10 IdentifierList ':' TypeSpec  */
#line 144 "parser.y"
                                                                        {varParamEnv = 0;}
#line 1513 "parser.tab.c"
    break;

  case 42: /* $@11: %empty  */
#line 159 "parser.y"
                                { assignmentEnv = 1;}
#line 1519 "parser.tab.c"
    break;

  case 43: /* Statement: Lhs ASSIGN $@11 ArithExpr  */
#line 159 "parser.y"
                                                                {printf(";\n"); finalAssignment(temp3Iden, lhsArrayFlag, arithIntTemp2); lhsArrayFlag = 0; assignmentEnv = 0; temp2 = 0;}
#line 1525 "parser.tab.c"
    break;

  case 47: /* $@12: %empty  */
#line 163 "parser.y"
                        {ifGuardEnv = 1; }
#line 1531 "parser.tab.c"
    break;

  case 48: /* $@13: %empty  */
#line 163 "parser.y"
                                                 {printf(";\n"); guardAssocs(); printNextIf(); ifGuardEnv = 0;}
#line 1537 "parser.tab.c"
    break;

  case 49: /* $@14: %empty  */
#line 163 "parser.y"
                                                                                                                     {ifEnvironment = 1;}
#line 1543 "parser.tab.c"
    break;

  case 50: /* $@15: %empty  */
#line 163 "parser.y"
                                                                                                                                                         {printNextNextIf();}
#line 1549 "parser.tab.c"
    break;

  case 51: /* Statement: IF $@12 Guard $@13 THEN $@14 Statement ELSE $@15 Statement  */
#line 163 "parser.y"
                                                                                                                                                                                        {ifEnvironment = 0; printFinalIf();}
#line 1555 "parser.tab.c"
    break;

  case 52: /* $@16: %empty  */
#line 164 "parser.y"
                           {whileGuardEnv = 1; startWhile();}
#line 1561 "parser.tab.c"
    break;

  case 53: /* $@17: %empty  */
#line 164 "parser.y"
                                                                    { printf(";\n"); printNextWhile(); whileGuardEnv = 0;}
#line 1567 "parser.tab.c"
    break;

  case 54: /* Statement: WHILE $@16 Guard $@17 DO Statement  */
#line 164 "parser.y"
                                                                                                                                        {printFinalWhile();}
#line 1573 "parser.tab.c"
    break;

  case 55: /* Lhs: IDENTIFIER  */
#line 167 "parser.y"
                                {printTempVar((yyvsp[0].strval)); temp3Iden = (yyvsp[0].strval);}
#line 1579 "parser.tab.c"
    break;

  case 56: /* $@18: %empty  */
#line 168 "parser.y"
                                {printTempVar((yyvsp[0].strval)); lhsArrayEnv = 1; temp3Iden = (yyvsp[0].strval);}
#line 1585 "parser.tab.c"
    break;

  case 57: /* Lhs: IDENTIFIER $@18 '[' ArithExpr ']'  */
#line 168 "parser.y"
                                                                                                       { lhsArrayEnv = 0; lhsArrayFlag = 1;}
#line 1591 "parser.tab.c"
    break;

  case 59: /* $@19: %empty  */
#line 172 "parser.y"
                                {printf("%s(", (yyvsp[0].strval)); procCallEnv = 1;}
#line 1597 "parser.tab.c"
    break;

  case 60: /* ProcedureCall: IDENTIFIER $@19 '(' ArithExprList ')'  */
#line 172 "parser.y"
                                                                                            {printf(");\n"); procCallEnv = 0;}
#line 1603 "parser.tab.c"
    break;

  case 61: /* $@20: %empty  */
#line 173 "parser.y"
                                {scanEnvironment = 1;}
#line 1609 "parser.tab.c"
    break;

  case 62: /* ProcedureCall: READLN '(' $@20 ArithExprList ')'  */
#line 173 "parser.y"
                                                                         {scanEnvironment = 0; finalPrintRead();}
#line 1615 "parser.tab.c"
    break;

  case 63: /* $@21: %empty  */
#line 174 "parser.y"
                                 {writeEnvironment = 1;}
#line 1621 "parser.tab.c"
    break;

  case 64: /* ProcedureCall: WRITELN '(' $@21 ArithExprList ')'  */
#line 174 "parser.y"
                                                                           {writeEnvironment = 0; finalWriteRead();}
#line 1627 "parser.tab.c"
    break;

  case 66: /* $@22: %empty  */
#line 178 "parser.y"
                         { saveGuard("!");}
#line 1633 "parser.tab.c"
    break;

  case 68: /* $@23: %empty  */
#line 179 "parser.y"
                              {; saveGuard("||");}
#line 1639 "parser.tab.c"
    break;

  case 70: /* $@24: %empty  */
#line 180 "parser.y"
                               { saveGuard("&&");}
#line 1645 "parser.tab.c"
    break;

  case 72: /* $@25: %empty  */
#line 181 "parser.y"
                         {inBrackFlag = 1;}
#line 1651 "parser.tab.c"
    break;

  case 73: /* Guard: '(' $@25 Guard ')'  */
#line 181 "parser.y"
                                                      {inBrackFlag = 0;;}
#line 1657 "parser.tab.c"
    break;

  case 74: /* $@26: %empty  */
#line 184 "parser.y"
                     { rhsGuard = 1;}
#line 1663 "parser.tab.c"
    break;

  case 75: /* $@27: %empty  */
#line 184 "parser.y"
                                                      {if (inBrackFlag) {changeTypeBrack();} rhsGuard = -1;}
#line 1669 "parser.tab.c"
    break;

  case 76: /* BoolAtom: $@26 ArithExpr Relop $@27 ArithExpr  */
#line 184 "parser.y"
                                                                                                                       {rhsGuard = 0;}
#line 1675 "parser.tab.c"
    break;

  case 77: /* Relop: RELOPLT  */
#line 187 "parser.y"
                             {saveGuardSym(1); if (whileGuardEnv) {printf(" < ");}}
#line 1681 "parser.tab.c"
    break;

  case 78: /* Relop: RELOPLEQ  */
#line 188 "parser.y"
                              {saveGuardSym(2); if (whileGuardEnv) {printf(" <= ");}}
#line 1687 "parser.tab.c"
    break;

  case 79: /* Relop: RELOPEQ  */
#line 189 "parser.y"
                             {saveGuardSym(3); if (whileGuardEnv) {printf(" == ");}}
#line 1693 "parser.tab.c"
    break;

  case 80: /* Relop: RELOPNEQ  */
#line 190 "parser.y"
                              {saveGuardSym(4); if (whileGuardEnv) {printf(" != ");}}
#line 1699 "parser.tab.c"
    break;

  case 81: /* Relop: RELOPGEQ  */
#line 191 "parser.y"
                              {saveGuardSym(5); if (whileGuardEnv) {printf(" >= ");}}
#line 1705 "parser.tab.c"
    break;

  case 82: /* Relop: RELOPGT  */
#line 192 "parser.y"
                             {saveGuardSym(6); if (whileGuardEnv) {printf(" > ");}}
#line 1711 "parser.tab.c"
    break;

  case 84: /* $@28: %empty  */
#line 196 "parser.y"
                                   {if (procCallEnv) {printf(", ");}}
#line 1717 "parser.tab.c"
    break;

  case 86: /* ArithExpr: IDENTIFIER  */
#line 199 "parser.y"
                                {
                                if (rhsGuard == 1) {saveGuardVar((yyvsp[0].strval));} else if (rhsGuard == -1) {saveGaurdVar2((yyvsp[0].strval));}
                                if (procCallEnv) {varChecker2((yyvsp[0].strval));}
                                // scanEnvironment = readln(ARITH) printReadVar takes iden and adds it to temporary scan array 
                                if (scanEnvironment) {printReadVar((yyvsp[0].strval));} 
                                // writeEnvironment = writeln(ARITH) printWriteVar takes iden and adds it to temporary write array
                                if (writeEnvironment && !specEnvironment) {printWriteVar((yyvsp[0].strval));}
                                // If you are in the write environment and within a function environment as well, add this iden to your function environment list.
                                if (writeEnvironment && specEnvironment) {addWriteFuncVar((yyvsp[0].strval));}
                                // If you are in the guard and while environment, simply print the iden
                                if (whileGuardEnv) {printf("%s", (yyvsp[0].strval));} 
                                // Else if you are in the assignment environment and not in the assignment of an array environment, print iden and print a new aux variable.
                                else if (assignmentEnv && !assignmentArrEnv) {varChecker((yyvsp[0].strval)); temp2++; nextAssignment();}
                                // If you are on the left hand side of the array, simply print the iden.
                                else if (lhsArrayEnv) {printf("%s", (yyvsp[0].strval));}}
#line 1737 "parser.tab.c"
    break;

  case 87: /* $@29: %empty  */
#line 214 "parser.y"
                                {
                   // If you are in the assignment environment, check if you are doing the first assignment or the next aux variable assignments, and print the array iden.
                   if (assignmentEnv) {if (temp < 2) {printf("%s[", (yyvsp[0].strval)); temp2++;} else {firstAssignmentFlag = 1; printf("%s[", (yyvsp[0].strval)); temp2++;} }
                   // if you are in the guard environment, simply print the arr iden.
                   if (whileGuardEnv) {printf("%s[", (yyvsp[0].strval));} assignmentArrEnv = 1; temp2Iden = (yyvsp[0].strval); }
#line 1747 "parser.tab.c"
    break;

  case 88: /* ArithExpr: IDENTIFIER $@29 '[' ArithExpr ']'  */
#line 220 "parser.y"
                                                                                                                              { if (rhsGuard == 1) {saveGuardArr((yyvsp[-4].strval), arithIntTemp);}
                                                                                                                                // If you are in the assignment environment or gaurd environment, simply print the closing array bracket.
                                                                                                                                if (assignmentEnv ||  whileGuardEnv)
                                                                                                                                {printf("]");} 
                                                                                                                                // If you are in the assignment environment, print the closing bracket, end of statement and new line
                                                                                                                                else if (assignmentEnv) {printf("];\n"); nextAssignment(); }
                                                                                                                                //Now outside of array assignment environment
                                                                                                                                assignmentArrEnv = 0;
                                                                                                                                // If you are in the scan environment, add the array to your scan array along with the changed idx.
                                                                                                                                if (scanEnvironment) {printReadArr((yyvsp[-4].strval), arithIntTemp);}
                                                                                                                                // If you are in the write environment and not in the function environment, add the array to your scan array.
                                                                                                                                if (writeEnvironment && !specEnvironment) {printWriteArr((yyvsp[-4].strval), arithIntTemp);}
                                                                                                                                // If you are in the write environment and in the function environment, add the array to your function param array.
                                                                                                                                else if (writeEnvironment && specEnvironment) {addWriteFuncArr((yyvsp[-4].strval), arithIntTemp);} }
#line 1766 "parser.tab.c"
    break;

  case 89: /* $@30: %empty  */
#line 234 "parser.y"
                                {
                    // If you are in the write environment, add the function to your write array. 
                    if (writeEnvironment) {printWriteFunc((yyvsp[0].strval));} specEnvironment = 1;}
#line 1774 "parser.tab.c"
    break;

  case 90: /* ArithExpr: IDENTIFIER $@30 '(' ArithExprList ')'  */
#line 239 "parser.y"
                    {specEnvironment = 0;}
#line 1780 "parser.tab.c"
    break;

  case 91: /* ArithExpr: INTNUMBER  */
#line 240 "parser.y"
                               {
                    if (rhsGuard == -1) {saveGuardVal((yyvsp[0].ival), 0.0, 1);}
                    if (procCallEnv) {printf("%d", (yyvsp[0].ival));}
                    // Create variable to use later in other functions when needeed.
                    arithIntTemp = (yyvsp[0].ival); 
                    // If you are in the array assignment environment, add the number to a special variable.
                    if (assignmentArrEnv) {arithIntTemp2 = (yyvsp[0].ival);}
                    // If you are in the gaurd environment or assignment of an array environment, print the changed idx according to the C bounds.
                    else if (whileGuardEnv && assignmentArrEnv) {changedIdxArray(temp2Iden, (yyvsp[0].ival));}
                    // If you are in the gaurd environment and not in the assignment of an array environment, simply print the number.                                              
                    else if (whileGuardEnv && !assignmentArrEnv) {printf("%d", (yyvsp[0].ival));}
                    // If you are purely in the assignment of an array environment, also print the changed idx.
                    if ((assignmentArrEnv && !writeEnvironment && !scanEnvironment)) {changedIdxArray(temp2Iden, (yyvsp[0].ival));}
                    // Else if you are in the assignment environment, print the number.
                    else if (assignmentEnv) {printf("%d", (yyvsp[0].ival));}
                    // Else if you are in the write and function environment, add the number to your function parameter array.
                    else if (writeEnvironment && specEnvironment && !assignmentArrEnv) {addWriteFuncNum((yyvsp[0].ival), 0.0);}
                    }
#line 1803 "parser.tab.c"
    break;

  case 92: /* ArithExpr: REALNUMBER  */
#line 258 "parser.y"
                                {
                    if (rhsGuard == -1) {saveGuardVal(0, (yyvsp[0].dval), 2);}
                    if (procCallEnv) {printf("%.1f", (yyvsp[0].dval));}
                    // If you are in the gaurd or assignment environment, print the number
                    if (whileGuardEnv || assignmentEnv ) {printf("%.1f", (yyvsp[0].dval));} 
                    // If you are in the write and function environment, add the number to your function parameter array.
                    else if (writeEnvironment && specEnvironment) {addWriteFuncNum(0, (yyvsp[0].dval));}}
#line 1815 "parser.tab.c"
    break;

  case 93: /* $@31: %empty  */
#line 265 "parser.y"
                               { 
                    printf(" + ");
                   }
#line 1823 "parser.tab.c"
    break;

  case 95: /* $@32: %empty  */
#line 269 "parser.y"
                               { if (firstAssignmentFlag) {printf("\n - ");} else {printf(" - ");}}
#line 1829 "parser.tab.c"
    break;

  case 97: /* $@33: %empty  */
#line 270 "parser.y"
                               { if (firstAssignmentFlag) {printf("\n * ");} else {printf(" * ");}}
#line 1835 "parser.tab.c"
    break;

  case 99: /* $@34: %empty  */
#line 271 "parser.y"
                               { if (firstAssignmentFlag) {printf("\n / ");} else {printf(" / ");}}
#line 1841 "parser.tab.c"
    break;

  case 101: /* $@35: %empty  */
#line 272 "parser.y"
                               { if (firstAssignmentFlag) {printf("\n / ");} else {printf(" / ");}}
#line 1847 "parser.tab.c"
    break;

  case 103: /* $@36: %empty  */
#line 273 "parser.y"
                               { if (firstAssignmentFlag) {printf("\n %% ");} else {printf(" %% ");}}
#line 1853 "parser.tab.c"
    break;

  case 105: /* $@37: %empty  */
#line 274 "parser.y"
                     {printf(" - ");}
#line 1859 "parser.tab.c"
    break;

  case 107: /* $@38: %empty  */
#line 275 "parser.y"
                     {printf("(");}
#line 1865 "parser.tab.c"
    break;

  case 108: /* $@39: %empty  */
#line 275 "parser.y"
                                                  {printf(")");}
#line 1871 "parser.tab.c"
    break;


#line 1875 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 278 "parser.y"


void printToken(int token) {
  /* single character tokens */
  if (token < 256) {
    if (token < 33) {
      /* non-printable character */
      printf("chr(%d)", token);
    } else {
      printf("'%c'", token);
    }
    return;
  }
  /* standard tokens (>255) */
  switch (token) {
  case PROGRAM   : printf("PROGRAM");
    break;
  case CONST     : printf("CONST");
    break;
  case IDENTIFIER: printf("identifier<%s>", yytext);
    break;
  case VAR       : printf("VAR");
    break;
  case ARRAY     : printf("ARRAY");
    break;
  case RANGE     : printf("..");
    break;
  case INTNUMBER : printf("Integer<%d>", yylval.ival);
    break;
  case REALNUMBER: printf("Real<%lf>", yylval.dval);
    break;
  case OF        : printf("OF");
    break;
  case INTEGER   : printf("INTEGER");
    break;
  case REAL      : printf("REAL");
    break;
  case FUNCTION  : printf("FUNCTION");
    break;
  case PROCEDURE : printf("PROCEDURE");
    break;
  case BEGINTOK  : printf("BEGIN");
    break;
  case ENDTOK    : printf("END");
    break;
  case ASSIGN    : printf(":=");
    break;
  case IF        : printf("IF");
    break;
  case THEN      : printf("THEN");
    break;
  case ELSE      : printf("ELSE");
    break;
  case WHILE     : printf("WHILE");
    break;
  case DO        : printf("DO");
    break;
  case SKIP      : printf("SKIP");
    break;
  case READLN    : printf("READLN");
    break;
  case WRITELN   : printf("WRITELN");
    break;
  }
}

void yyerror (char *msg) {
  showErrorLine();
  fprintf (stderr, "%s (detected at token=", msg);
  printToken(yychar);
  printf(").\n");
  exit(EXIT_SUCCESS);  /* EXIT_SUCCESS because we use Themis */
}

int main(int argc, char *argv[]) {
  if (argc > 2) {
    fprintf(stderr, "Usage: %s [pasfile]\n", argv[0]);
    return EXIT_FAILURE;
  }

  
  FILE *f = stdin;
  if (argc == 2) {
    f = fopen(argv[1], "r");
    if (f == NULL) {
      fprintf(stderr, "Error: failed to open file\n");
      exit(EXIT_FAILURE);
    }
  }

  initLexer(f);
  yyparse();
  finalizeLexer();

#if 0
  showStringTable();
#endif
  return EXIT_SUCCESS;
}
