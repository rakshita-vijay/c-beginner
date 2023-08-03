#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int numberOfCells;
int numberOfPlayers;
// char playerTokens[] = {'*', 'o', '$', '#', '=', '%', 'v', '\0'};
char playerTokens[] = {'1', '2', '3', '4', '5', '6', '7', '\0'};
int numberOfRows = 5;
int numberOfCellsInARow;
int numberOfBridges = 5;
int numberOfCellsInABridge = 2;
int numberOfCellsRemaining;

int calculateNumberOfTokens(char playerTokens[]) {
  int numberOfTokens = 0;
  while (playerTokens[numberOfTokens] != '\0') {
    numberOfTokens++;
  }

  return numberOfTokens;
}

int promptForNumberOfPlayers(int numberOfTokens) {
  printf("\nEnter the number of players: ");
  scanf("%i", &numberOfPlayers);

  while ((numberOfPlayers > numberOfTokens) || (numberOfPlayers <= 1)) {
    printf("Too ");
    // (numberOfPlayers > numberOfTokens) ? printf("many") : printf("less");
    printf((numberOfPlayers > numberOfTokens) ? "many" : "less");
    printf(" players. Maximum is %i. Minimum is 2. Re-enter the number of players: ", numberOfTokens);
    scanf("%i", &numberOfPlayers);
  }

  return numberOfPlayers;
}

void assignValuesToArrayOfCellValues(char arrayOfCellValues[numberOfCells][numberOfPlayers]) {
  for (int outerCount = 0; outerCount < numberOfCells; outerCount++) {
    for (int innerCount = 0; innerCount < numberOfPlayers; innerCount++) {
      // printf("(%i, %i) -(%c)- \n", outerCount, innerCount, arrayOfCellValues[outerCount-1][innerCount-1]);
      arrayOfCellValues[outerCount][innerCount] = ' ';
      // printf("(%i, %i) -(%c)- \n", outerCount, innerCount, arrayOfCellValues[outerCount][innerCount]);
    }
  }

  // for (int innerCount = 0; innerCount < numberOfPlayers; innerCount++) {
  //   arrayOfCellValues[numberOfCells][innerCount] = '\0';
  // }
}

void assignIndexToPlayers(int initialPlace[numberOfPlayers], int numberOnDice, char where, int playerNumber) {
  if (where == 'a') {
    for (int playerCount = 0; playerCount < numberOfPlayers; playerCount++) {
      initialPlace[playerCount] = 1;
    }
  } else {
    initialPlace[playerNumber] += numberOnDice;
  }
}

int promptForNumberOfCells() {
  printf("\n");
  int num;
  printf("Enter the number of cells you want in the game: ");
  scanf("%i", &num);
  numberOfCells = (int)(floor(num));

  while ((numberOfCells > 154) || (numberOfCells < 20)) {
    int choice;

    printf("Too ");
    (numberOfCells > 154) ? printf("many") : printf("less");
    printf(" cells. Maximum is 154. Minimum is 20. Default is 100. \nDo you want to: \n1) Re-enter the number of cells? \n2) Let it remain 100? \nEnter your choice: ");
    scanf("%i", &choice);
    printf("\n");

    if (choice == 1) {
      printf("Re-enter the number of cells: ");
      scanf("%i", &num);
      numberOfCells = (int)(floor(num));
      // printf("\n");
    } else {
      printf("The number of cells in the game is 100 \n");
      numberOfCells = 100;
    }
  }

  return numberOfCells;
}

void splitNumberOfCells(int numberOfCells) {
  numberOfCellsInARow = (int)(floor((numberOfCells - (numberOfBridges * numberOfCellsInABridge)) / numberOfRows));
  numberOfCellsRemaining = numberOfCells - ((numberOfCellsInARow * numberOfRows) + (numberOfBridges * numberOfCellsInABridge));
}

