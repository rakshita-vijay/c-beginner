#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numberOfCells;
int numberOfPlayers;
char playerTokens[] = {'*', 'o', '$', '#', '=', '%', 'v', '\0'};
int numberOfCells;
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

  while ((numberOfPlayers > numberOfTokens) || (numberOfPlayers <= 0)) {
    printf("Too ");
    (numberOfPlayers > numberOfTokens) ? printf("many") : printf("less");
    printf(" players. Maximum is %i. Re-enter the number of players: ", numberOfTokens);
    scanf("%i", &numberOfPlayers);
  }

  return numberOfPlayers;
}

void assignValuesToArrayOfCellValues(char arrayOfCellValues[numberOfCells][numberOfPlayers]) {
  for (int outerCount = 0; outerCount < numberOfCells; outerCount++) {
    for (int innerCount = 0; innerCount < numberOfPlayers; innerCount++) {
      // printf("(%i, %i) -%c/ \n", outerCount, innerCount, arrayOfCellValues[outerCount][innerCount]);
      arrayOfCellValues[outerCount][innerCount] = ' ';
      // printf("(%i, %i) (%c) \n", outerCount, innerCount, arrayOfCellValues[outerCount][innerCount]);
    }
  }

  // for (int innerCount = 0; innerCount < numberOfPlayers; innerCount++) {
  //   arrayOfCellValues[numberOfCells][innerCount] = '\0';
  // }
}

void assignIndexToPlayers(int initialPlace[numberOfPlayers], int numberOnDice, char where, int playerNumber) {
  if (where == 'a'){
    for (int playerCount = 0; playerCount < numberOfPlayers; playerCount++) {
      initialPlace[playerCount] = 1;
      }
    }
  else{
      initialPlace[playerNumber] += numberOnDice;
  }
}

int promptForNumberOfCells(){
  printf("\n");
  int num;
  printf("Enter the number of cells you want in the game: ");
  scanf("%i", &num);
  numberOfCells = (int) (floor(num));

  while ((numberOfCells > 154) || (numberOfCells < 20)) {
    int choice;

    printf("Too ");
    (numberOfCells > 154) ? printf("many") : printf("less");
    printf(" cells. Maximum is 154. Minimum is 20. Default is 100. \nDo you want to: \n1) Re-enter the number of cells? \n2) Let it remain 100? \nEnter your choice: ");
    scanf("%i", &choice);
    printf("\n");

    if (choice==1){
      printf("Re-enter the number of cells: ");
      scanf("%i", &num);
      numberOfCells = (int) (floor(num));
      // printf("\n");
    }
    else{
      printf("The number of cells in the game is 100 \n");
      numberOfCells=100;
    }
  }

  return numberOfCells;
}

void splitNumberOfCells(int numberOfCells){
  numberOfCellsInARow = (int) (floor((numberOfCells - (numberOfBridges * numberOfCellsInABridge)) / numberOfRows));
  numberOfCellsRemaining = numberOfCells - ((numberOfCellsInARow * numberOfRows) + (numberOfBridges * numberOfCellsInABridge));
}

void drawRow(int startIndex, char startSide) {
  printf("\n");
  printf("    ");
  for (int count = 0; count < (numberOfCellsInARow * 3); count++) {
    printf("_ ");
  }
  printf("\n");

  printf("   ");
  int index;
  if (startSide=='L') {
    index = startIndex + numberOfCellsInARow;
    for (int innerCount = 0; innerCount < numberOfCellsInARow; innerCount++, index--) {
      if (index > 99){
        printf("|%i  ", index);
        } else{
        (index > 9) ? printf("|%i   ", index) : printf("|0%i   ", index);
        }
      }
  } else { // if (startSide=='R')
      index = startIndex+1;
      for (int innerCount = 0; innerCount < numberOfCellsInARow; innerCount++, index++) {
        if (index > 99) {
        printf("|%i  ", index);
        } else {
        (index > 9) ? printf("|%i   ", index) : printf("|0%i   ", index);
        }
    }
  }
  printf("| \n");

  printf("   ");
  for (int innerCount = 0; innerCount < numberOfCellsInARow; innerCount++) {
    printf("|     ");
  }
  printf("| \n");

  printf("   ");
  for (int count = 0; count < numberOfCellsInARow; count++) {
    printf("|_ _ _");
  }
  printf("| \n");
}

