%{
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
%}

%token PROGRAM CONST VAR ARRAY RANGE OF SKIP READLN WRITELN
       FUNCTION PROCEDURE BEGINTOK ENDTOK ASSIGN IF THEN ELSE WHILE DO
       RELOPLT RELOPLEQ RELOPEQ RELOPNEQ RELOPGEQ RELOPGT INTEGER REAL
       AND OR NOT DIV MOD

%left '+' '-'
%left '*' '/' DIV MOD
%left OR
%left AND
%left NOT

%union {
  int ival;     /* used for passing int values from lexer to parser */
  double dval;  /* used for passing double values from lexer to parser */
  char *strval;
  char *intrange;
  /* add here anything you may need */
  /*....*/  
}

%token<strval> IDENTIFIER
%token<dval> REALNUMBER
%token<ival> INTNUMBER
%token<intrange> INTRANGE

%%

program            : PROGRAM IDENTIFIER ';' {printf("#include <stdio.h>\n\n");}
                     ConstDecl
                     VarDecl
	                   FuncProcDecl
	                   {printf("int main() {\n");} CompoundStatement
	                   '.' {printf("return 0;\n}");}
                   ;

ConstDecl          : ConstDecl CONST IDENTIFIER RELOPEQ NumericValue ';' {if (intConstFlag) {printf("const int %s = %d;\n", $3, constantInt);} 
                                                                          else if (realConstFlag) {printf("const double %s = %f;\n", $3, constantReal);}}
	                 | /* epsilon */
                   ;

NumericValue       : INTNUMBER {intConstFlag = 1; constantInt = $1;}
                   | REALNUMBER {realConstFlag = 1; constantReal = $1;}
                   ;

VarDecl            : VarDecl {varEnvironment = 1;} VAR IdentifierList ':' TypeSpec ';' {varEnvironment = 0;}
	                 | /* epsilon */
                   ;

IdentifierList     : IDENTIFIER                                             {{if (varEnvironment) {addVar($1);}} if (varParamEnv) {addVarParam($1);}
                                                                            else if (paramEnvironment) {addParam($1);}
                                                                            else if (functionEnv || procedureEnv) {addFuncProcVar($1);}}
                   | IdentifierList ',' IDENTIFIER                          {{if (varEnvironment) {addVar($3);}} if (varParamEnv) {addVarParam($3);}
                                                                             else if (paramEnvironment) {addParam($3);}
                                                                             else if (functionEnv || procedureEnv) {addFuncProcVar($3);}}
                   ;

TypeSpec           : BasicType
                   | ARRAY '[' INTNUMBER RANGE INTNUMBER ']' OF {arrEnvironment = 1;} BasicType {if (varEnvironment && !(functionEnv || procedureEnv)) {printArr($3, $5, temp+2);}
                                                                                                 else if (paramEnvironment) {changeTypeArrParam($3, $5, temp);} 
                                                                                                 else if (functionEnv || procedureEnv) {printFuncVarArr($3, $5, temp);} arrEnvironment = 0;}
                   ;

BasicType          : INTEGER                                                {temp = 1; if (varEnvironment && !arrEnvironment && !(functionEnv|| procedureEnv)) {printVar(1);} 
                                                                              if (varParamEnv && !arrEnvironment) {changeTypeParam(1);}
                                                                              else if (paramEnvironment && !arrEnvironment) {changeTypeParam(1);}
                                                                              else if ((functionEnv || procedureEnv) && !arrEnvironment && !paramEnvironment) {printFuncVar(1);}}   
                   | REAL                                                   {temp = 2; if (varEnvironment && !arrEnvironment && !(functionEnv|| procedureEnv)) {printVar(2);} 
                                                                              if (varParamEnv && !arrEnvironment) {changeTypeParam(2);}
                                                                              else if (paramEnvironment && !arrEnvironment) {changeTypeParam(2);}
                                                                              else if ((functionEnv || procedureEnv) && !arrEnvironment && !paramEnvironment) {printFuncVar(2);}}  
                   ;

FuncProcDecl       : FuncProcDecl SubProgDecl ';'
                   | /* epsilon */
                   ;

SubProgDecl        : SubProgHeading VarDecl CompoundStatement { freeFuncVarArr(); freeParamArr(); printf("}\n"); functionEnv = 0; procedureEnv = 0;}
                   ;

SubProgHeading     : FUNCTION {functionEnv = 1;} IDENTIFIER Parameters ':' BasicType ';' {addFunc($3, temp); printFuncParams();}
                   | PROCEDURE {procedureEnv = 1;} IDENTIFIER {printProcedureStart($3);} PossibleParameters ';' {printProcParams();}
                   ;

PossibleParameters : Parameters
                   | /* epsilon */
                   ;

Parameters         : '('  { paramEnvironment = 1;} ParameterList {paramEnvironment = 0;} ')'
                   ;