void drawRow(int startIndex, char startSide, char arrayOfCellValues[numberOfCells][numberOfPlayers]) {
  printf("\n");
  printf("    ");
  for (int count = 0; count < (numberOfCellsInARow * 3); count++) {
    printf("_ ");
  }
  printf("\n");

  printf("   ");
  int index;
  if (startSide == 'L') {
    index = startIndex + numberOfCellsInARow;
    /* FIRST LINE */
    for (int innerCount = 0; innerCount < numberOfCellsInARow; innerCount++, index--) {
      if (index > 99) {
        printf("|%i %c", index, arrayOfCellValues[index - 1][0]);
      } else {
        printf(((index > 9) ? "|%i  %c" : "|0%i  %c"), index, arrayOfCellValues[index - 1][0]);
      }
    }
    printf("| \n");
    /* SECOND LINE */
    printf("   ");
    index = startIndex + numberOfCellsInARow;
    // printf("~~ %i ~~", index);
    for (int innerCount = 0; innerCount < numberOfCellsInARow; innerCount++, index--) {
      if (numberOfPlayers == 2) {
        printf("|    %c", arrayOfCellValues[index - 1][1]);
      } else if (numberOfPlayers == 3) {
        printf("|   %c%c", arrayOfCellValues[index - 1][1], arrayOfCellValues[index - 1][2]);
      } else if (numberOfPlayers == 4) {
        printf("|  %c%c%c", arrayOfCellValues[index - 1][1], arrayOfCellValues[index - 1][2], arrayOfCellValues[index - 1][3]);
      } else if (numberOfPlayers >= 5) {
        printf("| %c%c%c%c", arrayOfCellValues[index - 1][1], arrayOfCellValues[index - 1][2], arrayOfCellValues[index - 1][3], arrayOfCellValues[index - 1][4]);
      }
    }
    printf("| \n");
    /* THIRD LINE */
    printf("   ");
    index = startIndex + numberOfCellsInARow;
    for (int innerCount = 0; innerCount < numberOfCellsInARow; innerCount++, index--) {
      if (numberOfPlayers == 6) {
        printf("|_ _%c_", arrayOfCellValues[index - 1][5]);
      } else if (numberOfPlayers == 7) {
        printf("|_%c_%c_", arrayOfCellValues[index - 1][5], arrayOfCellValues[index - 1][6]);
      } else {
        printf("|_ _ _");
      }
    }
    printf("| \n");
  }

  else /* if (startSide == 'R') */ {
    index = startIndex + 1;
    /* FIRST LINE */
    for (int innerCount = 0; innerCount < numberOfCellsInARow; innerCount++, index++) {
      if (index > 99) {
        printf("|%i %c", index, arrayOfCellValues[index - 1][0]);
      } else {
        printf(((index > 9) ? "|%i  %c" : "|0%i  %c"), index, arrayOfCellValues[index - 1][0]);
      }
    }
    printf("| \n");
    /* SECOND LINE */
    printf("   ");
    index = startIndex + 1;
    for (int innerCount = 0; innerCount < numberOfCellsInARow; innerCount++, index++) {
      if (numberOfPlayers == 2) {
        printf("|    %c", arrayOfCellValues[index - 1][1]);
      } else if (numberOfPlayers == 3) {
        printf("|   %c%c", arrayOfCellValues[index - 1][1], arrayOfCellValues[index - 1][2]);
      } else if (numberOfPlayers == 4) {
        printf("|  %c%c%c", arrayOfCellValues[index - 1][1], arrayOfCellValues[index - 1][2], arrayOfCellValues[index - 1][3]);
      } else if (numberOfPlayers >= 5) {
        printf("| %c%c%c%c", arrayOfCellValues[index - 1][1], arrayOfCellValues[index - 1][2], arrayOfCellValues[index - 1][3], arrayOfCellValues[index - 1][4]);
      }
    }
    printf("| \n");
    /* THIRD LINE */
    printf("   ");
    index = startIndex + 1;
    for (int innerCount = 0; innerCount < numberOfCellsInARow; innerCount++, index++) {
      if (numberOfPlayers == 6) {
        printf("|_ _%c_", arrayOfCellValues[index - 1][5]);
      } else if (numberOfPlayers == 7) {
        printf("|_%c_%c_", arrayOfCellValues[index - 1][5], arrayOfCellValues[index - 1][6]);
      } else {
        printf("|_ _ _");
      }
    }
    printf("| \n");
  }
}

