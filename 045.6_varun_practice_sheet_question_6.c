// 6) Sign-up, Sign-in

// Implement a system that enables signing-up and signing-in as described below.

// Description of actions
// 1: Sign-up
// 2: Sign-in
// 3: Exit

// Action: 1
// Username: varun
// Password: 2004
// New user registered!

// Action: 2
// Username: varun
// Password: 2004
// Successfully signed in!

#include <stdio.h>

struct member {
  char user_name[20];
  char pass_word[20];
};

struct member arr[50] = {{'o', 'o'}};

void sign_up() {
  struct member member_1;
  printf("Action 1: \n");
  printf("Enter username: ");
  scanf("%s", member_1.user_name);
  printf("Enter password: ");
  scanf("%s", member_1.pass_word);

  int count = 0;
  if()
  for(int count = 0; arr[count].user_name != 'o'; count++) {
    h
  }
  printf("New user registered! \n");
}

void sign_in() {
  struct member member_2;
  printf("Action 2: \n");
  printf("Enter username: ");
  scanf("%s", member_2.user_name);
  printf("Enter password: ");
  scanf("%s", member_2.pass_word);
  printf("Successfully signed in! \n");
}

int main() {
  int user_input;

  printf("\n");
  printf("Hello! Choose an action: \n1) Sign Up \n2) Sign In \n3) Exit \n \nEnter your choice: ");
  scanf("%d", &user_input);
  printf("\n");

  switch(user_input) {
    case 1: {
      sign_up();
      break;
    }
    case 2: {
      sign_in();
      break;
    }
    case 3: {
      printf("You have exited. \n");
      break;
    }
    default:
      printf("Your choice is not one of the options provided. Thus, exit has been chosen. \n");
      break;
  }
}