ParameterList      : ParamList
                   | ParameterList ';' ParamList
                   ;

ParamList          : VAR {varParamEnv = 1;} IdentifierList ':' TypeSpec {varParamEnv = 0;}
                   | IdentifierList ':' TypeSpec
                   ;                  

CompoundStatement  : BEGINTOK OptionalStatements ENDTOK 
                   ;

OptionalStatements : StatementList
                   | /* epsilon */
                   ;

StatementList      : Statement
                   | StatementList ';' Statement
                   ;

Statement          : Lhs ASSIGN { assignmentEnv = 1;} ArithExpr {printf(";\n"); finalAssignment(temp3Iden, lhsArrayFlag, arithIntTemp2); lhsArrayFlag = 0; assignmentEnv = 0; temp2 = 0;}
                   | ProcedureCall
                   | CompoundStatement
                   | SKIP
                   | IF {ifGuardEnv = 1; } Guard {printf(";\n"); guardAssocs(); printNextIf(); ifGuardEnv = 0;} THEN {ifEnvironment = 1;} Statement ELSE {printNextNextIf();} Statement {ifEnvironment = 0; printFinalIf();}
                   | WHILE {whileGuardEnv = 1; startWhile();} Guard { printf(";\n"); printNextWhile(); whileGuardEnv = 0;} DO Statement {printFinalWhile();}
                   ;

Lhs                : IDENTIFIER {printTempVar($1); temp3Iden = $1;}
                   | IDENTIFIER {printTempVar($1); lhsArrayEnv = 1; temp3Iden = $1;} '[' ArithExpr ']' { lhsArrayEnv = 0; lhsArrayFlag = 1;}
                   ;

ProcedureCall      : IDENTIFIER
                   | IDENTIFIER {printf("%s(", $1); procCallEnv = 1;} '(' ArithExprList ')' {printf(");\n"); procCallEnv = 0;};
                   | READLN '(' {scanEnvironment = 1;} ArithExprList ')' {scanEnvironment = 0; finalPrintRead();}
                   | WRITELN '(' {writeEnvironment = 1;} ArithExprList ')' {writeEnvironment = 0; finalWriteRead();}
                   ;

Guard              : BoolAtom
                   | NOT { saveGuard("!");} Guard
                   | Guard OR {; saveGuard("||");} Guard
                   | Guard AND { saveGuard("&&");} Guard
                   | '(' {inBrackFlag = 1;} Guard ')' {inBrackFlag = 0;;}
                   ;

BoolAtom           : { rhsGuard = 1;} ArithExpr Relop {if (inBrackFlag) {changeTypeBrack();} rhsGuard = -1;} ArithExpr {rhsGuard = 0;}
                   ;

Relop              : RELOPLT {saveGuardSym(1); if (whileGuardEnv) {printf(" < ");}}
                   | RELOPLEQ {saveGuardSym(2); if (whileGuardEnv) {printf(" <= ");}}
                   | RELOPEQ {saveGuardSym(3); if (whileGuardEnv) {printf(" == ");}}
                   | RELOPNEQ {saveGuardSym(4); if (whileGuardEnv) {printf(" != ");}}
                   | RELOPGEQ {saveGuardSym(5); if (whileGuardEnv) {printf(" >= ");}}
                   | RELOPGT {saveGuardSym(6); if (whileGuardEnv) {printf(" > ");}}
                   ;

ArithExprList      : ArithExpr                     
                   | ArithExprList {if (procCallEnv) {printf(", ");}} ',' ArithExpr   
                   ;

