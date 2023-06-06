// Connect Four : 6x7 grid with 2D array

#include <stdio.h>

char check_W_Left(char grid[6][7], int rowNumber, int columnChoice) {
  /*
  if ((grid[rowNumber][columnChoice] == grid[rowNumber][columnChoice - 1]) && (grid[rowNumber][columnChoice] == grid[rowNumber][columnChoice - 2]) && (grid[rowNumber][columnChoice] == grid[rowNumber][columnChoice - 3])) {
    return 'w';
  }
  */

  int count = 0;
  for (int adjacent = 1; adjacent < 4; adjacent++) {
    if (grid[rowNumber][columnChoice] == grid[rowNumber][columnChoice - adjacent]) {
      count++;
    }
  }

  if (count == 3) {
    return 'w';
  }

  else {
    return 'l';
  }
}
char check_E_Right(char grid[6][7], int rowNumber, int columnChoice) {
  if ((grid[rowNumber][columnChoice] == grid[rowNumber][columnChoice + 1]) && (grid[rowNumber][columnChoice] == grid[rowNumber][columnChoice + 2]) && (grid[rowNumber][columnChoice] == grid[rowNumber][columnChoice + 3])) {
    return 'w';
  }

  else {
    return 'l';
  }
}
char check_N_Top(char grid[6][7], int rowNumber, int columnChoice) {
  if ((grid[rowNumber][columnChoice] == grid[rowNumber - 1][columnChoice]) && (grid[rowNumber][columnChoice] == grid[rowNumber - 2][columnChoice]) && (grid[rowNumber][columnChoice] == grid[rowNumber - 3][columnChoice])) {
    return 'w';
  }

  else {
    return 'l';
  }
}
char check_S_Down(char grid[6][7], int rowNumber, int columnChoice) {
  if ((grid[rowNumber][columnChoice] == grid[rowNumber + 1][columnChoice]) && (grid[rowNumber][columnChoice] == grid[rowNumber + 2][columnChoice]) && (grid[rowNumber][columnChoice] == grid[rowNumber + 3][columnChoice])) {
    return 'w';
  }

  else {
    return 'l';
  }
}
char check_NW(char grid[6][7], int rowNumber, int columnChoice) {
  if ((grid[rowNumber][columnChoice] == grid[rowNumber - 1][columnChoice - 1]) && (grid[rowNumber][columnChoice] == grid[rowNumber - 2][columnChoice - 2]) && (grid[rowNumber][columnChoice] == grid[rowNumber - 3][columnChoice - 3])) {
    return 'w';
  }

  else {
    return 'l';
  }
}
char check_NE(char grid[6][7], int rowNumber, int columnChoice) {
  if ((grid[rowNumber][columnChoice] == grid[rowNumber - 1][columnChoice + 1]) && (grid[rowNumber][columnChoice] == grid[rowNumber - 2][columnChoice + 2]) && (grid[rowNumber][columnChoice] == grid[rowNumber - 3][columnChoice + 3])) {
    return 'w';
  }

  else {
    return 'l';
  }
}
char check_SW(char grid[6][7], int rowNumber, int columnChoice) {
  if ((grid[rowNumber][columnChoice] == grid[rowNumber + 1][columnChoice - 1]) && (grid[rowNumber][columnChoice] == grid[rowNumber + 2][columnChoice - 2]) && (grid[rowNumber][columnChoice] == grid[rowNumber + 3][columnChoice - 3])) {
    return 'w';
  }

  else {
    return 'l';
  }
}
char check_SE(char grid[6][7], int rowNumber, int columnChoice) {
  if ((grid[rowNumber][columnChoice] == grid[rowNumber + 1][columnChoice + 1]) && (grid[rowNumber][columnChoice] == grid[rowNumber + 2][columnChoice + 2]) && (grid[rowNumber][columnChoice] == grid[rowNumber + 3][columnChoice + 3])) {
    return 'w';
  }

  else {
    return 'l';
  }
}

char checkIfPlayerHasWon(char grid[6][7], int rowNumber, int columnChoice) {
  if ((check_W_Left(grid, rowNumber, columnChoice) == 'w') || (check_E_Right(grid, rowNumber, columnChoice) == 'w') || (check_N_Top(grid, rowNumber, columnChoice) == 'w') || (check_S_Down(grid, rowNumber, columnChoice) == 'w') || (check_NW(grid, rowNumber, columnChoice) == 'w') || (check_NE(grid, rowNumber, columnChoice) == 'w') || (check_SW(grid, rowNumber, columnChoice) == 'w') || (check_SE(grid, rowNumber, columnChoice) == 'w')) {
    return 'w';
  }

  else {
    return 'l';
  }
}

