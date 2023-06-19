#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int numberOfPlayers;
char playerTokens[] = {'*', 'o', '$', '#', '=', '%', 'v', '\0'};

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

void assignValuesToArrayOfCellValues(char arrayOfCellValues[101][numberOfPlayers]) {
  for (int outerCount = 0; outerCount < 101; outerCount++) {
    for (int innerCount = 0; innerCount < numberOfPlayers; innerCount++) {
      // printf("(%i, %i) -%c/ \n", outerCount, innerCount, arrayOfCellValues[outerCount][innerCount]);
      arrayOfCellValues[outerCount][innerCount] = ' ';
      arrayOfCellValues[101][innerCount] = '\0';
      printf("(%i, %i) -%c/ \n", outerCount, innerCount, arrayOfCellValues[outerCount][innerCount]);
    }
  }
}
void drawBoard(char arrayOfCellValues[101][numberOfPlayers], char playerTokens[]) {

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

bool askIfPlayerWantsToPlay(int playerNumber) {
  char playerChoice;
  printf("Player %i, do you want to roll the dice - y/n? ", playerNumber);
  scanf("%c", &playerChoice);

  return (((playerChoice == 'Y') || (playerChoice == 'y')) ? true : false);
}

// #define RAND_MAX = 6;
int obtainRandomNumberOnDice(int playerNumber) {
  int numberOnDice = random() % 6 + 1;
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

int playUntilOnePlayerWins(char arrayOfCellValues[101][numberOfPlayers]) {
  for (;;) {
    int playerNumber = 0;
    for (; arrayOfCellValues[100][playerNumber] != ' '; playerNumber++) {
      bool playerChoice = askIfPlayerWantsToPlay(playerNumber);
      if (playerChoice) {
        int numberOnDice = obtainRandomNumberOnDice(playerNumber);
        int finalTile = calculateFinalTile(numberOnDice);
        markChoiceOnGrid(finalTile);
      } else {
        continue;
      }
    }
    if (arrayOfCellValues[100][playerNumber] != ' ') {
      return playerNumber;
    }
  }
}

int main() {

  char arrayOfCellValues[101][numberOfPlayers];

  // {{'1', '2', '3', '4', '5', '6', '7'}, {'b', ' ', ' ', ' ', ' ', ' ', ' '}, {'c', ' ', ' ', ' ', ' ', ' ', ' '}, {'d', ' ', ' ', ' ', ' ', ' ', ' '}, {'e', ' ', ' ', ' ', ' ', ' ', ' '}, {'f', ' ', ' ', ' ', ' ', ' ', ' '}, {'g', ' ', ' ', ' ', ' ', ' ', ' '}, {'h', ' ', ' ', ' ', ' ', ' ', ' '}, {'i', ' ', ' ', ' ', ' ', ' ', ' '}, {'j', ' ', ' ', ' ', ' ', ' ', ' '}, {'k', ' ', ' ', ' ', ' ', ' ', ' '}, {'l', ' ', ' ', ' ', ' ', ' ', ' '}, {'m', ' ', ' ', ' ', ' ', ' ', ' '}, {'n', ' ', ' ', ' ', ' ', ' ', ' '}, {'o', ' ', ' ', ' ', ' ', ' ', ' '}, {'p', ' ', ' ', ' ', ' ', ' ', ' '}, {'q', ' ', ' ', ' ', ' ', ' ', ' '}, {'r', ' ', ' ', ' ', ' ', ' ', ' '}, {'s', ' ', ' ', ' ', ' ', ' ', ' '}, {'t', ' ', ' ', ' ', ' ', ' ', ' '}, {'u', ' ', ' ', ' ', ' ', ' ', ' '}, {'v', ' ', ' ', ' ', ' ', ' ', ' '}, {'w', ' ', ' ', ' ', ' ', ' ', ' '}, {'x', ' ', ' ', ' ', ' ', ' ', ' '}, {'y', ' ', ' ', ' ', ' ', ' ', ' '}, {'z', ' ', ' ', ' ', ' ', ' ', ' '}, {'\0', '\0', '\0', '\0', '\0', '\0', '\0'}};

  int numberOfTokens = calculateNumberOfTokens(playerTokens);
  // printf("%i \n", numberOfTokens);

  numberOfPlayers = promptForNumberOfPlayers(numberOfTokens);
  // printf("%i \n", numberOfPlayers);

  assignValuesToArrayOfCellValues(arrayOfCellValues);

  drawBoard(arrayOfCellValues, playerTokens);

  int playerNumber = playUntilOnePlayerWins(arrayOfCellValues);

  // int indexOfArrayOfCellValues = 0;
  // for (; arrayOfCellValues[indexOfArrayOfCellValues][0] != '\0', indexOfArrayOfCellValues++) {
  // }
}
