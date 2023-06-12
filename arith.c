#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Temp = 0, Integer = 1, Real = 2, IntegerArr = 3, RealArr = 4

typedef struct Variable{
    char* name;
    int type;
    int lBound;
} Variable;

typedef struct TemporaryArray {
    char* name;
    int idx;
    int type;
    int potInt;
    double potReal;
    int funcFlag;
    int arrFlag;
} TemporaryArray;

typedef struct Parameters {
    char* name;
    int type;
    int variable;
    int lBound;
    int aSize;
} Parameters;

typedef struct Functions {
    char *name;
    int type;
    char* varName;
    int varTrue;
} Functions;

typedef struct FuncVars {
    char *name;
    int type;
    int lBound;
} FuncVars;

typedef struct Labels {
    int flabel;
    int slabel;
} Labels;

typedef struct AuxVars {
    int type;
} AuxVars;

typedef struct guardTrips {
    char* iden1;
    char* typeGuard;
    int val2Int;
    double val2Double;
    char* iden2;
    int iden2flag;
    int valType;
    int potIdx;
    int arrayFlag;
    int inBrack;
} guardTrips;
 

Variable variable[100];
int varIdx = 0;
TemporaryArray tempArr[100];
int arrIdx = 0;
Parameters params[100];
int paramIdx = 0;
Functions func[100];
int funcIdx = 0;
FuncVars funcVar[100];
int funcVarIdx = 0;
Labels labels[100];
int labelIdx = 0;
int tempVar = 0;
TemporaryArray tempArr2[100];
int tempArrIdx2 = 0;
TemporaryArray tempArrFuncVars[100];
int tempAFV = 0;
Labels labels2[100];
int labelIdx2 = 0;
AuxVars auxVars[100];
int auxVarIdx = 0;
guardTrips guards[100];
int guardTripsIdx = 0;
int tempVar;
char* boolAtoms;
char* posGuards[100];
int posGuardsIdx = 0;
int guardCounter = 0;

void addVar(char* var){
    variable[varIdx].name = var;
    variable[varIdx].type = 0;
    varIdx++;
}

void printVar(int type){
    if (type == 1){
        printf("int ");
    } else if (type == 2){
        printf("double ");
    }
    for (int i = 0; i < varIdx; i++){
        if (variable[i].type == 0 && i != varIdx-1){
            variable[i].type = type;
            printf("%s, ", variable[i].name);
        } else if (variable[i].type == 0 && i == varIdx-1) {
            variable[i].type = type;
            printf("%s;\n", variable[i].name);            
        }
    }
}

void printArr(int lowerB, int upperB, int type){
    int arraySize = upperB - lowerB + 1;
     if (type == 3){
        printf("int ");
    } else if (type == 4){
        printf("double ");
    }
    for (int i = 0; i < varIdx; i++){
        if (variable[i].type == 0 && i != varIdx-1){
            variable[i].type = type;
            variable[i].lBound = lowerB;
            printf("%s[%d], ", variable[i].name, arraySize);
        } else if (variable[i].type == 0 && i == varIdx-1) {
            variable[i].type = type;
            variable[i].lBound = lowerB;
            printf("%s[%d];\n", variable[i].name, arraySize);            
        }
    }
}

void printReadVar(char* var) {
    for (int i = 0; i < varIdx; i++){
        if (strcmp(var, variable[i].name) == 0){
            tempArr[arrIdx].name = variable[i].name;
            tempArr[arrIdx].idx = -1;
            if (variable[i].type == 1){
                tempArr[arrIdx].type = 1;
            } else if (variable[i].type == 2){
                tempArr[arrIdx].type = 2;
            }
            arrIdx++;
        }
    }
}

void printReadArr(char* var, int idx) {
    for (int i = 0; i < varIdx; i++){
        if (strcmp(var, variable[i].name) == 0){
            if (variable[i].type == 3){
                tempArr[arrIdx].name = variable[i].name;
                tempArr[arrIdx].idx = idx-variable[i].lBound;
                tempArr[arrIdx].type = 3;
                arrIdx++;
            } else if (variable[i].type == 4){
                tempArr[arrIdx].name = variable[i].name;
                tempArr[arrIdx].idx = idx-variable[i].lBound;
                tempArr[arrIdx].type = 4;
                arrIdx++;
            }
        }
    }
}

