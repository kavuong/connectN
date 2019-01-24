#include <stdio.h>
#include "board.h"
#include "move.h"
#include "inputValidation.h"

int main(int argc, char * argv[]) {
  // FIX LATER: ALL PLACEHOLDER FOR MAKEFILE
  int userRows;
  int userCols;
  int userPiecesToWin;
  validateCmdLine(argc, argv, &userRows, &userCols, &userPiecesToWin);

  char** userBoard = createBoard(userRows, userCols);
  printBoard(userRows, userCols, userBoard);
  printf("\n");
  playGame(userRows, userCols, userPiecesToWin, userBoard);
  // ADD DESTROY BOARD FUNCTION TO game_over and game_won AT END
  return 0;
}