ArithExpr          : IDENTIFIER {
                                if (rhsGuard == 1) {saveGuardVar($1);} else if (rhsGuard == -1) {saveGaurdVar2($1);}
                                if (procCallEnv) {varChecker2($1);}
                                // scanEnvironment = readln(ARITH) printReadVar takes iden and adds it to temporary scan array 
                                if (scanEnvironment) {printReadVar($1);} 
                                // writeEnvironment = writeln(ARITH) printWriteVar takes iden and adds it to temporary write array
                                if (writeEnvironment && !specEnvironment) {printWriteVar($1);}
                                // If you are in the write environment and within a function environment as well, add this iden to your function environment list.
                                if (writeEnvironment && specEnvironment) {addWriteFuncVar($1);}
                                // If you are in the guard and while environment, simply print the iden
                                if (whileGuardEnv) {printf("%s", $1);} 
                                // Else if you are in the assignment environment and not in the assignment of an array environment, print iden and print a new aux variable.
                                else if (assignmentEnv && !assignmentArrEnv) {varChecker($1); temp2++; nextAssignment();}
                                // If you are on the left hand side of the array, simply print the iden.
                                else if (lhsArrayEnv) {printf("%s", $1);}}
                   | IDENTIFIER {
                   // If you are in the assignment environment, check if you are doing the first assignment or the next aux variable assignments, and print the array iden.
                   if (assignmentEnv) {if (temp < 2) {printf("%s[", $1); temp2++;} else {firstAssignmentFlag = 1; printf("%s[", $1); temp2++;} }
                   // if you are in the guard environment, simply print the arr iden.
                   if (whileGuardEnv) {printf("%s[", $1);} assignmentArrEnv = 1; temp2Iden = $1; } 
                   '[' ArithExpr ']'  
                                                                                                                              { if (rhsGuard == 1) {saveGuardArr($1, arithIntTemp);}
                                                                                                                                // If you are in the assignment environment or gaurd environment, simply print the closing array bracket.
                                                                                                                                if (assignmentEnv ||  whileGuardEnv)
                                                                                                                                {printf("]");} 
                                                                                                                                // If you are in the assignment environment, print the closing bracket, end of statement and new line
                                                                                                                                else if (assignmentEnv) {printf("];\n"); nextAssignment(); }
                                                                                                                                //Now outside of array assignment environment
                                                                                                                                assignmentArrEnv = 0;
                                                                                                                                // If you are in the scan environment, add the array to your scan array along with the changed idx.
                                                                                                                                if (scanEnvironment) {printReadArr($1, arithIntTemp);}
                                                                                                                                // If you are in the write environment and not in the function environment, add the array to your scan array.
                                                                                                                                if (writeEnvironment && !specEnvironment) {printWriteArr($1, arithIntTemp);}
                                                                                                                                // If you are in the write environment and in the function environment, add the array to your function param array.
                                                                                                                                else if (writeEnvironment && specEnvironment) {addWriteFuncArr($1, arithIntTemp);} }
                   | IDENTIFIER {
                    // If you are in the write environment, add the function to your write array. 
                    if (writeEnvironment) {printWriteFunc($1);} specEnvironment = 1;}  
                    '(' ArithExprList ')' 
                    // Outside of special function param environment.
                    {specEnvironment = 0;}
                   | INTNUMBER {
                    if (rhsGuard == -1) {saveGuardVal($1, 0.0, 1);}
                    if (procCallEnv) {printf("%d", $1);}
                    // Create variable to use later in other functions when needeed.
                    arithIntTemp = $1; 
                    // If you are in the array assignment environment, add the number to a special variable.
                    if (assignmentArrEnv) {arithIntTemp2 = $1;}
                    // If you are in the gaurd environment or assignment of an array environment, print the changed idx according to the C bounds.
                    else if (whileGuardEnv && assignmentArrEnv) {changedIdxArray(temp2Iden, $1);}
                    // If you are in the gaurd environment and not in the assignment of an array environment, simply print the number.                                              
                    else if (whileGuardEnv && !assignmentArrEnv) {printf("%d", $1);}
                    // If you are purely in the assignment of an array environment, also print the changed idx.
                    if ((assignmentArrEnv && !writeEnvironment && !scanEnvironment)) {changedIdxArray(temp2Iden, $1);}
                    // Else if you are in the assignment environment, print the number.
                    else if (assignmentEnv) {printf("%d", $1);}
                    // Else if you are in the write and function environment, add the number to your function parameter array.
                    else if (writeEnvironment && specEnvironment && !assignmentArrEnv) {addWriteFuncNum($1, 0.0);}
                    }
                   | REALNUMBER {
                    if (rhsGuard == -1) {saveGuardVal(0, $1, 2);}
                    if (procCallEnv) {printf("%.1f", $1);}
                    // If you are in the gaurd or assignment environment, print the number
                    if (whileGuardEnv || assignmentEnv ) {printf("%.1f", $1);} 
                    // If you are in the write and function environment, add the number to your function parameter array.
                    else if (writeEnvironment && specEnvironment) {addWriteFuncNum(0, $1);}}
                   | ArithExpr { 
                    printf(" + ");
                   } '+'ArithExpr
                   // If we are in the auxiliary variable assignments, print a new line before each operator.
                   | ArithExpr { if (firstAssignmentFlag) {printf("\n - ");} else {printf(" - ");}} '-' ArithExpr
                   | ArithExpr { if (firstAssignmentFlag) {printf("\n * ");} else {printf(" * ");}} '*' ArithExpr
                   | ArithExpr { if (firstAssignmentFlag) {printf("\n / ");} else {printf(" / ");}} '/' ArithExpr
                   | ArithExpr { if (firstAssignmentFlag) {printf("\n / ");} else {printf(" / ");}} DIV ArithExpr
                   | ArithExpr { if (firstAssignmentFlag) {printf("\n %% ");} else {printf(" %% ");}} MOD ArithExpr
                   | {printf(" - ");} '-' ArithExpr
                   | {printf("(");} '(' ArithExpr {printf(")");} ')' 
                   ;

%%

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