void finalPrintRead(){
    printf("scanf(\"");
    for (int i = 0; i < arrIdx; i++){
        if (i != arrIdx-1){
            if (tempArr[i].type == 1){
                printf("%%d ");
            } else if (tempArr[i].type == 2){
                printf("%%lf ");
            } else if (tempArr[i].type == 3) {
                printf("%%d ");                
            } else if (tempArr[i].type == 4) {
                printf("%%lf ");                
            }
        } else {
            if (tempArr[i].type == 1 || tempArr[i].type == 3){
                printf("%%d");
            } else if (tempArr[i].type == 2 || tempArr[i].type == 4){
                printf("%%lf");
            }
        }
    }
    printf("\", ");
    for (int i = 0; i < arrIdx; i++){
        if (tempArr[i].idx == -1){
            if (i == arrIdx-1){
                printf("&%s", tempArr[i].name);
            } else{
                printf("&%s, ", tempArr[i].name);  
            }
        } else {
            if (i == arrIdx-1){
                printf("&%s[%d]", tempArr[i].name, tempArr[i].idx);
            } else{
                printf("&%s[%d], ", tempArr[i].name, tempArr[i].idx); 
            }
        }
    }
    printf(");\n");
    arrIdx = 0;
}

void printFunctionStart(){
    if (func[funcIdx-1].type == 1){
        printf("int %s(", func[funcIdx-1].name);
    } else if (func[funcIdx-1].type == 2) {
        printf("double %s(", func[funcIdx-1].name);
    }
}

void printProcedureStart(char* var){
    printf("void %s(", var);
}

void addVarParam(char *var) {
    params[paramIdx].name = var;
    params[paramIdx].type = 0;
    params[paramIdx].variable = 1;
    paramIdx++;
}

void addParam(char *var) {
    params[paramIdx].name = var;
    params[paramIdx].type = 0;
    params[paramIdx].variable = 0;
    paramIdx++;
}

void changeTypeParam(int type) {
    if (type == 1){
        params[paramIdx-1].type = 1;
        if (params[paramIdx-2].type == 0){
            params[paramIdx-2].type = 1;
        }
    } else if (type == 2){
        params[paramIdx-1].type = 2;
        if (params[paramIdx-2].type == 0){
            params[paramIdx-2].type = 2;
        }              
    }
}

void changeTypeArrParam(int lBound, int uBound, int type){
    params[paramIdx-1].aSize = uBound - lBound + 1;
    params[paramIdx-1].type = type+2;
    params[paramIdx-1].lBound = lBound;
}

void addFunc(char *name, int type){
    func[funcIdx].name = name;    
    if (type == 1){
        func[funcIdx].type = 1;
    } if (type == 2){
        func[funcIdx].type = 2;
    }
    funcIdx++;
}

void printFuncParams() {
    if (func[funcIdx-1].type == 1){
        printf("int %s(", func[funcIdx-1].name);
    } else if (func[funcIdx-1].type == 2) {
        printf("double %s(", func[funcIdx-1].name);
    }
    for (int i = 0; i < paramIdx; i++){
        if (i != paramIdx-1){
            if (params[i].type == 1){
                if (params[i].variable == 1){
                    tempVar = i;
                    printf("int *%s, ", params[i].name);
                } else {
                    printf("int %s, ", params[i].name);
                }
            } else if (params[i].type == 2){
                if (params[i].variable == 1){
                    printf("double *%s, ", params[i].name);
                    tempVar = i;
                } else {
                    printf("double %s, ", params[i].name);
                }            
            } else if (params[i].type == 3){
                printf("int %s[%d], ", params[i].name, params[i].aSize);
            } else if (params[i].type == 4){
                printf("double %s[%d], ", params[i].name, params[i].aSize);
            }
        } else {
            if (params[i].type == 1){
                if (params[i].variable == 1){
                    printf("int *%s", params[i].name);
                } else {
                    printf("int %s", params[i].name);
                }
            } else if (params[i].type == 2){
                if (params[i].variable == 1){
                    printf("double *%s", params[i].name);
                } else {
                    printf("double %s", params[i].name);
                }            
            } else if (params[i].type == 3){
                printf("int %s[%d]", params[i].name, params[i].aSize);
            } else if (params[i].type == 4){
                printf("double %s[%d]", params[i].name, params[i].aSize);
            }            
        }
    }
    printf(") {\n");
}

