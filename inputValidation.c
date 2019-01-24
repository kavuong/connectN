//
// Created by kevin on 11/16/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include "inputValidation.h"

int getPosCol(int userCol) {
  scanf("%d", &userCol);
  if (userCol >= 0) {
    return userCol;
  }
  else{
    return 100;
  }
}

void validateCmdLine(int argc, char ** argv, int * rowPtr, int * colPtr, int * piecesPtr){
  if (argc < 4){
    printf("Not enough arguments entered \nUsage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
    exit(0);
  }
  else if (argc > 4){
    printf("Too many arguments entered \nUsage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
    exit(0);
  }
  else{
    sscanf(argv[1], "%d", rowPtr);
    sscanf(argv[2], "%d", colPtr);
    sscanf(argv[3], "%d", piecesPtr);
  }
}