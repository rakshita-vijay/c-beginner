// Connect Four : 6x7 grid

#include <stdio.h>

void drawGrid(char rows[], char columns[]) {
  printf("Connect Four: A Game");
  printf("\n    Player 1: x");
  printf("\n    Player 2: o \n");

  for (int rowCount = 0; rowCount < 6; rowCount++) {
    for (int columnCount = 0; columnCount < 7; columnCount++) {
      printf("\n|  %c%c  |  %c%c  |  %c%c  |  %c%c  |  %c%c  |  %c%c  |  %c%c  |", rows[rowCount], columns[columnCount], rows[rowCount], columns[columnCount + 1], rows[rowCount], columns[columnCount + 2], rows[rowCount], columns[columnCount + 3], rows[rowCount], columns[columnCount + 4], rows[rowCount], columns[columnCount + 5], rows[rowCount], columns[columnCount + 6]);
      printf("\n|------|------|------|------|------|------|------|");
      break;
    }
  }
}

char checkIfFilled(char rows[], int columnChoice) {
  /*for (int rowCount = 5; rowCount >= 0; rowCount--) {
    if rows
      [rowCount]
  }
  return res;
  */
}

int main() {
  char rows[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
  char columns[] = {'1', '2', '3', '4', '5', '6', '7', '\0'};
  drawGrid(rows, columns);

  int columnChoice;
  int countMoves;
  char resutOfCheckIfFilled = 'n';

  for (countMoves = 1; countMoves <= 42; countMoves++) {
    if (countMoves % 2 != 0) {
      printf("Player 1 (x): Enter your choice of column number: ");
      scanf("%i", &columnChoice);
      printf("\n");
      resutOfCheckIfFilled = checkIfFilled(rows, columnChoice);
    } else {
      printf("Player 2 (o): Enter your choice of column number: ");
      scanf("%i", &columnChoice);
      printf("\n");
      resutOfCheckIfFilled = checkIfFilled(rows, columnChoice);
    }
  }
}
