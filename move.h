//
// Created by kevin on 11/16/2017.
//
#include <stdbool.h>
#ifndef CONNECTN_MOVE_H
#define CONNECTN_MOVE_H
int askForMove(int numCols);
bool isMoveValid(int userCol, int totCols);
bool isColFilled(int numRows, int col, char** board);
void makeMove(int numRows, int moveCol, bool player, char** board);
void playGame(int numRows, int numCols, int piecesToWin, char** board);

#endif //CONNECTN_MOVE_H
