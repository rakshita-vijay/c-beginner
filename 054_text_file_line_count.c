#include <stdio.h>
#include <string.h>

int main () {
  char buff[100];
  int counter = 0;
  char c = ' ';

  FILE *f_ptr;
  f_ptr = fopen("054_file_line_count.txt", "w+");

  printf("Enter content of the text file, end it with a '~' if you have finished your text block: \n");
  scanf("%[^~]", buff);

  // printf("\n");
  // printf("Buff: \n%s \n", buff);

  if (f_ptr != NULL) {
    fputs(buff, f_ptr);
  }

  rewind(f_ptr);

  while((c = fgetc(f_ptr)) != EOF) {
    if (c == '\n') {
      counter++;
    } else {
      continue;
    }
  }

  if((counter == 0) || (c != ' ')) {
    counter++;
  }

  printf("Number of lines in the file is: %i \n", counter);

  fclose(f_ptr);
  f_ptr = NULL;
}
