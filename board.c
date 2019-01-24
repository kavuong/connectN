//
// Created by kevin on 11/16/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
char** createBoard(int numRows, int numCols){
  char** output_board = (char**)(malloc(numRows * sizeof(char*)));
  /*
   * blank space (*)
   * player one (X)
   * player two (O)
   */
  for (int row = 0; row < numRows; ++row){
    output_board[row] = (char*)(malloc(numCols * sizeof(char)));
    for (int col = 0; col < numCols; ++col){
      output_board[row][col] = '*';
    }
  }
  return output_board;
}

void printBoard(int numRows, int numCols, char** board){
  for (int row = 0; row < numRows; ++row){
    if ((numRows - row - 1) < 10) {
      printf(" %d ", numRows - row - 1);
    }
    else{
      printf("%d ", numRows - row - 1);
    }

    for (int col = 0; col < numCols; ++col){
      printf("%c ", board[row][col]);
    }
    printf("\n");

  }
  printf("  ");

  for (int col = 0; col < numCols; ++col){
    printf("%d ", col);
  }
}

void destroyBoard(int numRows, char** board){
  for (int row = 0; row < numRows; ++row){
    free(board[row]);
  }
  free(board);
  board = NULL;
}