void printProcParams() {
    for (int i = 0; i < paramIdx; i++){
        if (i != paramIdx-1){
            if (params[i].type == 1){
                if (params[i].variable == 1){
                    printf("int *%s, ", params[i].name);
                    func[funcIdx-1].varName = params[i].name;
                    func[funcIdx-1].varTrue = 1;
                } else {
                    printf("int %s, ", params[i].name);
                }
            } else if (params[i].type == 2){
                if (params[i].variable == 1){
                    printf("double *%s, ", params[i].name);
                    func[funcIdx-1].varName = params[i].name;
                    func[funcIdx-1].varTrue = 1;                   
                } else {
                    printf("double %s, ", params[i].name);
                }            
            } else if (params[i].type == 3){
                printf("int %s[%d], ", params[i].name, params[i].aSize);
            } else if (params[i].type == 4){
                printf("double %s[%d], ", params[i].name, params[i].aSize);
            }
        } else {
            if (params[i].type == 1){
                if (params[i].variable == 1){
                    printf("int *%s", params[i].name);
                } else {
                    printf("int %s", params[i].name);
                }
            } else if (params[i].type == 2){
                if (params[i].variable == 1){
                    printf("double *%s", params[i].name);
                } else {
                    printf("double %s", params[i].name);
                }            
            } else if (params[i].type == 3){
                printf("int %s[%d]", params[i].name, params[i].aSize);
            } else if (params[i].type == 4){
                printf("double %s[%d]", params[i].name, params[i].aSize);
            }            
        }
    }
    printf(") {\n");
}

void freeParamArr(){
    paramIdx = 0;
    params[paramIdx].type = 0;
}

void addFuncProcVar(char *name) {
    funcVar[funcVarIdx].name = name;
    funcVar[funcVarIdx].type = 0;
    funcVarIdx++;
}

void printFuncVar(int type) {
    if (type == 1 && funcVarIdx != 0){
        printf("int ");
    } else if (type ==  2 && funcVarIdx != 0){
        printf("double ");
    }
    for (int i = 0; i < funcVarIdx; i++) {
        if (funcVar[i].type == 0 && i != funcVarIdx-1){
            funcVar[i].type = type;
            printf("%s, ", funcVar[i].name);
        } else if (funcVar[i].type == 0 && i == funcVarIdx-1) {
            funcVar[i].type = type;
            printf("%s;\n", funcVar[i].name);
        }
    }
}

void printFuncVarArr(int lBound, int hBound, int type) {
    int arraySize = hBound - lBound + 1;
    if (type == 1 && funcVarIdx != 0){
        printf("int ");
    } else if (type ==  2 && funcVarIdx != 0) {
        printf("double ");
    }
    for (int i = 0; i < funcVarIdx; i++) {
        if (funcVar[i].type == 0 && i != funcVarIdx-1){
            funcVar[i].type = type+2;
            funcVar[i].lBound = lBound;
            printf("%s[%d], ",funcVar[i].name, arraySize);
        } else if (funcVar[i].type == 0 && i == funcVarIdx-1) {
            funcVar[i].type = type+2;
            funcVar[i].lBound = lBound;
            printf("%s[%d];\n", funcVar[i].name, arraySize);
        }
    }
}

void freeFuncVarArr() {
    funcVarIdx = 0;
    funcVar[funcVarIdx].type = 0;
}

void startWhile() {
    labels[labelIdx].flabel = 2*labelIdx;
    printf("lbl%d : ;\n  int _t%d = ", labels[labelIdx].flabel, auxVarIdx);
    labelIdx++;
    auxVars[auxVarIdx].type = 1;
    auxVarIdx++;
}

void printComparison(int type){
    if (type == 1){
        printf(" < ");
    } else if (type == 2) {
        printf(" <= ");
    } else if (type == 3) {
        printf(" == ");
    } else if (type == 4) {
        printf(" <> ");
    } else if (type == 5) {
        printf(" >= ");
    } else if (type == 6) {
        printf(" > ");
    }
}

void printNextWhile(){
    printf("if (!_t%d) goto lbl%d;\n", auxVarIdx-1, labels[labelIdx-1].flabel+1);
}

void printFinalWhile(){
    printf("  goto lbl%d;\nlbl%d : ;\n", labels[tempVar].flabel, labels[tempVar].flabel+1);
    tempVar++;
}

