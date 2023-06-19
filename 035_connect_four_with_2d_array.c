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

bool checkIf4PresentInAnyOrder(char arrayOfValues[], char cellValue) {
  int indexOfArrayOfValues = 0;
  int countIfMin4 = 0;

  while (arrayOfValues[indexOfArrayOfValues] != '\0') {
    if (arrayOfValues[indexOfArrayOfValues] == cellValue) {
      countIfMin4++;
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

bool checkIfPlayerHasWon(char arrayOfRows[6][7], int rowNumber, int columnChoice, char cellValue) {
  extractHorizontalValues(arrayOfRows, rowNumber);
  extractVerticalValues(arrayOfRows, columnChoice);
  extractDiagonalValuesFromLeftMargin(arrayOfRows, rowNumber, columnChoice);
  extractDiagonalValuesFromRightMargin(arrayOfRows, rowNumber, columnChoice);

  bool hRes = checkIf4PresentInAnyOrder(globalHorizontalArray, cellValue) && checkIfWonGivenSingleArray(globalHorizontalArray, 8);
  bool vRes = checkIf4PresentInAnyOrder(globalVerticalArray, cellValue) && checkIfWonGivenSingleArray(globalVerticalArray, 7);
  bool dResL = checkIf4PresentInAnyOrder(globalDiagonalArrayLeft, cellValue) && checkIfWonGivenSingleArray(globalDiagonalArrayLeft, ((8 > 7) ? 7 : 8));
  bool dResR = checkIf4PresentInAnyOrder(globalDiagonalArrayRight, cellValue) && checkIfWonGivenSingleArray(globalDiagonalArrayRight, ((8 > 7) ? 7 : 8));

  return (hRes || vRes || dResL || dResR);
}

char playersToken(int playerNumber) {
  return (playerNumber == 1) ? 'x' : 'o';
}

void drawGrid(char rows[], char columns[], char arrayOfRows[6][7]) {
  printf("                Connect Four: A Game ");
  printf("\n                    Player 1: %c ", playersToken(1));
  printf("\n                    Player 2: %c \n", playersToken(2));

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

bool checkIfColumnIsFilled(char arrayOfRows[6][7], int columnChoice) {
  return checkIfCellIsFilled(arrayOfRows[0][columnChoice - 1]);
}

bool markChoiceOnGrid(char rows[], char columns[], char arrayOfRows[6][7], int columnChoice, int playerNumber) {
  int rowNumber = 5;
  for (; rowNumber >= 0; rowNumber--) {
    if (!checkIfCellIsFilled(arrayOfRows[rowNumber][columnChoice - 1])) {
      break;
    }
  }
  bool res = checkIfColumnIsFilled(arrayOfRows, columnChoice);
  char cellValue = playersToken(playerNumber);
  if (res == false) {
    arrayOfRows[rowNumber][columnChoice - 1] = cellValue;
  }

  drawGrid(rows, columns, arrayOfRows);

  return checkIfPlayerHasWon(arrayOfRows, rowNumber, (columnChoice - 1), cellValue);
}

int promptForColumnChoice(char arrayOfRows[6][7], int playerNumber) {
  int columnChoice;
  printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");
  printf("Player %i (%c): Enter your choice of column number: ", playerNumber, playersToken(playerNumber));
  scanf("%i", &columnChoice);
  printf("\n");

  while ((columnChoice < 1) || (7 < columnChoice)) {
    printf("Invalid choice. Select another, Player %c: ", playerNumber);
    scanf("%i", &columnChoice);
  }

  bool resultOfCheckIfColumnIsFilled = checkIfColumnIsFilled(arrayOfRows, columnChoice);
  while (resultOfCheckIfColumnIsFilled) {
    printf("Invalid choice. Select another, Player %c: ", playerNumber);
    scanf("%i", &columnChoice);
    resultOfCheckIfColumnIsFilled = checkIfColumnIsFilled(arrayOfRows, columnChoice);
  }
  return columnChoice;
}

int main() {
  char rows[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
  char columns[] = {'1', '2', '3', '4', '5', '6', '7', '\0'};
  char arrayOfRows[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '}};
  drawGrid(rows, columns, arrayOfRows);

  for (int countMoves = 1; countMoves <= 42; countMoves++) {
    int playerNumber = (countMoves % 2 != 0) ? 1 : 2;
    int columnChoice = promptForColumnChoice(arrayOfRows, playerNumber);
    if (markChoiceOnGrid(rows, columns, arrayOfRows, columnChoice, playerNumber)) {
      printf("Congrats, Player %i! You have won!\n", playerNumber);
      break;
    }
  }
}