void drawGrid(char rows[], char columns[], char grid[6][7]) {
  printf("                Connect Four: A Game ");
  printf("\n                    Player 1: x ");
  printf("\n                    Player 2: o \n");

  for (int rowCount = 0; rowCount < 6; rowCount++) {
    for (int columnCount = 0; columnCount < 7;) {
      for (; grid[rowCount][columnCount] != '\0';) {
        printf("\n   %c   |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |", rows[rowCount], grid[rowCount][columnCount], grid[rowCount][columnCount + 1], grid[rowCount][columnCount + 2], grid[rowCount][columnCount + 3], grid[rowCount][columnCount + 4], grid[rowCount][columnCount + 5], grid[rowCount][columnCount + 6]);
        columnCount += 7;
        break;
      }
    }
    printf("\n       |-----|-----|-----|-----|-----|-----|-----|");
  }

  printf("\n\n       ");

  for (int columnCount = 0; columnCount < 7; columnCount++) {
    printf("   %c  ", columns[columnCount]);
  }

  printf("\n\n");
}

char checkIfFilled(char grid[6][7], int columnChoice) {
  if ((grid[0][columnChoice - 1] == 'x') || (grid[0][columnChoice - 1] == 'o')) {
    return 'y';
  }

  else {
    return 'n';
  }
}

char markChoiceOnGrid(char rows[], char columns[], char grid[6][7], int columnChoice, char playerNumber) {

  int rowNumber = 0;
  for (; grid[rowNumber][columnChoice] != '\0'; rowNumber++) {
    if (((grid[rowNumber][columnChoice]) != 'x') || ((grid[rowNumber][columnChoice]) != 'o')) {
      if (playerNumber == '1') {
        grid[rowNumber][columnChoice] = 'x';
        break;
      }

      else if (playerNumber == '2') {
        grid[rowNumber][columnChoice] = 'o';
        break;
      }
    }
  }

  drawGrid(rows, columns, grid);

  // ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~

  char res = checkIfPlayerHasWon(grid, rowNumber, columnChoice);

  if (res == 'w') {
    printf("Congrats, Player %c! You have won! ", playerNumber);
    return 'w';
  }

  else {
    return 'l';
  }
  // ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~
}

int main() {
  char rows[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
  char columns[] = {'1', '2', '3', '4', '5', '6', '7', '\0'};
  char grid[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}};
  drawGrid(rows, columns, grid);

  int columnChoice;
  int countMoves;
  char resultOfCheckIfFilled;

  for (countMoves = 1; countMoves <= 42; countMoves++) {
    if (countMoves % 2 != 0) {
      printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");
      printf("Player 1 (x): Enter your choice of column number: ");
      scanf("%i", &columnChoice);
      printf("\n");

      while ((columnChoice < 1) || (7 < columnChoice)) {
        printf("Invalid choice. Select another, Player 1.");
        scanf("%d", &columnChoice);
      }

      resultOfCheckIfFilled = checkIfFilled(grid, columnChoice);

      while (resultOfCheckIfFilled == 'y') {
        printf("Invalid choice. Select another, Player 1.");
        scanf("%d", &columnChoice);
        resultOfCheckIfFilled = checkIfFilled(grid, columnChoice);
      }

      char res = markChoiceOnGrid(rows, columns, grid, columnChoice, '1');
      if (res == 'w') {
        break;
      }
    }

    else {
      printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");
      printf("Player 2 (o): Enter your choice of column number: ");
      scanf("%i", &columnChoice);
      printf("\n");

      while ((columnChoice < 1) || (7 < columnChoice)) {
        printf("Invalid choice. Select another, Player 2.");
        scanf("%d", &columnChoice);
      }

      resultOfCheckIfFilled = checkIfFilled(grid, columnChoice);

      while (resultOfCheckIfFilled == 'y') {
        printf("Invalid choice. Select another, Player 2.");
        scanf("%d", &columnChoice);
        resultOfCheckIfFilled = checkIfFilled(grid, columnChoice);
      }

      char res = markChoiceOnGrid(rows, columns, grid, columnChoice, '2');
      if (res == 'w') {
        break;
      }
    }
  }
}
