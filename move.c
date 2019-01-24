//
// Created by kevin on 11/16/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include "move.h"
#include "win.h"
#include "inputValidation.h"
#include "board.h"

int askForMove(int numCols){
  int userCol = 0;
  printf("Enter a column between 0 and %d to play in: ", numCols - 1);

  userCol = getPosCol(userCol);
  return userCol;
}
bool isMoveValid(int userCol, int totCols){
  if ((userCol >= 0) && (userCol <= totCols - 1) && (userCol != 100)){
    return true;
  }
  else
    return false;
}
bool isColFilled(int numRows, int col, char** board){
  for (int row = numRows - 1; row >= 0; --row){
    if (board[row][col] != '*'){
      continue;
    }
    else{
      return false;
    }
  }
  return true;
}
/* player 1 -> true -> X
 *  player 2 -> false -> O
 */
void makeMove(int numRows, int moveCol, bool player, char** board){
  for (int row = numRows - 1; row >= 0; --row){
    if (board[row][moveCol] == '*'){
      if (player) {
        board[row][moveCol] = 'X';
        break;
      }
      else {
        board[row][moveCol] = 'O';
        break;
      }
    }
  }
}
void playGame(int numRows, int numCols, int piecesToWin, char** board){
  int userMoveCol = 0;
  int numMoves = 0;

  // player 1 starts
  bool currentPlayer = true;

  while (true){
    char winChar;
      if (!gameWon(numRows, numCols, piecesToWin, board, &winChar)) {
        userMoveCol = askForMove(numCols);
        if (isMoveValid(userMoveCol, numCols)) {
          if (!isColFilled(numRows, userMoveCol, board)) {
            numMoves++;
            makeMove(numRows, userMoveCol, currentPlayer, board);
            currentPlayer = !currentPlayer;
            printBoard(numRows, numCols, board);
          } else {
            continue;
          }
        } else {
          continue;
        }
      }
      else{
        whoWon(&winChar);
        destroyBoard(numRows, board);
        exit(0);
      }
      if (numMoves == numRows * numCols){
        printf("Tie game!");
        destroyBoard(numRows, board);
        exit(0);
      }
  }
}


