//
// Created by kevin on 11/16/2017.
//
#include <stdbool.h>
#ifndef CONNECTN_INPUTVALIDATION_H
#define CONNECTN_INPUTVALIDATION_H

int getPosCol(int userCol);
void validateCmdLine(int argc, char * argv[], int * rowPtr, int * colPtr, int * piecesPtr);

#endif //CONNECTN_INPUTVALIDATION_H