void drawRightBridge(int startIndex) {
  int index = (startIndex + numberOfCellsInABridge);
  for (int outerCount = 0; ((outerCount < numberOfCellsInABridge) && ((index - outerCount) >= 1)); outerCount++) {
    for (int lineCount = 0; lineCount < 2; lineCount++) {
        printf("   ");
        for (int spaceCount1 = 0; spaceCount1 < ((numberOfCellsInARow - 1) * 6); spaceCount1++) {
        printf(" ");
        }
        if ((index - outerCount) > 99) {
        (lineCount == 0) ? printf("|%i  | \n", (index - outerCount)) : printf("|     | \n");
        } else {
        (lineCount == 0) ? (((index - outerCount) > 9) ? printf("|%i   | \n", (index - outerCount)) : printf("|0%i   | \n", (index - outerCount))) : (((index - outerCount) > 9) ? printf("|     | \n") : printf("|     | \n"));
        }
    }

    printf("   ");
    for (int spaceCount2 = 0; spaceCount2 < ((numberOfCellsInARow - 1) * 6); spaceCount2++) {
        printf(" ");
    }
    printf("|_ _ _| \n");
  }
}

void drawLeftBridge(int startIndex) {
  int index = (startIndex + numberOfCellsInABridge);
  for (int outerCount = 0; outerCount < numberOfCellsInABridge; outerCount++) {
    if ((index - outerCount) != 0) {
      for (int lineCount = 0; lineCount < 2; lineCount++) {
        printf("   ");
        if ((index - outerCount) > 99) {
          (lineCount == 0) ? printf("|%i  | \n", (index - outerCount)) : printf("|    | \n");
        } else {
          (lineCount == 0) ? (((index - outerCount) > 9) ? printf("|%i   | \n", (index - outerCount)) : printf("|0%i   | \n", (index - outerCount))) : (((index - outerCount) > 9) ? printf("|     | \n") : printf("|     | \n"));
        }
        }
      }

    printf("   ");
    printf("|_ _ _| \n");
  }
}

void drawRemainingCellsOnRightAsColumn(int numberOfCellsRemaining) {
  for (; numberOfCellsRemaining > 0; numberOfCellsRemaining--) {
    for (int lineCount = 0; lineCount < 2; lineCount++) {
      printf("   ");
      for (int spaceCount = 0; spaceCount < ((numberOfCellsInARow - 1) * 6); spaceCount++) {
        printf(" ");
      }
      (lineCount == 0) ? (printf("|0%i   | \n", numberOfCellsRemaining)) : (printf("|     | \n"));
    }

    printf("   ");
    for (int spaceCount2 = 0; spaceCount2 < ((numberOfCellsInARow - 1) * 6); spaceCount2++) {
      printf(" ");
    }
    printf("|_ _ _| \n");
  }
}

void drawRemainingCellsOnRightAsRow(int numberOfCellsRemaining) {
  printf("    ");
  for (int spaceCount = 0; spaceCount < ((numberOfCellsInARow - numberOfCellsRemaining) * 6); spaceCount++) {
    printf(" ");
  }
  for (int count = 0; count < (numberOfCellsRemaining * 3); count++) {
    printf("_ ");
  }
  printf("\n");

  printf("   ");
  for (int spaceCount = 0; spaceCount < ((numberOfCellsInARow - numberOfCellsRemaining) * 6); spaceCount++) {
    printf(" ");
  }
  for (int count = 1; count <= numberOfCellsRemaining; count++) {
    (count > 9) ? printf("|%i   ", count) : printf("|0%i   ", count);
  }
  printf("| \n");

  printf("   ");
  for (int spaceCount = 0; spaceCount < ((numberOfCellsInARow - numberOfCellsRemaining) * 6); spaceCount++) {
    printf(" ");
  }
  for (int count = 0; count < numberOfCellsRemaining; count++) {
    printf("|     ");
  }
  printf("| \n");

  printf("   ");
  for (int spaceCount = 0; spaceCount < ((numberOfCellsInARow - numberOfCellsRemaining) * 6); spaceCount++) {
    printf(" ");
  }
  for (int count = 0; count < numberOfCellsRemaining; count++) {
    printf("|_ _ _");
  }
  printf("| \n");
}

