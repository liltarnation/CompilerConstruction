#define HELPER_H

void addVar(char* var);

void printVar(int type);

void printArr(int lBound, int hBound, int type);

void printReadVar(char* var);

void printReadArr(char* var, int idx);

void finalPrintRead();

void printFunctionStart();

void printProcedureStart(char* var);

void addVarParam(char *var);

void addFunc(char *name, int type);

void changeTypeArrParam(int lBound, int uBound, int type);

void addParam(char *var);

void changeTypeParam(int type);

void printFuncParams();

void printProcParams();

void freeParamArr();

void addFuncProcVar(char *name);

void printFuncVar(int type);

void printFuncVarArr(int lBound, int hBound, int type);

void freeFuncVarArr();

void startWhile();

void printComparison(int type);

void printNextWhile();

void printFinalWhile();

void printCheckVariable(char* var);

void printAlteredArrIdx(char* var, int num);

void changedIdxArray(char* var, int num);

void printWriteVar(char* var);

void printWriteArr(char* var, int idx);

void finalWriteRead();

void startIf();

void printNextIf();

void printNextNextIf();

void printFinalIf();

void printTempVar(char *var);

void finalAssignment(char* var, int flag, int idx);

void nextAssignment();

void addWriteFuncNum(int num, double num2);

void addWriteFuncArr(char* name, int idx);

void addWriteFuncVar(char* name);

void printWriteFunc(char* var);

void saveGaurdVal(int intNum, double dubNum, int type);

void saveGuardSym(int type);

void saveGuardArr(char* var, int idx);

void saveGuardVar(char* var);

void saveGuardVal(int intNum, double dubNum, int type);

void guardAssocs();

void changeTypeBrack();

void saveGuard(char* type);

void saveGaurdVar2(char* name);

void varChecker(char* name);

void varChecker2(char* name);