#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numberOfCells;
int numberOfPlayers;
char playerTokens[] = {'*', 'o', '$', '#', '=', '%', 'v', '\0'};
int numberOfCells;

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
  printf("\n");

  while ((numberOfPlayers > numberOfTokens) || (numberOfPlayers <= 0)) {
    printf("Too ");
    (numberOfPlayers > numberOfTokens) ? printf("many") : printf("less");
    printf(" players. Maximum is %i. Re-enter the number of players: ", numberOfTokens);
    scanf("%i", &numberOfPlayers);
    printf("\n");
  }

  printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

  return numberOfPlayers;
}

void assignValuesToArrayOfCellValues(char arrayOfCellValues[numberOfCells][numberOfPlayers]) {
  for (int outerCount = 0; outerCount < numberOfCells; outerCount++) {
    for (int innerCount = 0; innerCount < numberOfPlayers; innerCount++) {
      // printf("(%i, %i) -%c/ \n", outerCount, innerCount, arrayOfCellValues[outerCount][innerCount]);
      arrayOfCellValues[outerCount][innerCount] = ' ';
      printf("(%i, %i) (%c) \n", outerCount, innerCount, arrayOfCellValues[outerCount][innerCount]);
    }
  }

  // for (int innerCount = 0; innerCount < numberOfPlayers; innerCount++) {
  //   arrayOfCellValues[numberOfCells][innerCount] = '\0';
  // }
}

/*
void drawBoard(char arrayOfCellValues[numberOfCells][numberOfPlayers], char playerTokens[]) {

  printf("                                    Chutes and Ladders: A Game \n");

  int countNumberOfPlayers = 0;
  for (; countNumberOfPlayers < numberOfPlayers; countNumberOfPlayers++) {
    printf("                                           Player %i: %c \n", (countNumberOfPlayers + 1), playerTokens[countNumberOfPlayers]);
  }

  printf("   _ _ _ _ _ \n");
  printf("  /          \\_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _   \n");
  printf(" |           |99   |98   |97   |96   |95   |94   |93   |92   |91   |90   |89   |88   |87   |86   |85   |84   /\\ \n");
  printf(" |  FINISH!  |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |    /  \\ \n");
  printf(" |           |_   _|_ _ _|_ _ _|_ _ _|_|_ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_   _|_ _ _|_ /_/|_ _/    \\ \n");
  printf("  \\ _ _ _ _ /  ( (                   |_|                                               ) )         /_/     | 83  \\ \n");
  printf("               ) )                   |_|                                              / /         /_/      /\\    / \n");
  printf("              / /                    |_|                                             / /         /_/      /  \\  / \n");
  printf("              ) )                    |_|                                            / /         /_/      /    \\/ \n");
  printf("    _ _ _ _ _/ /_ _ _ _ _ _ _ _ _ _ _|_|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _( (_ _ _ _ _/_/_ _ _ /  82  | \n");
  printf("   |    \\      |     |     |     |   |_|     |     |     |     |     |     |     |  \\ \\|     |/ /  |    \\      / \n");
  printf("   | 65  \\ 66  | 67  | 68  | 69  |70 |_| 71  | 72  | 73  | 74  | 75  | 76  | 77  |78 | | 79  | 80  | 81  \\    / \n");
  printf("    \\_ _ _\\ _ _|_ _ _|_ _ _|_ _ _|_ _|_|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _| |_ _ _|_ _ _|_ _ _|_ _/ \n");
  printf("     \\     \\                         |_|                                            / /    _ _ _ _            \n");
  printf("      \\ 64  \\_ _ _ _ _ _ _ _ _ _ _ _ |_| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\\ \\_ _/ _ _ _ \\_ _ _ _ _ _  \n");
  printf("       \\    /     |     |     |     || |  |     |     |     |     |     |     |     |\\_ _ _/    |\\ \\    |     \\ \n");
  printf("        \\  /  63  | 62  | 61  | 60  | 59  | 58  | 57  | 56  | 55  | 54  | 53  | 52  | 51  | 50  | ) )49 | 48   \\ \n");
  printf("         \\/_ _ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_   _|_ _ _|_ _ _|_ _ _|_ _ _|_   _|_\\_\\_|_ _ _|_ _ _|/ / _ _|_ _ _ _\\ \n");
  printf("                                            \\  \\ _ _/  \\       _ _ _ _ _ /  /    \\_\\            / /      \\       \\ \n");
  printf("                                             \\_ _ _ _/\\ \\_ _ _/ _ _ _ _ _ _/      \\_\\          / /        \\  47   \\ \n");
  printf("                    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\\_ _ _ _/_ _ _ _ _ _ _ _ _ _\\_\\_ _ _ _ _\\ \\_ _ _ _ /_ _ _ _/ \n");
  printf("                   /\\       |     |     |     |     |     |     |     |     |     | \\ \\ |     |     |     |      / \n");
  printf("                  /  \\ 32   | 33  | 34  | 35  | 36  | 37  | 38  | 39  | 40  | 41  | 42  | 43  | 44  | 45  | 46  / \n");
  printf("                 /    \\_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ / \n");
  printf("                / 31  /      _ _ _ _ _ _ _ _ _                _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  \n");
  printf("               /_ _ _/      |     |     |     |              /     /     |     |     |     |     |     |     |     |     | \n");
  printf("              /     /       | 23  | 22  | 21  |             / 15  /  14  | 13  | 12  | 11  | 10  | 09  | 08  | 07  | 06  | \n");
  printf("             / 30  /        |_ _ _|_ _ _|_ _ _|            /_ _ _/_ _ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _|_ _ _| \n");
  printf("            /_ _ _/         |     |     |     |           /     /                                                  |     | \n");
  printf("           /     /          | 24  |     | 20  |          / 16  /                        _ _ _ _ _ _ _ _            | 05  | \n");
  printf("          / 29  /           |_ _ _|     |_ _ _|         /_ _ _/                       /        __   .  \\_ _ _ _ _ _|_ _ _| \n");
  printf("         /_ _ _/_ _ _ _ _ _/      |     |      \\_ _ _ _/     /                       |        /  \\ /|  |     |     |     | \n");
  printf("        /     /     |     |  25   |     |   19  |     |  17  |                       |        |  |  |  | 02  | 03  | 04  | \n");
  printf("       / 28  /  27  | 26  |      /       \\      | 18  |      |                       |        \\__/ _|_ |_ _ _|_ _ _|_ _ _| \n");
  printf("      /_ _ _/_ _ _ _|_ _ _|_ _ _/         \\_ _ _|_ _ _|_ _ _/                         \\ _ _ _ _ _ _ _ _/ \n");
}
*/

