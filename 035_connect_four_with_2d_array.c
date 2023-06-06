// Connect Four : 6x7 grid with 2D array

#include <stdbool.h>
#include <stdio.h>

bool check_W_Left(char arrayOfRows[6][7], int rowNumber, int columnChoice) {
  int count = 0;
  for (int adjacent = 1; adjacent < 4; adjacent++) {
    if (arrayOfRows[rowNumber][columnChoice] == arrayOfRows[rowNumber][columnChoice - adjacent]) {
      count++;
    }
  }
  return (count == 3);
}

bool check_E_Right(char arrayOfRows[6][7], int rowNumber, int columnChoice) {
  int count = 0;
  for (int adjacent = 1; adjacent < 4; adjacent++) {
    if (arrayOfRows[rowNumber][columnChoice] == arrayOfRows[rowNumber][columnChoice + adjacent]) {
      count++;
    }
  }
  return (count == 3);
}

bool check_N_Up(char arrayOfRows[6][7], int rowNumber, int columnChoice) {
  int count = 0;
  for (int adjacent = 1; adjacent < 4; adjacent++) {
    if (arrayOfRows[rowNumber][columnChoice] == arrayOfRows[rowNumber - adjacent][columnChoice]) {
      count++;
    }
  }
  return (count == 3);
}

bool check_S_Down(char arrayOfRows[6][7], int rowNumber, int columnChoice) {
  int count = 0;
  for (int adjacent = 1; adjacent < 4; adjacent++) {
    if (arrayOfRows[rowNumber][columnChoice] == arrayOfRows[rowNumber + adjacent][columnChoice]) {
      count++;
    }
  }
  return (count == 3);
}

bool check_NW(char arrayOfRows[6][7], int rowNumber, int columnChoice) {
  int count = 0;
  for (int adjacent = 1; adjacent < 4; adjacent++) {
    if (arrayOfRows[rowNumber][columnChoice] == arrayOfRows[rowNumber - adjacent][columnChoice - adjacent]) {
      count++;
    }
  }
  return (count == 3);
}

bool check_NE(char arrayOfRows[6][7], int rowNumber, int columnChoice) {
  int count = 0;
  for (int adjacent = 1; adjacent < 4; adjacent++) {
    if (arrayOfRows[rowNumber][columnChoice] == arrayOfRows[rowNumber - adjacent][columnChoice + adjacent]) {
      count++;
    }
  }
  return (count == 3);
}

bool check_SW(char arrayOfRows[6][7], int rowNumber, int columnChoice) {
  int count = 0;
  for (int adjacent = 1; adjacent < 4; adjacent++) {
    if (arrayOfRows[rowNumber][columnChoice] == arrayOfRows[rowNumber + adjacent][columnChoice - adjacent]) {
      count++;
    }
  }
  return (count == 3);
}

bool check_SE(char arrayOfRows[6][7], int rowNumber, int columnChoice) {
  int count = 0;
  for (int adjacent = 1; adjacent < 4; adjacent++) {
    if (arrayOfRows[rowNumber][columnChoice] == arrayOfRows[rowNumber + adjacent][columnChoice + adjacent]) {
      count++;
    }
  }
  return (count == 3);
}

bool check_l_and_r(char arrayOfRows[6][7], int rowNumber, int columnChoice) {
  return (check_W_Left(arrayOfRows, rowNumber, columnChoice) && check_E_Right(arrayOfRows, rowNumber, columnChoice));
}

bool check_t_and_b(char arrayOfRows[6][7], int rowNumber, int columnChoice) {
  return (check_N_Up(arrayOfRows, rowNumber, columnChoice) && check_S_Down(arrayOfRows, rowNumber, columnChoice));
}

bool check_diagonals(char arrayOfRows[6][7], int rowNumber, int columnChoice) {
  return (check_NW(arrayOfRows, rowNumber, columnChoice) && check_NE(arrayOfRows, rowNumber, columnChoice) && check_SW(arrayOfRows, rowNumber, columnChoice) && check_SE(arrayOfRows, rowNumber, columnChoice));
}

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~

struct arr {
  char array[7];
};

struct arr createHorizontalArray(char arrayOfRows[6][7], int rowNumber) {
  int HIndex;
  int columnNum;
  char hArr[7];

  for (HIndex = 0, columnNum = 0; columnNum <= 7; HIndex++, columnNum++) {
    hArr[HIndex] = arrayOfRows[rowNumber][columnNum];
  }

  struct arr arrOfHorizontalValues[1] = {hArr[7]};
  return arrOfHorizontalValues[0];
}

struct arr createVerticalArray(char arrayOfRows[6][7], int columnChoice) {
  int VIndex;
  int rowNum;
  char vArr[6];

  for (VIndex = 0, rowNum = 0; rowNum <= 6; VIndex++, rowNum++) {
    vArr[VIndex] = arrayOfRows[rowNum][columnChoice];
  }
  struct arr arrOfVerticalValues[1] = {vArr[6]};
  return arrOfVerticalValues[0];
}

struct arr createDiagonalArray(char arrayOfRows[6][7], int rowNumber, int columnChoice) {
  int HVIndex;
  char dArr[6];

  while ((rowNumber >= 0) && (columnChoice >= 0)) {
    rowNumber--;
    columnChoice--;
  }

