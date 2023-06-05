// Connect Four : 6x7 grid

#include <stdio.h>

char check_W_Left(char grid[], int gridNumberForCoder) {
  if ((grid[gridNumberForCoder] == grid[gridNumberForCoder - 1]) && (grid[gridNumberForCoder] == grid[gridNumberForCoder - 2]) && (grid[gridNumberForCoder] == grid[gridNumberForCoder - 3])) {
    return 'w';
  }

  else {
    return 'l';
  }
}
char check_E_Right(char grid[], int gridNumberForCoder) {
  if ((grid[gridNumberForCoder] == grid[gridNumberForCoder + 1]) && (grid[gridNumberForCoder] == grid[gridNumberForCoder + 2]) && (grid[gridNumberForCoder] == grid[gridNumberForCoder + 3])) {
    return 'w';
  }

  else {
    return 'l';
  }
}
char check_N_Top(char grid[], int gridNumberForCoder) {
  if ((grid[gridNumberForCoder] == grid[gridNumberForCoder - 7]) && (grid[gridNumberForCoder] == grid[gridNumberForCoder - 14]) && (grid[gridNumberForCoder] == grid[gridNumberForCoder - 21])) {
    return 'w';
  }

  else {
    return 'l';
  }
}
char check_S_Down(char grid[], int gridNumberForCoder) {
  if ((grid[gridNumberForCoder] == grid[gridNumberForCoder + 7]) && (grid[gridNumberForCoder] == grid[gridNumberForCoder + 14]) && (grid[gridNumberForCoder] == grid[gridNumberForCoder + 21])) {
    return 'w';
  }

  else {
    return 'l';
  }
}
char check_NW(char grid[], int gridNumberForCoder) {
  if ((grid[gridNumberForCoder] == grid[gridNumberForCoder - 8]) && (grid[gridNumberForCoder] == grid[gridNumberForCoder - 16]) && (grid[gridNumberForCoder] == grid[gridNumberForCoder - 24])) {
    return 'w';
  }

  else {
    return 'l';
  }
}
char check_NE(char grid[], int gridNumberForCoder) {
  if ((grid[gridNumberForCoder] == grid[gridNumberForCoder - 6]) && (grid[gridNumberForCoder] == grid[gridNumberForCoder - 12]) && (grid[gridNumberForCoder] == grid[gridNumberForCoder - 18])) {
    return 'w';
  }

  else {
    return 'l';
  }
}
char check_SW(char grid[], int gridNumberForCoder) {
  if ((grid[gridNumberForCoder] == grid[gridNumberForCoder + 6]) && (grid[gridNumberForCoder] == grid[gridNumberForCoder + 12]) && (grid[gridNumberForCoder] == grid[gridNumberForCoder + 18])) {
    return 'w';
  }

  else {
    return 'l';
  }
}
char check_SE(char grid[], int gridNumberForCoder) {
  if ((grid[gridNumberForCoder] == grid[gridNumberForCoder + 8]) && (grid[gridNumberForCoder] == grid[gridNumberForCoder + 16]) && (grid[gridNumberForCoder] == grid[gridNumberForCoder + 24])) {
    return 'w';
  }

  else {
    return 'l';
  }
}

char checkIfPlayerHasWon(char grid[], int gridNumber) {
  char choice;

  int gridNumberForCoder = gridNumber - 1;

  if ((check_W_Left(grid, gridNumberForCoder) == 'w') || (check_E_Right(grid, gridNumberForCoder) == 'w') || (check_N_Top(grid, gridNumberForCoder) == 'w') || (check_S_Down(grid, gridNumberForCoder) == 'w') || (check_NW(grid, gridNumberForCoder) == 'w') || (check_NE(grid, gridNumberForCoder) == 'w') || (check_SW(grid, gridNumberForCoder) == 'w') || (check_SE(grid, gridNumberForCoder) == 'w')) {
    return 'w';
  }

  else {
    return 'l';
  }
}

void drawGrid(char rows[], char columns[], char grid[]) {
  printf("                Connect Four: A Game ");
  printf("\n                    Player 1: x ");
  printf("\n                    Player 2: o \n");

  int gridCount = 0;

  for (int rowCount = 0; rowCount < 6; rowCount++) {
    for (; grid[gridCount] != '\0';) {
      printf("\n   %c   |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |", rows[rowCount], grid[gridCount], grid[gridCount + 1], grid[gridCount + 2], grid[gridCount + 3], grid[gridCount + 4], grid[gridCount + 5], grid[gridCount + 6]);
      gridCount += 7;
      break;
    }
    printf("\n       |-----|-----|-----|-----|-----|-----|-----|");
  }

  printf("\n\n       ");

  for (int columnCount = 0; columnCount < 7; columnCount++) {
    printf("   %c  ", columns[columnCount]);
  }

  printf("\n\n");
}

char checkIfFilled(char grid[], int columnChoice) {
  if ((grid[columnChoice - 1] == 'x') || (grid[columnChoice - 1] == 'o')) {
    return 'y';
  }

  else {
    return 'n';
  }
}

char markChoiceOnGrid(char rows[], char columns[], char grid[], int columnChoice, char playerNumber) {
  int gridNumber = columnChoice + 35; // c*(r-1)
  for (; gridNumber >= 1; gridNumber -= 7) {
    char res = checkIfFilled(grid, gridNumber);
    if (res == 'n') {
      if (playerNumber == '1') {
        grid[gridNumber - 1] = 'x';
        break;
      }

      else if (playerNumber == '2') {
        grid[gridNumber - 1] = 'o';
        break;
      }
    }
  }
  drawGrid(rows, columns, grid);

  // ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~

  char res = checkIfPlayerHasWon(grid, gridNumber);

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
  char grid[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'};
  // char grid[] = {'a', ' ', ' ', ' ', ' ', ' ', ' ', 'b', ' ', ' ', ' ', ' ', ' ', ' ', 'c', ' ', ' ', ' ', ' ', ' ', ' ', 'd', ' ', ' ', ' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', 'f', ' ', ' ', ' ', ' ', ' ', 'g', '\0'};
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