void drawRightBridge(int startIndex, char arrayOfCellValues[numberOfCells][numberOfPlayers]) {
  int index = startIndex + numberOfCellsInABridge;
  for (int outerCount = 0; ((outerCount < numberOfCellsInABridge) && ((index - outerCount) >= 1)); outerCount++) {
    /* FIRST LINE */
    printf("   ");
    for (int spaceCount1 = 0; spaceCount1 < ((numberOfCellsInARow - 1) * 6); spaceCount1++) {
      printf(" ");
    }
    if ((index - outerCount) > 99) {
      printf("|%i %c| \n", (index - outerCount), arrayOfCellValues[index - outerCount - 1][0]);
    } else if ((index - outerCount) > 9) {
      printf("|%i  %c| \n", (index - outerCount), arrayOfCellValues[index - outerCount - 1][0]);
    } else {
      printf("|0%i  %c| \n", (index - outerCount), arrayOfCellValues[index - outerCount - 1][0]);
    }
    /* SECOND LINE */
    printf("   ");
    for (int spaceCount1 = 0; spaceCount1 < ((numberOfCellsInARow - 1) * 6); spaceCount1++) {
      printf(" ");
    }
    if (numberOfPlayers == 2) {
      printf("|    %c| \n", arrayOfCellValues[index - 1][1]);
    } else if (numberOfPlayers == 3) {
      printf("|   %c%c| \n", arrayOfCellValues[index - 1][1], arrayOfCellValues[index - 1][2]);
    } else if (numberOfPlayers == 4) {
      printf("|  %c%c%c| \n", arrayOfCellValues[index - 1][1], arrayOfCellValues[index - 1][2], arrayOfCellValues[index - 1][3]);
    } else if (numberOfPlayers >= 5) {
      printf("| %c%c%c%c| \n", arrayOfCellValues[index - 1][1], arrayOfCellValues[index - 1][2], arrayOfCellValues[index - 1][3], arrayOfCellValues[index - 1][4]);
    }
    /* THIRD LINE */
    printf("   ");
    for (int spaceCount1 = 0; spaceCount1 < ((numberOfCellsInARow - 1) * 6); spaceCount1++) {
      printf(" ");
    }
    if (numberOfPlayers == 6) {
      printf("|_ _%c_| \n", arrayOfCellValues[index - 1][5]);
    } else if (numberOfPlayers == 7) {
      printf("|_%c_%c_| \n", arrayOfCellValues[index - 1][5], arrayOfCellValues[index - 1][6]);
    } else {
      printf("|_ _ _| \n");
    }
  }
}

void drawLeftBridge(int startIndex, char arrayOfCellValues[numberOfCells][numberOfPlayers]) {
  int index = startIndex + numberOfCellsInABridge;
  for (int outerCount = 0; ((outerCount < numberOfCellsInABridge) && ((index - outerCount) >= 1)); outerCount++) {
    /* FIRST LINE */
    printf("   ");
    if ((index - outerCount) > 99) {
      printf("|%i %c| \n", (index - outerCount), arrayOfCellValues[index - outerCount - 1][0]);
    } else if ((index - outerCount) > 9) {
      printf("|%i  %c| \n", (index - outerCount), arrayOfCellValues[index - outerCount - 1][0]);
    } else {
      printf("|0%i  %c| \n", (index - outerCount), arrayOfCellValues[index - outerCount - 1][0]);
    }
    /* SECOND LINE */
    printf("   ");
    if (numberOfPlayers == 2) {
      printf("|    %c| \n", arrayOfCellValues[index - 1][1]);
    } else if (numberOfPlayers == 3) {
      printf("|   %c%c| \n", arrayOfCellValues[index - 1][1], arrayOfCellValues[index - 1][2]);
    } else if (numberOfPlayers == 4) {
      printf("|  %c%c%c| \n", arrayOfCellValues[index - 1][1], arrayOfCellValues[index - 1][2], arrayOfCellValues[index - 1][3]);
    } else if (numberOfPlayers >= 5) {
      printf("| %c%c%c%c| \n", arrayOfCellValues[index - 1][1], arrayOfCellValues[index - 1][2], arrayOfCellValues[index - 1][3], arrayOfCellValues[index - 1][4]);
    }
    /* THIRD LINE */
    printf("   ");
    if (numberOfPlayers == 6) {
      printf("|_ _%c_| \n", arrayOfCellValues[index - 1][5]);
    } else if (numberOfPlayers == 7) {
      printf("|_%c_%c_| \n", arrayOfCellValues[index - 1][5], arrayOfCellValues[index - 1][6]);
    } else {
      printf("|_ _ _| \n");
    }
  }
}

