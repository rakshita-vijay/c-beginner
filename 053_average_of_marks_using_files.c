// #include <stdio.h>

// int main () {
//   FILE *f_ptr_1;
//   FILE *f_ptr_2;
//   FILE *f_ptr_3;

//   int num_of_students;
//   printf("Enter the number of students: ");
//   scanf("%d", &num_of_students);

//   f_ptr_1 = fopen("marks.txt", "w");

//   int mark_to_be_entered;
//   float avg_marks = 0;

//   for (int mark_index = 0; mark_index < num_of_students; mark_index++) {
//     printf("Enter the marks of student #%d: ", mark_index + 1);
//     fscanf("%d", &mark_to_be_entered);
//     fputw(mark_to_be_entered, f_ptr_1);
//     avg_marks += mark_to_be_entered;
//   }
//   fclose(f_ptr_1);

//   avg_marks /= num_of_students;
//   printf("Avg: %f \n", avg_marks);

//   f_ptr_1 = fopen("marks.txt", "r");
//   f_ptr_2 = fopen("below_avg_marks.txt", "w");
//   f_ptr_3 = fopen("above_avg_marks.txt", "w");

//   for (int mark_index = 0; mark_index < num_of_students; mark_index++) {
//     mark_to_be_entered = fgetw(f_ptr_1);
//     if(mark_to_be_entered < avg_marks) {
//       fputw(mark_to_be_entered, f_ptr_2);
//     } else {
//       fputw(mark_to_be_entered, f_ptr_3);
//     }
//   }
//   fclose(f_ptr_1);
//   fclose(f_ptr_2);
//   fclose(f_ptr_3);

//   f_ptr_2 = fopen("below_avg_marks.txt", "r");
//   f_ptr_3 = fopen("above_avg_marks.txt", "r");

//   int marks_to_be_printed;

//   printf("Below average marks: \n");
//   while((marks_to_be_printed = fgetw(f_ptr_2)) != EOF) {
//     printf("%d  ", marks_to_be_printed);
//   }

//   printf("\n \n");

//   printf("Above average marks: \n");
//   while((marks_to_be_printed = fgetw(f_ptr_3)) != EOF) {
//     printf("%d  ", marks_to_be_printed);
//   }

//   printf("\n");

//   fclose(f_ptr_2);
//   fclose(f_ptr_3);
// }

// #include <stdio.h>
// #include <string.h>
// int main(){
//   FILE *fptr1;
//   char s[200];
//   scanf("%[^~]",s);
// 	fptr1 = fopen("file3.txt", "w");
// 	fputs(s,fptr1);
// 	fclose(fptr1);
// 	fptr1 = fopen("file3.txt", "r");
// 	char s1[200];
// 	fgets(s1,200,fptr1);
// 	fclose(fptr1);
// 	printf("%s %ld",s1,strlen(s1));
// }


// (char *) calloc(2 /*strings*/, strlen(string_from_user))
// char char_arr[2] = (char *) calloc(2 /*strings*/, 10);

// #include <stdio.h>

// int main() {
//   double pi = 3.14159265359;
//   printf("%9.3e", pi);
// }
// 3.142e+00

// characters, words, and lines

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//   int num_of_char = 0;
//   int num_of_words = 0;
//   int num_of_lines = 0;

//   char str_arr[20];
//   printf("Enter a string: ");
//   scanf("%[^\n]", str_arr);

//   FILE *f_ptr;
//   f_ptr = fopen("char_word_line.txt", "w");
//   fputs(str_arr, f_ptr);
//   fclose(f_ptr);

//   f_ptr = fopen("char_word_line.txt", "r");

//   if(f_ptr == NULL) {
//     printf("File could not be opened. \n");
//     exit(0);
//   }

//   char char_from_file;
//   while((char_from_file = fgetc(f_ptr)) != EOF) {
//     num_of_char++;
//     if(char_from_file == ' ' || char_from_file == '\0'  || char_from_file == '\n'  || char_from_file == '\t') {
//       num_of_words++;
//     } else if(char_from_file == '\n' || char_from_file == '\0') {
//       num_of_lines++;
//     }
//   }
//   if (num_of_char > 0) {
//     num_of_words++;
//     num_of_lines++;
//     }

//   fclose(f_ptr);

//   printf("Total characters: %d \n", num_of_char);
//   printf("Total words: %d \n", num_of_words);
//   printf("Total lines: %d \n", num_of_lines);

// }

// to insert a node to the beginning of a linked list

// #include <stdio.h>
// #include <stdlib.h>

// struct linked_list {
//   int num;
//   struct linked_list *next_node;
// }

// int main() {
//   int data_to_insert;
//   printf("Enter the number to insert into the beginning of the list: ");
//   scanf("%d", &data_to_insert);

//   // adding to the beginning
//   struct linked_list *first = NULL;
//   struct linked_list *temp;
//   temp.num = data_to_insert;
//   temp.(*next_node) = first;
//   first = temp;

//   while (linked_list.next_node != NULL) {
//     printf("%d", linked_list.num);
//     linked_list = linked_list.(*next_node);
//   }
// }

// #include <stdio.h>

// int main(){
//   int i;
//   int a[4]={1};
//   for(i=0; i<4;i++)
//   printf("%d ", a[i]);
// }

#include <stdio.h>
#include <string.h>

int main () {
  FILE *f_ptr;
  f_ptr = fopen("fruits.txt", "r"); // because the teacher is supposed to have the file already

  char arr[][5];
  int penalty;

  while (arr = fgetc(f_ptr) != EOF) {
    penalty = 0;

    for (int index = 0; index < strlen(arr); index++) {
      if (arr[index][0] != toupper(arr[index][0])) {
        penalty++;
        }
      for (int individual_index = 1; individual_index < strlen(arr[index][individual_index - 1]); individual_index++)
    }
    if(penalty > 0) {
      p
    }


    penalty = 0;

  }
}
