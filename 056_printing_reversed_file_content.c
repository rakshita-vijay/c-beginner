#include <stdio.h>

int main() {
  FILE *f_ptr = fopen("056_file_content_to_reverse.txt", "w+");

  char content[100];
  printf("Enter content of the text file, end it with a '~' if you have finished your text block: \n");
  scanf("%[^~]", content);
  fputs(content, f_ptr);

  rewind(f_ptr); // goes to beginning

  fseek(f_ptr, 0, SEEK_END); // goes to end
  int position = ftell(f_ptr);

  for (int index = 1; index <= position; index++) {
    fseek(f_ptr, (position - index), SEEK_SET);
    printf("%c", fgetc(f_ptr));
  }
  printf("\n");

  fclose(f_ptr);
}