void drawRemainingCellsOnRightAsColumn(int numberOfCellsRemaining, char arrayOfCellValues[numberOfCells][numberOfPlayers]) {
  for (; numberOfCellsRemaining > 0; numberOfCellsRemaining--) {
    /* FIRST LINE */
    printf("   ");
    for (int spaceCount1 = 0; spaceCount1 < ((numberOfCellsInARow - 1) * 6); spaceCount1++) {
      printf(" ");
    }
    printf("|0%i  %c| \n", numberOfCellsRemaining, arrayOfCellValues[numberOfCellsRemaining - 1][0]);
    /* SECOND LINE */
    printf("   ");
    for (int spaceCount1 = 0; spaceCount1 < ((numberOfCellsInARow - 1) * 6); spaceCount1++) {
      printf(" ");
    }
    if (numberOfPlayers == 2) {
      printf("|    %c| \n", arrayOfCellValues[numberOfCellsRemaining - 1][1]);
    } else if (numberOfPlayers == 3) {
      printf("|   %c%c| \n", arrayOfCellValues[numberOfCellsRemaining - 1][1], arrayOfCellValues[numberOfCellsRemaining - 1][2]);
    } else if (numberOfPlayers == 4) {
      printf("|  %c%c%c| \n", arrayOfCellValues[numberOfCellsRemaining - 1][1], arrayOfCellValues[numberOfCellsRemaining - 1][2], arrayOfCellValues[numberOfCellsRemaining - 1][3]);
    } else if (numberOfPlayers >= 5) {
      printf("| %c%c%c%c| \n", arrayOfCellValues[numberOfCellsRemaining - 1][1], arrayOfCellValues[numberOfCellsRemaining - 1][2], arrayOfCellValues[numberOfCellsRemaining - 1][3], arrayOfCellValues[numberOfCellsRemaining - 1][4]);
    }
    /* THIRD LINE */
    printf("   ");
    for (int spaceCount1 = 0; spaceCount1 < ((numberOfCellsInARow - 1) * 6); spaceCount1++) {
      printf(" ");
    }
    if (numberOfPlayers == 6) {
      printf("|_ _%c_| \n", arrayOfCellValues[numberOfCellsRemaining - 1][5]);
    } else if (numberOfPlayers == 7) {
      printf("|_%c_%c_| \n", arrayOfCellValues[numberOfCellsRemaining - 1][5], arrayOfCellValues[numberOfCellsRemaining - 1][6]);
    } else {
      printf("|_ _ _| \n");
    }
  }
}

void drawRemainingCellsOnRightAsRow(int numberOfCellsRemaining, char arrayOfCellValues[numberOfCells][numberOfPlayers]) {
  printf("    ");
  for (int spaceCount = 0; spaceCount < ((numberOfCellsInARow - numberOfCellsRemaining) * 6); spaceCount++) {
    printf(" ");
  }
  for (int count = 0; count < (numberOfCellsRemaining * 3); count++) {
    printf("_ ");
  }
  printf("\n");

  /* FIRST LINE */
  printf("   ");
  for (int spaceCount1 = 0; spaceCount1 < ((numberOfCellsInARow - numberOfCellsRemaining) * 6); spaceCount1++) {
    printf(" ");
  }
  for (int count = 1; count <= numberOfCellsRemaining; count++) {
    printf(((count > 9) ? "|%i  %c" : "|0%i  %c"), count, arrayOfCellValues[count - 1][0]);
  }
  printf("| \n");
  /* SECOND LINE */
  printf("   ");
  for (int spaceCount1 = 0; spaceCount1 < ((numberOfCellsInARow - numberOfCellsRemaining) * 6); spaceCount1++) {
    printf(" ");
  }
  for (int count = 0; count < numberOfCellsRemaining; count++) {
    if (numberOfPlayers == 2) {
      printf("|    %c", arrayOfCellValues[count][1]);
    } else if (numberOfPlayers == 3) {
      printf("|   %c%c", arrayOfCellValues[count][1], arrayOfCellValues[count][2]);
    } else if (numberOfPlayers == 4) {
      printf("|  %c%c%c", arrayOfCellValues[count][1], arrayOfCellValues[count][2], arrayOfCellValues[count][3]);
    } else if (numberOfPlayers >= 5) {
      printf("| %c%c%c%c", arrayOfCellValues[count][1], arrayOfCellValues[count][2], arrayOfCellValues[count][3], arrayOfCellValues[count][4]);
    }
  }
  printf("| \n");
  /* THIRD LINE */
  printf("   ");
  for (int spaceCount1 = 0; spaceCount1 < ((numberOfCellsInARow - numberOfCellsRemaining) * 6); spaceCount1++) {
    printf(" ");
  }
  for (int count = 0; count < numberOfCellsRemaining; count++) {
    if (numberOfPlayers == 6) {
      printf("|_ _%c_", arrayOfCellValues[count][5]);
    } else if (numberOfPlayers == 7) {
      printf("|_%c_%c_", arrayOfCellValues[count][5], arrayOfCellValues[count][6]);
    } else {
      printf("|_ _ _");
    }
  }
  printf("| \n");
}

