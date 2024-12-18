#include <stdio.h>
#include <ctype.h>

int main() {
  FILE *file_1 = NULL;
  file_1 = fopen("055A_source_file.txt", "w+");

  char buff[100];
  printf("Enter content of the text file, end it with a '~' if you have finished your text block: \n");
  scanf("%[^~]", buff);

  if (file_1 != NULL) {
    fputs(buff, file_1);
  } else {
    return -1;
  }
  rewind(file_1);

  // printf("Contents of file_1: \n");
  // while(fgets(buff, 100, file_1) != NULL) {
  //   printf("%s", buff);
  // }
  // rewind(file_1);

  char c = ' ';
  FILE *file_2 = NULL;
  file_2 = fopen("055B_temp_file.txt", "w+");
  while((c = fgetc(file_1)) != EOF) {
    fputc(toupper(c), file_2);
  }
  rewind(file_2);

  // printf("\n~~~*~~~ \n");
  printf("\n");

  printf("Contents of file_2: \n");
  while(fgets(buff, 100, file_2) != NULL) {
    printf("%s", buff);
  }

  printf("\n");

  int value = rename("055B_temp_file.txt", "055B_destination_file.txt");
  printf("Renaming %s", ((value = 1) ? "successful! \n" : "unsuccessful :( \nTry again later! \n"));


  fclose(file_1);
  fclose(file_2);
}
