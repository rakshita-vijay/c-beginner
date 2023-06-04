#include <math.h>
#include <stdio.h>

// char arr[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

// TO CORRECT:
// Out of bounds error - 0>x or x>9 - CORRECTED
// Congrats for which player?  - CORRECTED
// End after winning  - CORRECTED
// Reprogram checkIfPlayerHasWon with series/sequence *****************************************

char checkIfPlayerHasWon(char arr[9]);
char markChoiceOnGrid(char arr[9], int gridChoice, char playerNumber);
char drawGrid(char arr[9], char playerNumber);

char checkIfPlayerHasWon(char arr[9]) {
  // 8 combos

  // 1 2 4 5 = 1+2+1 // 1 2 5 6 = 1+3+1

  /*
  int varInt;

  char indices[varInt];

  for(varInt = 1; varInt <= 3; varInt++)
  {

  }
  */
  if ((arr[0] == arr[1] && arr[1] == arr[2]) || (arr[3] == arr[4] && arr[4] == arr[5]) ||
      (arr[6] == arr[7] && arr[7] == arr[8]) || (arr[0] == arr[3] && arr[3] == arr[6]) ||
      (arr[1] == arr[4] && arr[4] == arr[7]) || (arr[2] == arr[5] && arr[5] == arr[8]) ||
      (arr[0] == arr[4] && arr[4] == arr[8]) || (arr[2] == arr[4] && arr[4] == arr[6])) {
    return 'w';
  } else {
    return 'l';
  }
}

char markChoiceOnGrid(char arr[9], int gridChoice, char playerNumber) {
  char ending = 'd';

  if (playerNumber == '1') {
    arr[(gridChoice - 1)] = 'x';
    ending = drawGrid(arr, '1');
    if (ending == 'b') {
      return ending;
    }
  } else {
    arr[gridChoice - 1] = 'o';
    ending = drawGrid(arr, '2');
    if (ending == 'b') {
      return ending;
    }
  }
}

char drawGrid(char arr[9], char playerNumber) {
  char res = 'l';

  printf("Tic Tac Toe: A Game");
  printf("\n    Player 1: x");
  printf("\n    Player 2: o \n");
  printf("\n   %c   |   %c   |   %c ", arr[0], arr[1], arr[2]);
  printf("\n-------|-------|-------");
  printf("\n   %c   |   %c   |   %c ", arr[3], arr[4], arr[5]);
  printf("\n-------|-------|-------");
  printf("\n   %c   |   %c   |   %c \n\n", arr[6], arr[7], arr[8]);

  // printf("\n   %i   |   %i   |   %i \n-------|-------|-------\n   %i   |   %i   |   %i \n-------|-------|-------\n %i
  // |   %i   |   %i \n\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8]);
  res = checkIfPlayerHasWon(arr);
  if (res == 'w') {
    printf("Congrats! You have won, Player %c!", playerNumber);
    return 'b';
  }
}

int main() {
  int gridChoice;
  char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  drawGrid(arr, '1');

  int count;
  char endRes = 'd';

  for (count = 1; count <= 9; count++) {
    if (count % 2 != 0) {
      printf("Player 1 (x): Enter your choice of grid number: ");
      scanf("%d", &gridChoice);
      printf("\n");
      while (arr[gridChoice - 1] == 'x' || arr[gridChoice - 1] == 'o' || gridChoice < 1 || gridChoice > 9) {
        printf("Invalid choice. Select another, Player 1.");
        scanf("%d", &gridChoice);
      }
      endRes = markChoiceOnGrid(arr, gridChoice, '1');
      if (endRes == 'b') {
        break;
      }
    } else {
      printf("Player 2 (o): Enter your choice of grid number: ");
      scanf("%d", &gridChoice);
      printf("\n");
      while (arr[gridChoice - 1] == 'x' || arr[gridChoice - 1] == 'o' || gridChoice < 1 || gridChoice > 9) {
        printf("Invalid choice. Select another, Player 2.");
        scanf("%d", &gridChoice);
      }
      endRes = markChoiceOnGrid(arr, gridChoice, '2');
      if (endRes == 'b') {
        break;
      }
    }
  }
}