void drawBoard(char arrayOfCellValues[numberOfCells][numberOfPlayers], char playerTokens[]) {
  printf("\n                                    Chutes and Ladders: A Game \n");

  int countNumberOfPlayers = 0;
  for (; countNumberOfPlayers < numberOfPlayers; countNumberOfPlayers++) {
    printf("                                           Player %i: %c \n", (countNumberOfPlayers + 1), playerTokens[countNumberOfPlayers]);
  }

  int startIndex = numberOfCells - numberOfCellsInARow;
  drawRow(startIndex, 'L', arrayOfCellValues);

  startIndex -= numberOfCellsInABridge;
  drawRightBridge(startIndex, arrayOfCellValues);

  startIndex -= numberOfCellsInARow;
  drawRow(startIndex, 'R', arrayOfCellValues);

  startIndex -= numberOfCellsInABridge;
  drawLeftBridge(startIndex, arrayOfCellValues);

  startIndex -= numberOfCellsInARow;
  drawRow(startIndex, 'L', arrayOfCellValues);

  startIndex -= numberOfCellsInABridge;
  drawRightBridge(startIndex, arrayOfCellValues);

  startIndex -= numberOfCellsInARow;
  drawRow(startIndex, 'R', arrayOfCellValues);

  startIndex -= numberOfCellsInABridge;
  drawLeftBridge(startIndex, arrayOfCellValues);

  startIndex -= numberOfCellsInARow;
  drawRow(startIndex, 'L', arrayOfCellValues);

  startIndex -= numberOfCellsInABridge;
  drawRightBridge(startIndex, arrayOfCellValues);

  (numberOfCellsRemaining < 2) ? drawRemainingCellsOnRightAsColumn(numberOfCellsRemaining, arrayOfCellValues) : drawRemainingCellsOnRightAsRow(numberOfCellsRemaining, arrayOfCellValues);
}

