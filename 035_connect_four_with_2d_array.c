// Connect Four : 6x7 grid with 2D array

#include <stdbool.h>
#include <stdio.h>

char globalHorizontalArray[8];
char globalVerticalArray[7];
char globalDiagonalArrayLeft[((8 > 7) ? 7 : 8)];
char globalDiagonalArrayRight[((8 > 7) ? 7 : 8)];

void extractHorizontalValues(char arr[6][7], int row) {
  for (int columnNum = 0; columnNum < 7; columnNum++) {
    globalHorizontalArray[columnNum] = arr[row][columnNum];
  }
  globalHorizontalArray[7] = '\0';
}

void extractVerticalValues(char arr[6][7], int column) {
  for (int rowNum = 0; rowNum < 6; rowNum++) {
    globalVerticalArray[rowNum] = arr[rowNum][column];
  }
  globalVerticalArray[6] = '\0';
}

void extractDiagonalValuesFromLeftMargin(char arr[6][7], int rowNumber, int columnChoice) {
  while ((rowNumber > 0) && (columnChoice > 0)) {
    rowNumber--;
    columnChoice--;
  }
  // at this point, either row or column will be at the boundary (if not both)

  int HVIndex = 0;

  while ((rowNumber < 6) && (columnChoice < 7)) {
    globalDiagonalArrayLeft[HVIndex] = arr[rowNumber][columnChoice];
    rowNumber++;
    columnChoice++;
    HVIndex++;
  }
  // at this point, the globalDiagonalArrayLeft might not be fully filled up

  globalDiagonalArrayLeft[HVIndex] = '\0';
}

void extractDiagonalValuesFromRightMargin(char arr[6][7], int rowNumber, int columnChoice) {
  while ((rowNumber > 0) && (columnChoice < 7)) {
    rowNumber--;
    columnChoice++;
  }
  // at this point, either row or column will be at the boundary (if not both)

  int HVIndex = 0;

  while ((rowNumber < 6) && (columnChoice >= 0)) {
    globalDiagonalArrayRight[HVIndex] = arr[rowNumber][columnChoice];
    rowNumber++;
    columnChoice--;
    HVIndex++;
  }
  // at this point, the globalDiagonalArrayRight might not be fully filled up

  globalDiagonalArrayRight[HVIndex] = '\0';
}

bool checkIf4PresentInAnyOrder(char arrayOfValues[], char playerNumber) {
  int indexOfArrayOfValues = 0;
  char cellValue = ((playerNumber == '1') ? 'x' : 'o');
  int countIfMin4 = 0;

  while (arrayOfValues[indexOfArrayOfValues] != '\0') {
    if (arrayOfValues[indexOfArrayOfValues] == cellValue) {
      countIfMin4 += 1;
    }
    indexOfArrayOfValues++;
  }
  return (countIfMin4 >= 4);
}

bool checkIfWonGivenSingleArray(char arrayOfValues[], int length) {
  for (int count = 0; (count + 4) <= length; count++) {
    if ((arrayOfValues[count] != ' ') && (arrayOfValues[count] == arrayOfValues[count + 1]) && (arrayOfValues[count] == arrayOfValues[count + 2]) && (arrayOfValues[count] == arrayOfValues[count + 3])) {
      return true;
    }
  }
  return false;
}

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~

bool checkIfPlayerHasWon(char arrayOfRows[6][7], int rowNumber, int columnChoice, char playerNumber) {
  extractHorizontalValues(arrayOfRows, rowNumber);
  extractVerticalValues(arrayOfRows, columnChoice);
  extractDiagonalValuesFromLeftMargin(arrayOfRows, rowNumber, columnChoice);
  extractDiagonalValuesFromRightMargin(arrayOfRows, rowNumber, columnChoice);

  bool hRes = false;
  bool vRes = false;
  bool dResL = false;
  bool dResR = false;

  if (checkIf4PresentInAnyOrder(globalHorizontalArray, playerNumber)) {
    hRes = checkIfWonGivenSingleArray(globalHorizontalArray, 8);
  }

  if (checkIf4PresentInAnyOrder(globalVerticalArray, playerNumber)) {
    vRes = checkIfWonGivenSingleArray(globalVerticalArray, 7);
  }

  if (checkIf4PresentInAnyOrder(globalDiagonalArrayLeft, playerNumber)) {
    dResL = checkIfWonGivenSingleArray(globalDiagonalArrayLeft, ((8 > 7) ? 7 : 8));
  }

  if (checkIf4PresentInAnyOrder(globalDiagonalArrayRight, playerNumber)) {
    dResR = checkIfWonGivenSingleArray(globalDiagonalArrayRight, ((8 > 7) ? 7 : 8));
  }

  return (hRes || vRes || dResL || dResR);
}

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~

void drawGrid(char rows[], char columns[], char arrayOfRows[6][7]) {
  printf("                Connect Four: A Game ");
  printf("\n                    Player 1: x ");
  printf("\n                    Player 2: o \n");

  for (int rowCount = 0; rowCount < 6; rowCount++) {
    for (int columnCount = 0; columnCount < 7;) {
      for (; arrayOfRows[rowCount][columnCount] != '\0';) {
        printf("\n   %c   |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |", rows[rowCount], arrayOfRows[rowCount][columnCount], arrayOfRows[rowCount][columnCount + 1], arrayOfRows[rowCount][columnCount + 2], arrayOfRows[rowCount][columnCount + 3], arrayOfRows[rowCount][columnCount + 4], arrayOfRows[rowCount][columnCount + 5], arrayOfRows[rowCount][columnCount + 6]);
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

bool checkIfCellIsFilled(char cellValue) {
  return (cellValue != ' ');
}

char checkIfColumnIsFilled(char arrayOfRows[6][7], int columnChoice) {
  return checkIfCellIsFilled(arrayOfRows[0][columnChoice - 1]) ? 'y' : 'n';
}

bool markChoiceOnGrid(char rows[], char columns[], char arrayOfRows[6][7], int columnChoice, char playerNumber) {
  int rowNumber = 5;
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

  if (checkIfPlayerHasWon(arrayOfRows, rowNumber, (columnChoice - 1), playerNumber)) {
    printf("Congrats, Player %c! You have won!", playerNumber);
    return true;
  } else {
    return false;
  }

  // ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~
}

int promptForColumnChoice(char playerNumber) {
  int columnChoice;
  printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");
  printf("Player %c (%c): Enter your choice of column number: ", playerNumber, ((playerNumber == '1') ? 'x' : 'o'));
  scanf("%i", &columnChoice);
  printf("\n");

  while ((columnChoice < 1) || (7 < columnChoice)) {
    printf("Invalid choice. Select another, Player %c.", playerNumber);
    scanf("%d", &columnChoice);
  }
  return columnChoice;
}

int main() {
  char rows[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
  char columns[] = {'1', '2', '3', '4', '5', '6', '7', '\0'};
  char arrayOfRows[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}};
  drawGrid(rows, columns, arrayOfRows);

  int columnChoice;
  int countMoves;
  char resultOfCheckIfColumnIsFilled;

  for (countMoves = 1; countMoves <= 42; countMoves++) {
    if (countMoves % 2 != 0) {
      columnChoice = promptForColumnChoice('1');

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
      columnChoice = promptForColumnChoice('2');

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
