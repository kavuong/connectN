//
// Created by kevin on 11/16/2017.
//
#include <stdbool.h>

#ifndef CONNECTN_WIN_H
#define CONNECTN_WIN_H
bool checkArrayVals(int piecesToWin, char* valsToCheck);
char horzWin(int numRows, int numCols, int piecesToWin, char ** board);
char vertWin(int numRows, int numCols, int piecesToWin, char ** board);
char diagWin(int numRows, int numCols, int piecesToWin, char ** board);
char leftDiagWin(int numRows, int numCols, int piecesToWin, char ** board);
char rightDiagWin(int numRows, int numCols, int piecesToWin, char ** board);

void whoWon(char * character);
bool gameWon(int numRows, int numCols, int piecesToWin, char ** board, char * winChar);
#endif //CONNECTN_WIN_H