void printCheckVariable(char* var){
    int yesFlag = 0;
    for (int i = 0; i < paramIdx; i++){
        if (strcmp(var, params[i].name) == 0 && params[i].variable == 1){
            printf("&%s", params[i].name);
            yesFlag = 1;
        } else if (strcmp(var, params[i].name) == 0 && params[i].variable == 0){
            printf("%s", params[i].name);
            yesFlag = 1;
        }
    }
    if (!yesFlag) {
        printf("%s", var);
    }
}

void printAlteredArrIdx(char* var, int num) {
    int yesFlag = 0;
    for (int i = 0; i < paramIdx; i++){
        if (strcmp(var, params[i].name) == 0){
            printf("%s[%d]", params[i].name, num-params[i].lBound);
            yesFlag = 1;
            break;
        }
    }
    if (!yesFlag){
        for (int i = 0; i < varIdx; i++){
            if (strcmp(var, variable[i].name) == 0){
                printf("%s[%d]", variable[i].name, num-variable[i].lBound);
                break;
            }
        }        
    }    
}

void changedIdxArray(char* var, int num){
    int yesFlag = 0;
    for (int i = 0; i < paramIdx; i++){
        if (strcmp(var, params[i].name) == 0){
            printf("%d", num-params[i].lBound);
            yesFlag = 1;
            break;
        }
    }
    if (!yesFlag){
        for (int i = 0; i < varIdx; i++){
            if (strcmp(var, variable[i].name) == 0){
                printf("%d", num-variable[i].lBound);
                yesFlag = 1;
                break;
            }
        }        
    }
}

void printWriteVar(char* var) {
    for (int i = 0; i < varIdx; i++){
        if (strcmp(var, variable[i].name) == 0){
            tempArr2[tempArrIdx2].name = variable[i].name;
            tempArr2[tempArrIdx2].idx = -1;
            tempArr2[tempArrIdx2].type = variable[i].type;
            tempArrIdx2++;
        }
    }
}

void printWriteArr(char* var, int idx) {
    for (int i = 0; i < varIdx; i++){
        if (strcmp(var, variable[i].name) == 0){
            if (variable[i].type == 3){
                tempArr2[tempArrIdx2].name = variable[i].name;
                tempArr2[tempArrIdx2].idx = idx-variable[i].lBound;
                tempArr2[tempArrIdx2].type = 3;
                tempArrIdx2++;
            } else if (variable[i].type == 4){
                tempArr2[tempArrIdx2].name = variable[i].name;
                tempArr2[tempArrIdx2].idx = idx-variable[i].lBound;
                tempArr2[tempArrIdx2].type = 4;
                tempArrIdx2++;
            }
        }
    }
}

void printWriteFunc(char* var) {
    for (int i = 0; i < varIdx; i++){
        if (strcmp(var, func[i].name) == 0){
            tempArr2[tempArrIdx2].name = var;
            tempArr2[tempArrIdx2].idx = -1;
            tempArr2[tempArrIdx2].type = func[funcIdx-1].type;
            tempArr2[tempArrIdx2].funcFlag = 1;
            tempArrIdx2++;
        }
    }
}

