//
// Created by kevin on 11/16/2017.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "win.h"

// checks if row/col/diagonal are composed of same elements
bool checkArrayVals(int piecesToWin, char* valsToCheck){
  // checks if characters in valsToCheck are the same starting from second element
  for (int i = 1; i < piecesToWin; ++i){
    if (valsToCheck[i] == valsToCheck[0] && valsToCheck[i] != '*'){
      continue;
    }
    else{
      return false;
    }
  }
  return true;
}
char horzWin(int numRows, int numCols, int piecesToWin, char** board){
  int numIterations = numCols - piecesToWin + 1;
  int j = 0;
  for (int row = 0; row < numRows; ++row) {
    for (int i = 0; i < numIterations; ++i) {
      char valesToCompare[100];
      for (j = 0; j < piecesToWin; ++j) {
        (valesToCompare)[j] = board[row][i + j];
      }
      // strings need to be terminated with NULL CHARACTER
      valesToCompare[strlen(valesToCompare)] = '\0';
      if (checkArrayVals(piecesToWin, valesToCompare)){
        // j - 1 because ++j in for loop updates j after the fact
        return valesToCompare[j - 1];
      }
    }
  }
  return '\0';
}
char vertWin(int numRows, int numCols, int piecesToWin, char ** board){
  int numIterations = numRows - piecesToWin + 1;
  int j = 0;
  for (int col = 0; col < numCols; ++col){
    for (int i = 0; i < numIterations; ++i){
      char valesToCompare[100];
      for (j = 0; j < piecesToWin; ++j){
        valesToCompare[j] = board[i + j][col];
      }
      valesToCompare[strlen(valesToCompare)] = '\0';
      if (checkArrayVals(piecesToWin, valesToCompare)){
        return valesToCompare[j - 1];
      }
    }
  }
  return '\0';
}
/*
 * CLARIFICATION: FOr wins that look like this
 * O
 *  O
 *   O
 */


char leftDiagWin(int numRows, int numCols, int piecesToWin, char ** board){
  int rowIterations = numRows - piecesToWin + 1;
  int colIterations = numCols - piecesToWin + 1;
  int rowStart = 0;
  for (int rowIter = 0; rowIter < rowIterations; rowIter++){
    int colStart = 0;
    for (int colIter = 0; colIter < colIterations; colIter++){
      int index = 0;
      char valesToCompare[100];
      int copyRow = rowStart;
      int copyCol = colStart;
      for (index = 0; index < piecesToWin; ++index){
        valesToCompare[index] = board[copyRow][copyCol];
        copyRow++;
        copyCol++;
      }

      valesToCompare[strlen(valesToCompare)] = '\0';
      if (checkArrayVals(piecesToWin, valesToCompare)){
        return valesToCompare[index - 1];
      }
      colStart++;
    }
    rowStart++;
  }
  return '\0';
}



/*
 * CLARIFICATION: FOr wins that look like this
 *   O
 *  O
 * O
 */


char rightDiagWin(int numRows, int numCols, int piecesToWin, char ** board){
    int rowIterations = numRows - piecesToWin + 1;
    int colIterations = numCols - piecesToWin + 1;
    int rowStart = 0;
    for (int rowIter = 0; rowIter < rowIterations; rowIter++){
      int colStart = piecesToWin - 1;
      for (int colIter = 0; colIter < colIterations; colIter++){
        int index = 0;
        char valesToCompare[100];
        int copyRow = rowStart;
        int copyCol = colStart;
        for (index = 0; index < piecesToWin; ++index){
          valesToCompare[index] = board[copyRow][copyCol];
          copyRow++;
          copyCol--;
        }

        valesToCompare[strlen(valesToCompare)] = '\0';
        if (checkArrayVals(piecesToWin, valesToCompare)){
          return valesToCompare[index - 1];
        }
        colStart++;
      }
      rowStart++;
    }
  return '\0';
  }




char diagWin(int numRows, int numCols, int piecesToWin, char ** board){
  char leftDiagChar = leftDiagWin(numRows, numCols, piecesToWin, board);
  char rightDiagChar = rightDiagWin(numRows, numCols, piecesToWin, board);
  if (rightDiagChar != '\0'){
    return rightDiagChar;
  }

  else if (leftDiagChar != '\0'){
    return leftDiagChar;
  }



  else{
    return '\0';
  }
}

void whoWon(char * character){
  if (*character == 'X'){
    printf("\nPlayer 1 Won!");
  }
  else if (*character == 'O'){
    printf("\nPlayer 2 Won!");
  }
  else{
    printf("Error pls");
  }
}

bool gameWon(int numRows, int numCols, int piecesToWin, char ** board, char * winChar){
  if (piecesToWin > numRows && piecesToWin > numCols) {
    return false;
  }
  else{
    *winChar = '\0';
    if (numCols >= piecesToWin) {
      *winChar = horzWin(numRows, numCols, piecesToWin, board);
      if (*winChar != '\0')
        return true;
    }
    if (numRows >= piecesToWin){
      *winChar = vertWin(numRows, numCols, piecesToWin, board);
      if (*winChar != '\0')
        return true;
    }

    if (numRows >= piecesToWin && numCols >= piecesToWin){
      *winChar = diagWin(numRows, numCols, piecesToWin, board);
    }


    if (*winChar == '\0'){
      return false;
    }
    else return true;
  }


}



