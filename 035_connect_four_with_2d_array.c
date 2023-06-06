// Connect Four : 6x7 grid with 2D array

#include <stdbool.h>
#include <stdio.h>

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~

int MAX_COLUMNS = 7;
int MAX_ROWS = 6;

// struct arr {
//   char array[7];
// };
int MAX_DIAGONAL = MAX_COLUMNS > MAX_ROWS ? MAX_ROWS : MAX_COLUMNS;
char globalHorizontalArray[MAX_COLUMNS];
char globalVerticalArray[MAX_ROWS];
char globalDiagonalArray[MAX_DIAGONAL];

void extractHorizontalValues(char arr[MAX_ROWS][MAX_COLUMNS], int row) {
  for (int columnNum = 0; columnNum < MAX_COLUMNS; columnNum++) {
    globalHorizontalArray[columnNum] = arr[row][columnNum];
  }
}

void extractVerticalValues(char arr[MAX_ROWS][MAX_COLUMNS], int column) {
  for (int rowNum = 0; rowNum < MAX_COLUMNS; rowNum++) {
    globalVerticalArray[rowNum] = arr[rowNum][column];
  }
}

void extractDiagonalArray(char arr[MAX_ROWS][MAX_COLUMNS], int rowNumber, int columnChoice) {
  while ((rowNumber >= 0) && (columnChoice >= 0)) {
    rowNumber--;
    columnChoice--;
  }
  // at this point, either row or col will be at the boundary (if not both)

  while ((rowNumber < MAX_ROWS) && (columnChoice < MAX_COLUMNS)) {
    for (int HVIndex = 0;; rowNumber++, columnChoice++) {
      globalDiagonalArray[HVIndex] = arr[rowNumber][columnChoice];
    }
  }
  // at this point, the globalDiagonalArray might not be fully filled up
}

bool checkIfWonGivenSingleArray(char arrayOfValues[], int length) {
  for (int count = 0; (count + 4) < length; count++) {
    if ((arrayOfValues[count] == arrayOfValues[count + 1]) && (arrayOfValues[count] == arrayOfValues[count + 2]) && (arrayOfValues[count] == arrayOfValues[count + 3])) {
      return true;
    }
  }
  return false;
}

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~

bool checkIfPlayerHasWon(char arrayOfRows[MAX_ROWS][MAX_COLUMNS], int rowNumber, int columnChoice) {
  /*
  if (check_W_Left(arrayOfRows, rowNumber, columnChoice) || check_E_Right(arrayOfRows, rowNumber, columnChoice) || check_N_Up(arrayOfRows, rowNumber, columnChoice) || check_S_Down(arrayOfRows, rowNumber, columnChoice) || check_NW(arrayOfRows, rowNumber, columnChoice) || check_NE(arrayOfRows, rowNumber, columnChoice) || check_SW(arrayOfRows, rowNumber, columnChoice) || check_SE(arrayOfRows,
  rowNumber, columnChoice) || check_l_and_r(arrayOfRows, rowNumber, columnChoice) || check_t_and_b(arrayOfRows, rowNumber, columnChoice) || check_diagonals(arrayOfRows, rowNumber, columnChoice)) { return 'w';
  }

  else {
    return 'l';
  }
  */

  struct arr arrayOfHorizontalValues = extractHorizontalValues(arrayOfRows, rowNumber);
  struct arr arrayOfVerticalValues = createVerticalArray(arrayOfRows, columnChoice);
  struct arr arrayOfDiagonalValues = createDiagonalArray(arrayOfRows, rowNumber, columnChoice);

  bool hRes = checkIfWonGivenSingleArray(arrayOfHorizontalValues, MAX_COLUMNS);
  bool vRes = checkIfWonGivenSingleArray(arrayOfVerticalValues, MAX_ROWS);
  bool dRes = checkIfWonGivenSingleArray(arrayOfDiagonalValues, MAX_DIAGONAL);

  return hRes || vRes || dRes;
}

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~

void drawGrid(char rows[], char columns[], char arrayOfRows[MAX_ROWS][MAX_COLUMNS]) {
  printf("                Connect Four: A Game ");
  printf("\n                    Player 1: x ");
  printf("\n                    Player 2: o \n");

  for (int rowCount = 0; rowCount < MAX_ROWS; rowCount++) {
    for (int columnCount = 0; columnCount < MAX_COLUMNS;) {
      for (; arrayOfRows[rowCount][columnCount] != '\0';) {
        printf("\n   %c   |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |", rows[rowCount], arrayOfRows[rowCount][columnCount], arrayOfRows[rowCount][columnCount + 1], arrayOfRows[rowCount][columnCount + 2], arrayOfRows[rowCount][columnCount + 3], arrayOfRows[rowCount][columnCount + 4], arrayOfRows[rowCount][columnCount + 5], arrayOfRows[rowCount][columnCount + MAX_ROWS]);
        columnCount += MAX_COLUMNS;
        break;
      }
    }
    printf("\n       |-----|-----|-----|-----|-----|-----|-----|");
  }

  printf("\n\n       ");

  for (int columnCount = 0; columnCount < MAX_COLUMNS; columnCount++) {
    printf("   %c  ", columns[columnCount]);
  }

  printf("\n\n");
}