void finalWriteRead(){
    printf("printf(\"");
    for (int i = 0; i < tempArrIdx2; i++){
        if (i != tempArrIdx2-1){
            if (tempArr2[i].type == 1 || tempArr2[i].type == 3){
                printf("%%d ");
            } else if (tempArr2[i].type == 2 || tempArr2[i].type == 4){
                printf("%%lf ");
            }
        } else {
            if (tempArr2[i].type == 1 || tempArr2[i].type == 3){
                printf("%%d\\n");
            } else if (tempArr2[i].type == 2 || tempArr2[i].type == 4){
                printf("%%lf\\n");
            }
        }
    }
    printf("\", ");
    for (int i = 0; i < tempArrIdx2; i++){
        if (tempArr2[i].funcFlag == 1){
            printf("%s(", tempArr2[i].name);
            for (int y = 0; y < tempAFV; y++){
                if (y != tempAFV-1){
                    if (strcmp(tempArrFuncVars[y].name, "REAL") == 0) {
                        printf("%.1f, ", tempArrFuncVars[y].potReal);
                    } else if (strcmp(tempArrFuncVars[y].name, "INTEGER") == 0) {
                        printf("%d, ", tempArrFuncVars[y].potInt);
                    } else if (tempArrFuncVars[y].arrFlag == 1){
                    printf("%s[%d], ", tempArrFuncVars[y].name, tempArrFuncVars[y].idx); 
                    } else {
                    printf("%s, ", tempArrFuncVars[y].name);  
                    }               
                } else {
                    if (strcmp(tempArrFuncVars[y].name, "REAL") == 0) {
                    printf("%.1f", tempArrFuncVars[y].potReal); 
                    } else if (strcmp(tempArrFuncVars[y].name, "INTEGER") == 0) {
                    printf("%d", tempArrFuncVars[y].potInt);
                    } else if (tempArrFuncVars[y].arrFlag == 1) {
                    printf("%s[%d]", tempArrFuncVars[y].name, tempArrFuncVars[y].idx);
                    } else {
                    printf("%s", tempArrFuncVars[y].name);                     
                    }       
                }
            }
            if (i == tempArrIdx2-1){
                printf(")");
            } else {
                printf("), ");
            }
        } else {
            if (tempArr2[i].idx == -1){
                if (i == tempArrIdx2-1){
                    printf("%s", tempArr2[i].name);
                } else{
                    printf("%s, ", tempArr2[i].name);  
                }
            } else {
                if (i == tempArrIdx2-1){
                    printf("%s[%d]", tempArr2[i].name, tempArr2[i].idx);
                } else{
                    printf("%s[%d], ", tempArr2[i].name, tempArr2[i].idx); 
                }
            }            
        }
    }
    for (int i = 0; i < tempArrIdx2; i++){
        tempArr2[i].funcFlag = 0;
        tempArr2[i].arrFlag = 0;
    }
    funcVarIdx = 0;
    tempAFV = 0;
    printf(");\n");
    tempArrIdx2 = 0;
}

void startIf() {
    labels[labelIdx].flabel = 2*labelIdx;
    printf("int _t%d = ", auxVarIdx);
    labelIdx++;
    auxVars[auxVarIdx].type = 1;
    auxVarIdx++;
}

void printNextIf() {
    printf("if (!_t%d) goto lbl%d;\n", auxVarIdx-1, labels[labelIdx-1].flabel);    
}

void printNextNextIf() {
    printf("goto lbl%d;\nlbl%d : ;\n", labels[labelIdx-1].flabel+1, labels[labelIdx-1].flabel);
}

void printFinalIf() {
    printf("lbl%d : ;\n", labels[labelIdx-1].flabel+1);
}

void printTempVar(char *var) {
    int yesFlag = 0;
    for (int i = 0; i < varIdx; i++){
            if (strcmp(var, variable[i].name) == 0){
            yesFlag = 1;
            if (variable[i].type == 1){
                auxVars[auxVarIdx].type = 1;
                printf("int _t%d = ", auxVarIdx);
            } else if (variable[i].type == 2) {
                auxVars[auxVarIdx].type = 2;
                printf("double _t%d = ", auxVarIdx);
            } else if (variable[i].type == 3){
                auxVars[auxVarIdx].type = 1;
                printf("int _t%d = ", auxVarIdx);
            } else if (variable[i].type == 4) {
                auxVars[auxVarIdx].type = 2;
                printf("double _t%d = ", auxVarIdx);
            }
            break;
        }
    }
    if (!yesFlag){
        for (int i = 0; i < paramIdx; i++){
            if (strcmp(var, params[i].name) == 0){
                yesFlag = 1;
                if (params[i].type == 1){
                    printf("int _t%d = ", auxVarIdx);
                    auxVars[auxVarIdx].type = 1;
                } else if (params[i].type == 2) {
                    printf("double _t%d = ", auxVarIdx);
                    auxVars[auxVarIdx].type = 2;
                } else if (params[i].type == 3){
                    printf("int _t%d = ", auxVarIdx);
                    auxVars[auxVarIdx].type = 1;
                } else if (params[i].type == 4) {
                    printf("double _t%d = ", auxVarIdx);
                    auxVars[auxVarIdx].type = 2;
                }
                break;
            }
        }        
    }
    if (!yesFlag) {
        if (func[funcIdx-1].type == 1){
            printf("int _t%d = ", auxVarIdx);
            auxVars[auxVarIdx].type = 1;
        } else if (func[funcIdx-1].type == 2) {
            auxVars[auxVarIdx].type = 2;
            printf("double _t%d = ", auxVarIdx);
        }
    }        
    auxVarIdx++;
}