  while ((rowNumber <= 6) && (columnChoice <= 7)) {
    for (HVIndex = 0;; rowNumber++, columnChoice++) {
      dArr[HVIndex] = arrayOfRows[rowNumber][columnChoice];
    }
  }
  struct arr arrOfDiagonalValues[1] = {dArr[6]};
  return arrOfDiagonalValues[0];
}

char checkIfPlayerHasWonHorizontally(struct arr arrayOfHorizontalValues) {
  for (int count = 0; count < 4; count++) {
    if ((arrayOfHorizontalValues.array[count] == arrayOfHorizontalValues.array[count + 1]) && (arrayOfHorizontalValues.array[count] == arrayOfHorizontalValues.array[count + 2]) && (arrayOfHorizontalValues.array[count] == arrayOfHorizontalValues.array[count + 3])) {
      return 'w';
    } else {
      return 'l';
    }
  }
}

char checkIfPlayerHasWonVertically(struct arr arrayOfVerticalValues) {
  for (int count = 0; count < 3; count++) {
    if ((arrayOfVerticalValues.array[count] == arrayOfVerticalValues.array[count + 1]) && (arrayOfVerticalValues.array[count] == arrayOfVerticalValues.array[count + 2]) && (arrayOfVerticalValues.array[count] == arrayOfVerticalValues.array[count + 3])) {
      return 'w';
    } else {
      return 'l';
    }
  }
}

char checkIfPlayerHasWonDiagonally(struct arr arrayOfDiagonalValues) {
  for (int count = 0; count < 3; count++) {
    if ((arrayOfDiagonalValues.array[count] == arrayOfDiagonalValues.array[count + 1]) && (arrayOfDiagonalValues.array[count] == arrayOfDiagonalValues.array[count + 2]) && (arrayOfDiagonalValues.array[count] == arrayOfDiagonalValues.array[count + 3])) {
      return 'w';
    } else {
      return 'l';
    }
  }
}

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~

char checkIfPlayerHasWon(char arrayOfRows[6][7], int rowNumber, int columnChoice) {
  /*if (check_W_Left(arrayOfRows, rowNumber, columnChoice) || check_E_Right(arrayOfRows, rowNumber, columnChoice) || check_N_Up(arrayOfRows, rowNumber, columnChoice) || check_S_Down(arrayOfRows, rowNumber, columnChoice) || check_NW(arrayOfRows, rowNumber, columnChoice) || check_NE(arrayOfRows, rowNumber, columnChoice) || check_SW(arrayOfRows, rowNumber, columnChoice) || check_SE(arrayOfRows, rowNumber, columnChoice) || check_l_and_r(arrayOfRows, rowNumber, columnChoice) || check_t_and_b(arrayOfRows, rowNumber, columnChoice) || check_diagonals(arrayOfRows, rowNumber, columnChoice)) {
    return 'w';
  }

  else {
    return 'l';
  }
  */

  struct arr arrayOfHorizontalValues = createHorizontalArray(arrayOfRows, rowNumber);
  struct arr arrayOfVerticalValues = createVerticalArray(arrayOfRows, columnChoice);
  struct arr arrayOfDiagonalValues = createDiagonalArray(arrayOfRows, rowNumber, columnChoice);

  char hRes = checkIfPlayerHasWonHorizontally(arrayOfHorizontalValues);
  char vRes = checkIfPlayerHasWonVertically(arrayOfVerticalValues);
  char dRes = checkIfPlayerHasWonDiagonally(arrayOfDiagonalValues);

  if ((hRes == 'w') || (vRes == 'w') || (dRes == 'w')) {
    return 'w';
  } else {
    return 'l';
  }
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

char markChoiceOnGrid(char rows[], char columns[], char arrayOfRows[6][7], int columnChoice, char playerNumber) {
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

  char result = checkIfPlayerHasWon(arrayOfRows, rowNumber, (columnChoice - 1));

  if (result == 'w') {
    printf("Congrats, Player %c! You have won! ", playerNumber);
    return 'w';
  } else {
    return 'l';
  }
  // ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~
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
      printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");
      printf("Player 1 (x): Enter your choice of column number: ");
      scanf("%i", &columnChoice);
      printf("\n");

      while ((columnChoice < 1) || (7 < columnChoice)) {
        printf("Invalid choice. Select another, Player 1.");
        scanf("%d", &columnChoice);
      }

      resultOfCheckIfColumnIsFilled = checkIfColumnIsFilled(arrayOfRows, columnChoice);

      while (resultOfCheckIfColumnIsFilled == 'y') {
        printf("Invalid choice. Select another, Player 1.");
        scanf("%d", &columnChoice);
        resultOfCheckIfColumnIsFilled = checkIfColumnIsFilled(arrayOfRows, columnChoice);
      }

      char res = markChoiceOnGrid(rows, columns, arrayOfRows, columnChoice, '1');
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

      resultOfCheckIfColumnIsFilled = checkIfColumnIsFilled(arrayOfRows, columnChoice);

      while (resultOfCheckIfColumnIsFilled == 'y') {
        printf("Invalid choice. Select another, Player 2.");
        scanf("%d", &columnChoice);
        resultOfCheckIfColumnIsFilled = checkIfColumnIsFilled(arrayOfRows, columnChoice);
      }

      char res = markChoiceOnGrid(rows, columns, arrayOfRows, columnChoice, '2');
      if (res == 'w') {
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
