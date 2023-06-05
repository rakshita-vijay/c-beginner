// Connect Four : 6x7 grid

#include <stdio.h>
char checkIfPlayerHasWon(char grid[], char playerNumber, int gridNumber) {
  return 'w';
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

void markChoiceOnGrid(char rows[], char columns[], char grid[], int columnChoice, char playerNumber) {
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

  char res = checkIfPlayerHasWon(grid, playerNumber, gridNumber);

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

      markChoiceOnGrid(rows, columns, grid, columnChoice, '1');
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

      markChoiceOnGrid(rows, columns, grid, columnChoice, '2');
    }
  }
}