void drawBoard(char arrayOfCellValues[numberOfCells][numberOfPlayers], char playerTokens[]) {

  printf("                                    Chutes and Ladders: A Game \n");

  int countNumberOfPlayers = 0;
  for (; countNumberOfPlayers < numberOfPlayers; countNumberOfPlayers++) {
    printf("                                           Player %i: %c \n", (countNumberOfPlayers + 1), playerTokens[countNumberOfPlayers]);
  }

  int startIndex = numberOfCells - numberOfCellsInARow;
  drawRow(startIndex, 'L');

  startIndex -= numberOfCellsInABridge;
  drawRightBridge(startIndex);

  startIndex -= numberOfCellsInARow;
  drawRow(startIndex, 'R');

  startIndex -= numberOfCellsInABridge;
  drawLeftBridge(startIndex);

  startIndex -= numberOfCellsInARow;
  drawRow(startIndex, 'L');

  startIndex -= numberOfCellsInABridge;
  drawRightBridge(startIndex);

  startIndex -= numberOfCellsInARow;
  drawRow(startIndex, 'R');

  startIndex -= numberOfCellsInABridge;
  drawLeftBridge(startIndex);

  startIndex -= numberOfCellsInARow;
  drawRow(startIndex, 'L');

  startIndex -= numberOfCellsInABridge;
  drawRightBridge(startIndex);

  (numberOfCellsRemaining<2) ? drawRemainingCellsOnRightAsColumn(numberOfCellsRemaining) : drawRemainingCellsOnRightAsRow(numberOfCellsRemaining);
}

bool askIfPlayerWantsToPlay(int playerNumber) {
  char playerChoice;
  printf("Player %i, do you want to roll the dice - y/n? ", playerNumber);
  scanf("%c", &playerChoice);

  return (((playerChoice == 'Y') || (playerChoice == 'y')) ? true : false);
}

int obtainRandomNumberOnDice(int playerNumber) {
  int numberOnDice = ((rand() % 6) + 1);
  printf("Player %i, move forward %i spaces \n", playerNumber+1, numberOnDice);
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
    arrayOfCellValues[(initialPlace[playerNumber])-1][playerNumber] = playerTokens[playerNumber];
  }
}

int playUntilOnePlayerWins(char arrayOfCellValues[numberOfCells][numberOfPlayers], int initialPlace[numberOfPlayers]) {
  for (;;) {
    int playerNumber = 0;
    for (; arrayOfCellValues[numberOfCells-1][playerNumber] != ' '; playerNumber++) {
      bool playerChoice = askIfPlayerWantsToPlay(playerNumber+1);
      if (playerChoice) {
        int numberOnDice = obtainRandomNumberOnDice(playerNumber);
        calculateFinalTile(numberOnDice, initialPlace, playerNumber);
        printf("~~~");
        markChoiceOnGrid(arrayOfCellValues, initialPlace);
      }
      if (playerNumber == (numberOfPlayers-1)) {
        playerNumber = 0;
      }
    }
    if (arrayOfCellValues[numberOfCells-1][playerNumber] != ' ') {
      return playerNumber;
    }
  }
}

void displayCongratulatoryMessage(int playerNumber) {
  printf("Congrats, Player %i! You have won! \n", playerNumber);
}

int main() {
  char arrayOfCellValues[numberOfCells][numberOfPlayers];
  int initialPlace[numberOfPlayers];

  int numberOfTokens = calculateNumberOfTokens(playerTokens);
  numberOfPlayers = promptForNumberOfPlayers(numberOfTokens);
  assignValuesToArrayOfCellValues(arrayOfCellValues);
  assignIndexToPlayers(initialPlace, 1, 'a', 0);
  int numberOfCells = promptForNumberOfCells();
  splitNumberOfCells(numberOfCells);

  drawBoard(arrayOfCellValues, playerTokens);

  int playerNumber = playUntilOnePlayerWins(arrayOfCellValues, initialPlace);

  displayCongratulatoryMessage(playerNumber);

}