void finalAssignment(char* var, int flag, int idx) {
    int yesFlag = 0;
    if (flag) {
        printf("%s[", var);
        for (int i = 0; i < paramIdx; i++){
            if (strcmp(var, params[i].name) == 0){
                printf("%d", idx-params[i].lBound);
                yesFlag = 1;
                break;
            }
        }
        if (!yesFlag){
            for (int i = 0; i < varIdx; i++){
                if (strcmp(var, variable[i].name) == 0){
                    printf("%d", idx-variable[i].lBound);
                    yesFlag = 1;
                    break;
                }
            }        
        }
        printf("] = _t%d;\n", auxVarIdx-1);
    } else {
        for (int i = 0; i < funcIdx; i++) {
            if (strcmp(var, func[i].name) == 0){
                printf("return _t%d;\n", auxVarIdx-1);
                yesFlag = 1;
                break;
            }
        }
        if (!yesFlag){
            for (int i = 0; i < paramIdx; i++){
                yesFlag = 1;
                if (strcmp(var, params[i].name) == 0 && params[i].variable == 1){
                    printf("*%s = _t%d;\n", var, auxVarIdx-1);
                    break;
                } else if (strcmp(var, params[i].name) == 0 && params[i].variable == 0) {
                    printf("%s = _t%d;\n", var, auxVarIdx-1);
                }
            }
            if (!yesFlag){
                printf("%s = _t%d;\n", var, auxVarIdx-1);
            }
        }
    }

}

void nextAssignment() {
    if (auxVars[auxVarIdx-1].type == 1){
        printf("int _t%d = _t%d", auxVarIdx, auxVarIdx-1);
        auxVars[auxVarIdx].type = 1;
    } else if (auxVars[auxVarIdx-1].type == 2) {
        printf("double _t%d = _t%d", auxVarIdx, auxVarIdx-1);
        auxVars[auxVarIdx].type = 2;
    }
    auxVarIdx++;
}

void addWriteFuncVar(char* name) {
    tempArrFuncVars[tempAFV].name = name;
    tempArrFuncVars[tempAFV].idx = -1;
    tempAFV++;
}

void addWriteFuncArr(char* name, int idx) {
    for (int i = 0; i < varIdx; i++){
        if (strcmp(name, variable[i].name) == 0){
                tempArrFuncVars[tempAFV].name = variable[i].name;
                tempArrFuncVars[tempAFV].idx = idx-variable[i].lBound;
                tempArrFuncVars[tempAFV].arrFlag = 1;
        }
    }
    tempAFV++;
}

void addWriteFuncNum(int num, double num2){
    if (num == 0){
        tempArrFuncVars[tempAFV].name = "REAL";
        tempArrFuncVars[tempAFV].potReal = num2;
    } else {
        tempArrFuncVars[tempAFV].name = "INTEGER";
        tempArrFuncVars[tempAFV].potInt = num;
    }
    tempAFV++;
}

void saveGuardVar(char* var){
    guards[guardTripsIdx].iden1 = var;
}

void saveGuardArr(char* var, int idx) {
    int yesFlag = 0;
    for (int i = 0; i < paramIdx; i++){
        if (strcmp(var, params[i].name) == 0){
            guards[guardTripsIdx].potIdx = idx-params[i].lBound-1;
            yesFlag = 1;
            break;
        }
    }
    if (!yesFlag){
        for (int i = 0; i < varIdx; i++){
            if (strcmp(var, variable[i].name) == 0){
                guards[guardTripsIdx].potIdx = idx-params[i].lBound-1;
                yesFlag = 1;
                break;
            }
        }        
    }
    guards[guardTripsIdx].iden1 = var;
    guards[guardTripsIdx].arrayFlag = 1;
}

// 1 = LT, 2 = LEQ, 3 = EQ, 4 = NEQ, 5 = GEQ, 6 = GT
void saveGuardSym(int type){
    if (type == 1){
        guards[guardTripsIdx].typeGuard = "<";
    } else if (type == 2){
        guards[guardTripsIdx].typeGuard = "<=";
    } else if (type == 3){
        guards[guardTripsIdx].typeGuard = "==";
    } else if (type == 4){
        guards[guardTripsIdx].typeGuard = "!=";
    } else if (type == 5){
        guards[guardTripsIdx].typeGuard = ">=";
    } else if (type == 6){
        guards[guardTripsIdx].typeGuard = ">";
    }
}

