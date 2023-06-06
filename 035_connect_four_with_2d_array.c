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

bool check_N_Top(char arrayOfRows[6][7], int rowNumber, int columnChoice) {
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

char checkIfPlayerHasWon(char arrayOfRows[6][7], int rowNumber, int columnChoice) {
  if (check_W_Left(arrayOfRows, rowNumber, columnChoice) || check_E_Right(arrayOfRows, rowNumber, columnChoice) || check_N_Top(arrayOfRows, rowNumber, columnChoice) || check_S_Down(arrayOfRows, rowNumber, columnChoice) || check_NW(arrayOfRows, rowNumber, columnChoice) || check_NE(arrayOfRows, rowNumber, columnChoice) || check_SW(arrayOfRows, rowNumber, columnChoice) || check_SE(arrayOfRows, rowNumber, columnChoice)) {
    return 'w';
  }

  else {
    return 'l';
  }
}

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