bool askIfPlayerWantsToPlay(int playerNumber) {
  char playerChoice;
  printf("Player %i (%c), do you want to roll the dice - y/n? ", playerNumber, playerTokens[playerNumber - 1]);
  scanf("%c", &playerChoice);

  return (((playerChoice == 'Y') || (playerChoice == 'y')) ? true : false);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int obtainRandomNumberOnDice(int playerNumber) {
  int numberOfRandNumsToAverage = ((rand() % 6) + 1);
  printf("numberOfRandNumsToAverage = %i \n", numberOfRandNumsToAverage);
  int sum = 0;
  for (int count = 0; count < numberOfRandNumsToAverage; count++) {
    int randNum = ((rand() % 6) + 1);
    printf("randNum = %i \n", randNum);
    sum += randNum;
    printf("sum = %i \n", sum);
  }
  int numberOnDice = sum / numberOfRandNumsToAverage;
  printf("Player %i, move forward %i spaces \n", playerNumber + 1, numberOnDice);
  return numberOnDice;
}

void climbUpIfRequired(int initialPlace[numberOfPlayers]) {
  for (int playerNumber = 0; playerNumber < numberOfPlayers; playerNumber++) {
    if ((initialPlace[playerNumber] == 12) || (initialPlace[playerNumber] == 53) || (initialPlace[playerNumber] == 80)) {
      assignIndexToPlayers(initialPlace, 5, 'b', playerNumber);
    }
    if ((initialPlace[playerNumber] == 15) || (initialPlace[playerNumber] == 24)) {
      assignIndexToPlayers(initialPlace, 6, 'b', playerNumber);
    }
    if (initialPlace[playerNumber] == 42) {
      assignIndexToPlayers(initialPlace, 10, 'b', playerNumber);
    }
    if (initialPlace[playerNumber] == 59) {
      assignIndexToPlayers(initialPlace, 36, 'b', playerNumber);
    }
    printf("Player %i, you are now at %i \n", playerNumber + 1, initialPlace[playerNumber]);
  }
}

void slideDownIfRequired(int initialPlace[numberOfPlayers]) {
  for (int playerNumber = 0; playerNumber < numberOfPlayers; playerNumber++) {
    if (initialPlace[playerNumber] == 32) {
      assignIndexToPlayers(initialPlace, -9, 'b', playerNumber);
    }
    if (initialPlace[playerNumber] == 58) {
      assignIndexToPlayers(initialPlace, -5, 'b', playerNumber);
    }
    if (initialPlace[playerNumber] == 87) {
      assignIndexToPlayers(initialPlace, -43, 'b', playerNumber);
    }
    if (initialPlace[playerNumber] == 99) {
      assignIndexToPlayers(initialPlace, -33, 'b', playerNumber);
    }
    printf("Player %i, you are now at %i \n", playerNumber + 1, initialPlace[playerNumber]);
  }
}

void calculateFinalTile(int numberOnDice, int initialPlace[numberOfPlayers], int playerNumber) {
  assignIndexToPlayers(initialPlace, numberOnDice, 'b', playerNumber);
  climbUpIfRequired(initialPlace);
  slideDownIfRequired(initialPlace);
}

void markChoiceOnGrid(char arrayOfCellValues[numberOfCells][numberOfPlayers], int initialPlace[numberOfPlayers]) {
  for (int playerNumber = 0; playerNumber < numberOfPlayers; playerNumber++) {
    arrayOfCellValues[(initialPlace[playerNumber]) - 1][playerNumber] = playerTokens[playerNumber];
    printf("~~ %c ~~ \n", arrayOfCellValues[(initialPlace[playerNumber]) - 1][playerNumber]);
  }
  drawBoard(arrayOfCellValues, playerTokens);
}

int playUntilOnePlayerWins(char arrayOfCellValues[numberOfCells][numberOfPlayers], int initialPlace[numberOfPlayers]) {
  for (;;) {
    int playerNumber = 0;
    for (; arrayOfCellValues[numberOfCells - 1][playerNumber] == ' '; playerNumber++) {
      bool playerChoice = askIfPlayerWantsToPlay(playerNumber + 1);
      if (playerChoice) {
        //////////////////////////////////////////////////////////////////////////////////
        /**/ arrayOfCellValues[(initialPlace[playerNumber]) - 1][playerNumber] = ' '; /**/
        //////////////////////////////////////////////////////////////////////////////////
        int numberOnDice = obtainRandomNumberOnDice(playerNumber);
        calculateFinalTile(numberOnDice, initialPlace, playerNumber);
        markChoiceOnGrid(arrayOfCellValues, initialPlace);
      }
      if (playerNumber == (numberOfPlayers - 1)) {
        playerNumber = 0;
      }
    }
    if (arrayOfCellValues[numberOfCells - 1][playerNumber] != ' ') {
      return playerNumber;
    }
  }
}

void displayCongratulatoryMessage(int playerNumber) {
  printf("Congrats, Player %i! You have won! \n", playerNumber);
}

int main() {
  int numberOfTokens = calculateNumberOfTokens(playerTokens);
  numberOfPlayers = promptForNumberOfPlayers(numberOfTokens);

  int initialPlace[numberOfPlayers];

  int numberOfCells = promptForNumberOfCells();
  splitNumberOfCells(numberOfCells);

  char arrayOfCellValues[numberOfCells][numberOfPlayers];

  assignValuesToArrayOfCellValues(arrayOfCellValues);

  assignIndexToPlayers(initialPlace, 1, 'a', 0);

  markChoiceOnGrid(arrayOfCellValues, initialPlace);

  /////////////////////////////////////////////////////////////////////////////////////
  /**/ int playerNumber = playUntilOnePlayerWins(arrayOfCellValues, initialPlace); /**/
  /////////////////////////////////////////////////////////////////////////////////////

  displayCongratulatoryMessage(playerNumber);
}