void saveGuardVal(int intNum, double dubNum, int type){
    if (type == 1){
        guards[guardTripsIdx].valType = 1;
        guards[guardTripsIdx].val2Int = intNum;
    } else if (type == 2){
        guards[guardTripsIdx].valType = 2;
        guards[guardTripsIdx].val2Double = dubNum;        
    }
    guardTripsIdx++;
}

void guardAssocs() {
    for (int i = 0; i < guardTripsIdx; i++){
        if (guards[i].valType == 1){
            if (guards[i].arrayFlag == 1) {
                printf("int _t%d = %s[%d] %s %d;\n", 
                auxVarIdx, guards[i].iden1, guards[i].potIdx,
                guards[i].typeGuard, guards[i].val2Int);
                auxVarIdx++;
                guardCounter++;
            } else {
                printf("int _t%d = %s %s %d;\n", 
                auxVarIdx, guards[i].iden1, guards[i].typeGuard,
                guards[i].val2Int);
                auxVarIdx++;
                guardCounter++;
            }
        } else if (guards[i].valType == 2) {
            if (guards[i].arrayFlag == 1) {
                printf("int _t%d = %s[%d] %s %.1lf;\n", 
                auxVarIdx, guards[i].iden1, guards[i].potIdx,
                guards[i].typeGuard, guards[i].val2Double);
                auxVarIdx++;
                guardCounter++;
            } else {
                printf("int _t%d = %s %s %.1lf;\n", 
                auxVarIdx, guards[i].iden1, guards[i].typeGuard,
                guards[i].val2Double);
                auxVarIdx++;
                guardCounter++;
            }            
        } 
    }
    int temp = auxVarIdx-guardCounter;
    int temp2;
    int temp3;
    if (guardTripsIdx > 1){
            printf("int _t%d = _t%d %s _t%d;\n", auxVarIdx, temp, posGuards[0], temp+1);
            auxVarIdx++;
            temp2 = auxVarIdx-1;
        for (int i = 0; i < guardTripsIdx; i++){
            if (guards[i].inBrack == 1){
                temp = i;
                break;
            }
        }
        printf("int _t%d = _t%d %s _t%d;\n", auxVarIdx, temp, posGuards[temp+1], temp+1);
        auxVarIdx++;
        for (int i = temp+2; i < guardTripsIdx; i++){
            printf("int _t%d = _t%d %s _t%d;\n", auxVarIdx, auxVarIdx-1 , posGuards[i], i);
            auxVarIdx++;
            if (i == guardTripsIdx-1){
                for (int i = 0; i < posGuardsIdx; i++){
                    if (strcmp(posGuards[i], "!") == 0) {
                        temp3 = i-1;
                        printf("_t%d = !_t%d;\n", auxVarIdx-1, auxVarIdx-1);
                    }
                }
            }
            
        }
        printf("int _t%d = _t%d %s _t%d;\n", auxVarIdx, auxVarIdx-1, posGuards[temp3], temp2);
        auxVarIdx++;
    }

}

void changeTypeBrack() {
    guards[guardTripsIdx].inBrack = 1;
}

void saveGuard(char* type) {
    posGuards[posGuardsIdx] = type;
    posGuardsIdx++;
}

void saveGaurdVar2(char* name){
    guards[guardTripsIdx].iden2 = name;
    guards[guardTripsIdx].iden2flag = 1;
    guardTripsIdx++;
}

void varChecker(char* name){
    int yesFlag = 0;
    for (int i = 0; i < paramIdx; i++){
        if (strcmp(name, params[i].name) == 0 && params[i].variable == 1){
            printf("*%s;\n", params[i].name);
            yesFlag = 1;
            break;
        }
    }
    if (!yesFlag){
        printf("%s;\n", name);
    }
}

void varChecker2(char* name){
    if (func[funcIdx-1].varTrue == 1){
        if (strcmp(name, func[funcIdx-1].varName) == 0){
            printf("&%s", name);
        } else {
            printf("%s", name);
        }
    } else {
        printf("%s", name);
    }
}