bool checkIfCellIsFilled(char cellValue) {
  return (cellValue != ' ');
}

char checkIfColumnIsFilled(char arrayOfRows[MAX_ROWS][MAX_COLUMNS], int columnChoice) {
  return checkIfCellIsFilled(arrayOfRows[0][columnChoice - 1]) ? 'y' : 'n';
}

bool markChoiceOnGrid(char rows[], char columns[], char arrayOfRows[MAX_ROWS][MAX_COLUMNS], int columnChoice, char playerNumber) {
  int rowNumber = MAX_ROWS - 1;
  for (; rowNumber >= 0; rowNumber--) {
    if (!checkIfCellIsFilled(arrayOfRows[rowNumber][columnChoice - 1])) {
      break;
    }
  }
  char res = checkIfColumnIsFilled(arrayOfRows, columnChoice);
  if (res == 'n') {
    arrayOfRows[rowNumber][columnChoice - 1] = ((playerNumber == '1') ? 'x' : 'o');
  }

  drawGrid(rows, columns, arrayOfRows);

  // ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~

  if (checkIfPlayerHasWon(arrayOfRows, rowNumber, (columnChoice - 1))) {
    printf("Congrats, Player %c! You have won! ", playerNumber);
    return true;
  } else {
    return false;
  }
  // ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~
}

int main() {
  char rows[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
  char columns[] = {'1', '2', '3', '4', '5', '6', '7', '\0'};
  char arrayOfRows[MAX_ROWS][MAX_COLUMNS] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}};
  drawGrid(rows, columns, arrayOfRows);

  int columnChoice;
  int countMoves;
  char resultOfCheckIfColumnIsFilled;

  for (countMoves = 1; countMoves <= 42; countMoves++) {
    if (countMoves % 2 != 0) {
      printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");
      printf("Player 1 (x): Enter your choice of column number: ");
      scanf("%i", &columnChoice);
      printf("\n");

      while ((columnChoice < 1) || (MAX_COLUMNS < columnChoice)) {
        printf("Invalid choice. Select another, Player 1.");
        scanf("%d", &columnChoice);
      }

      resultOfCheckIfColumnIsFilled = checkIfColumnIsFilled(arrayOfRows, columnChoice);

      while (resultOfCheckIfColumnIsFilled == 'y') {
        printf("Invalid choice. Select another, Player 1.");
        scanf("%d", &columnChoice);
        resultOfCheckIfColumnIsFilled = checkIfColumnIsFilled(arrayOfRows, columnChoice);
      }

      bool res = markChoiceOnGrid(rows, columns, arrayOfRows, columnChoice, '1');
      if (res) {
        break;
      }
    } else {
      printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");
      printf("Player 2 (o): Enter your choice of column number: ");
      scanf("%i", &columnChoice);
      printf("\n");

      while ((columnChoice < 1) || (MAX_COLUMNS < columnChoice)) {
        printf("Invalid choice. Select another, Player 2.");
        scanf("%d", &columnChoice);
      }

      resultOfCheckIfColumnIsFilled = checkIfColumnIsFilled(arrayOfRows, columnChoice);

      while (resultOfCheckIfColumnIsFilled == 'y') {
        printf("Invalid choice. Select another, Player 2.");
        scanf("%d", &columnChoice);
        resultOfCheckIfColumnIsFilled = checkIfColumnIsFilled(arrayOfRows, columnChoice);
      }

      bool res = markChoiceOnGrid(rows, columns, arrayOfRows, columnChoice, '2');
      if (res) {
        break;
      }
    }
  }
}

/*
                Connect Four: A Game
                    Player 1: x
                    Player 2: o

   a   |     |     |     |     |     |     |     |
       |-----|-----|-----|-----|-----|-----|-----|
   b   |     |     |     |     |     |     |     |
       |-----|-----|-----|-----|-----|-----|-----|
   c   |     |     |     |     |  o  |     |     |
       |-----|-----|-----|-----|-----|-----|-----|
   d   |     |  o  |  x  |     |  x  |  o  |     |
       |-----|-----|-----|-----|-----|-----|-----|
   e   |     |  x  |  o  |     |  x  |  x  |     |
       |-----|-----|-----|-----|-----|-----|-----|
   f   |  x  |  o  |  x  |     |  o  |  o  |  x  |
       |-----|-----|-----|-----|-----|-----|-----|

          1     2     3     4     5     6     7

Congrats, Player 1! You have won! %
*/