int promptForNumberOfCells(){
  // printf("Enter the number of cells you want in the game (Default is 100): ");
  printf("Enter the number of cells you want in the game: ");
  scanf("%i", &numberOfCells);
  printf("\n");

  while ((numberOfCells > 200) || (numberOfCells < 10)) {
    printf("Too ");
    (numberOfCells > 200) ? printf("many") : printf("less");
    printf(" cells. Maximum is 200. Minimum is 10. Re-enter the number of cells: ");
    scanf("%i", &numberOfCells);
    printf("\n");
  }

  return numberOfCells;
}

int numberOfRows = 5;
int numberOfCellsInARow;
int numberOfBridges = 5;
int numberOfCellsInABridge = 2;
int numberOfCellsRemaining;

void splitNumberOfCells(int numberOfCells){
  numberOfCellsInARow = floor((numberOfCells - (numberOfBridges * numberOfCellsInABridge)) / numberOfRows);
  numberOfCellsRemaining = numberOfCells - ((numberOfCellsInARow * numberOfRows) + (numberOfBridges * numberOfCellsInABridge));
}

void drawRow(){
  printf("    ");
  for (int count = 0; count < (numberOfCellsInARow * 3); count++) {
    printf("_ ");
  }
  printf("\n");

  for (int outerCount = 0; outerCount < 2; outerCount++) {
    printf("   ");
    for (int innerCount = 0; innerCount < numberOfCellsInARow; innerCount++) {
      printf("|     ");
    }
    printf("| \n");
  }

  printf("   ");
  for (int count = 0; count < numberOfCellsInARow; count++) {
    printf("|_ _ _");
  }
  printf("| \n");
}

void drawRightBridge() {
  for (int outerCount = 0; outerCount < numberOfCellsInABridge; outerCount++) {
    for (int innerCount = 0; innerCount < 2; innerCount++) {
      printf("   ");
      for (int spaceCount1 = 0; spaceCount1 < ((numberOfCellsInARow-1) * 6); spaceCount1++) {
        printf(" ");
      }
      printf("|     | \n");
    }

    printf("   ");
    for (int spaceCount2 = 0; spaceCount2 < ((numberOfCellsInARow - 1) * 6); spaceCount2++) {
      printf(" ");
    }
    printf("|_ _ _| \n");
  }
}

void drawLeftBridge() {
  for (int outerCount = 0; outerCount < numberOfCellsInABridge; outerCount++) {
    for (int innerCount = 0; innerCount < 2; innerCount++) {
      printf("   ");
      printf("|     | \n");
    }

    printf("   ");
    printf("|_ _ _| \n");
  }
}

void drawBoard(char arrayOfCellValues[numberOfCells][numberOfPlayers], char playerTokens[]) {

  printf("                                    Chutes and Ladders: A Game \n");

  int countNumberOfPlayers = 0;
  for (; countNumberOfPlayers < numberOfPlayers; countNumberOfPlayers++) {
    printf("                                           Player %i: %c \n", (countNumberOfPlayers + 1), playerTokens[countNumberOfPlayers]);
  }

  for(int count =0; count< 2; count++){
    drawRow();
    drawRightBridge();
    drawRow();
    drawLeftBridge();
  }

  drawRow();
  drawRightBridge();
}

bool askIfPlayerWantsToPlay(int playerNumber) {
  char playerChoice;
  printf("Player %i, do you want to roll the dice - y/n? ", playerNumber);
  scanf("%c", &playerChoice);

  return (((playerChoice == 'Y') || (playerChoice == 'y')) ? true : false);
}

// #define RAND_MAX = 6;
int obtainRandomNumberOnDice(int playerNumber) {
  int numberOnDice = ((rand() % 6) + 1);
  printf("Player %i, move forward %i spaces", playerNumber, numberOnDice);
  return numberOnDice;
}

/*
// int climbUpIfRequired() {
// }

// int slideDownIfRequired() {
// }
*/

int calculateFinalTile(int numberOnDice) {
  // normal move
  // climbUpIfRequired();
  // slideDownIfRequired();

  return 0;
}

void markChoiceOnGrid(int finalTile) {
}

int playUntilOnePlayerWins(char arrayOfCellValues[numberOfCells][numberOfPlayers]) {
  for (;;) {
    int playerNumber = 0;
    for (; arrayOfCellValues[99][playerNumber] != ' '; playerNumber++) {
      bool playerChoice = askIfPlayerWantsToPlay(playerNumber);
      if (playerChoice) {
        int numberOnDice = obtainRandomNumberOnDice(playerNumber);
        int finalTile = calculateFinalTile(numberOnDice);
        markChoiceOnGrid(finalTile);
      } else {
        continue;
      }
    }
    if (arrayOfCellValues[99][playerNumber] != ' ') {
      return playerNumber;
    }
  }
}

void displayCongratulatoryMessage(int playerNumber) {
  printf("Congrats, Player %i! You have won! \n", playerNumber);
}

int main() {

  char arrayOfCellValues[numberOfCells][numberOfPlayers];

  // {{'1', '2', '3', '4', '5', '6', '7'}, {'b', ' ', ' ', ' ', ' ', ' ', ' '}, {'c', ' ', ' ', ' ', ' ', ' ', ' '}, {'d', ' ', ' ', ' ', ' ', ' ', ' '}, {'e', ' ', ' ', ' ', ' ', ' ', ' '}, {'f', ' ', ' ', ' ', ' ', ' ', ' '}, {'g', ' ', ' ', ' ', ' ', ' ', ' '}, {'h', ' ', ' ', ' ', ' ', ' ', ' '}, {'i', ' ', ' ', ' ', ' ', ' ', ' '}, {'j', ' ', ' ', ' ', ' ', ' ', ' '}, {'k', ' ', ' ', ' ', ' ', ' ', ' '}, {'l', ' ', ' ', ' ', ' ', ' ', ' '}, {'m', ' ', ' ', ' ', ' ', ' ', ' '}, {'n', ' ', ' ', ' ', ' ', ' ', ' '}, {'o', ' ', ' ', ' ', ' ', ' ', ' '}, {'p', ' ', ' ', ' ', ' ', ' ', ' '}, {'q', ' ', ' ', ' ', ' ', ' ', ' '}, {'r', ' ', ' ', ' ', ' ', ' ', ' '}, {'s', ' ', ' ', ' ', ' ', ' ', ' '}, {'t', ' ', ' ', ' ', ' ', ' ', ' '}, {'u', ' ', ' ', ' ', ' ', ' ', ' '}, {'v', ' ', ' ', ' ', ' ', ' ', ' '}, {'w', ' ', ' ', ' ', ' ', ' ', ' '}, {'x', ' ', ' ', ' ', ' ', ' ', ' '}, {'y', ' ', ' ', ' ', ' ', ' ', ' '}, {'z', ' ', ' ', ' ', ' ', ' ', ' '}, {'\0', '\0', '\0', '\0', '\0', '\0', '\0'}};

  int numberOfTokens = calculateNumberOfTokens(playerTokens);
  // printf("%i \n", numberOfTokens);

  numberOfPlayers = promptForNumberOfPlayers(numberOfTokens);
  // printf("%i \n", numberOfPlayers);

  assignValuesToArrayOfCellValues(arrayOfCellValues);

  int numberOfCells = promptForNumberOfCells();

  int numberOfCellsInOneRow = calculateNumberOfCellsInOneRow(numberOfCells);

  // drawBoard(arrayOfCellValues, playerTokens);

  // int playerNumber = playUntilOnePlayerWins(arrayOfCellValues);

  // displayCongratulatoryMessage(playerNumber);

  // int indexOfArrayOfCellValues = 0;
  // for (; arrayOfCellValues[indexOfArrayOfCellValues][0] != '\0', indexOfArrayOfCellValues++) {
  // }
}
