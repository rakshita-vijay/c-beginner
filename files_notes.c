file reading - characters:
-------------------------
fgetc(): reads a character from a text file that has been opened for reading
-------
takes file pointer as argument
returns the character read as type int

ex.: int mchar = fgetc(pfile);  // Reads a character into mchar with pfile as a File pointer
EOF will be returned if the end of the file has been reached

getc(): getc() = fgetc() [virtually identical]
------
argument of type FILE*
returns the character read as type int
only difference: getc() may be implemented as a macro, whereas fgetc() is a function

#include <stdio.h>

int main() {
  FILE *fp;
  int c;

  fp = fopen("file.txt", "r");

  if (fp == NULL) {
    perror("Error in opening file");
    return -1;
  }

  while ((c = fgetc(fp)) != EOF)
    printf("%c", c); // prints out entire content of file

  fclose(fp);
  fp = NULL;
}

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

file reading - strings:
----------------------
fgets(): function reads from any file or stream
-------
syntax: char *fgets(char *str, int nchars, FILE *stream)
        str: buffer
        nchars: number of characters to read
        stream: source file

characters:  read until either '\n' is read or (nchars-1) characters have been read from stream, whichever occurs first
if a newline character is read, it’s retained in the string

a '\0' character will be appended to the end of the string
no error --> fgets() returns the pointer str
error --> NULL is returned

reading EOF causes NULL to be returned

#include <stdio.h>

int main () {
  FILE *fp;
  char str[61];

  fp = fopen("file.txt", "r");

  if(fp == NULL) {
    perror("Error opening file");
    return -1;
  }

  if(fgets(str, 60, fp) != NULL) {
    printf("%s", str); // prints out entire content of file
  }

  fclose(fp);
  fp = NULL;
}

fscanf(): function
--------
syntax: int fscanf(FILE *stream, const char *format, buffer_destination_1, buffer_destination_2, ...)
        stream: source file
        format: "%x %y ..."
        buffer_destination_n: where to store the read data

format is a C string that contains one or more of the following items:
1) whitespace character
2) non-whitespace character
3) format specifiers
4) usage is similar to scanf, but, from a file

returns the number of input items successfully matched and assigned

#include <stdio.h>
#include <stdlib.h>

int main () {
  char str1[10], str2[10], str3[10];
  int year;

  FILE *fp = fopen("file.txt", "w+");
  if (fp != NULL)
    fputs("Hello how are you", fp);

  rewind(fp); // goes to the beginning of the file (places pointer there)

  fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);
  printf("Read String1 |%s| \n", str1);
  printf("Read String2 |%s| \n", str2);
  printf("Read String3 |%s| \n", str3);
  printf("Read Integer |%d| \n", year);

  fclose(fp);
}

/*
O/P:
Read String1 |Hello|
Read String2 |how|
Read String3 |are|
Read Integer |0|
*/

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

file writing - characters:
-------------------------
fputc(): writes a single character to a txt file
-------
syntax: int fputc(int ch, FILE *pfile);
        character (ch) written to the file pfile

returns the character that was written if successful
returns EOF if failure

extremely inefficient

putc(): putc() = fputc() [virtually identical]
------
syntax: int putc(int ch, FILE *pfile);

return type is the same
difference: putc() may be implemented in the standard library as a macro, whereas fputc() is a function

#include <stdio.h>

int main () {
  FILE *fp = fopen("file.txt", "w+");

  for(int ch = 33; ch <= 100; ch++) {
    fputc(ch, fp);
  }

  fclose(fp);
}

/*
O/P:
!"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcd
*/

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

file writing - strings:
----------------------
fputs():
-------
syntax: int fputs(const char *str, FILE *pfile);
character string (str) that is to be written to the file (pfile)

will write characters from a string until it reaches a '\0' characterc
does not write the null terminator character to the file

can complicate reading back variable-length strings from a file that have been written by fputs()
expecting to write a line of text that has a newline character at the end
have to have '\0' written either implicitly or explicitly

#include <stdio.h>

int main () {
  FILE *filePointer = fopen("file.txt", "w+");
  fputs("This is a Jason Fedin Course. ", filePointer);
  fputs("I am happy to be here :)", filePointer);

  fclose(filePointer);
}

/*
O/P:
This is a Jason Fedin Course. I am happy to be here :)
*/

fprintf(): formatted output written to a file
---------
syntax: int fprintf(FILE *stream, const char *format, ...)

format: a C string that contains one or more of the following items:
1) whitespace character
2) non-whitespace character
3) format specifiers

usage is similar to printf, but to a file

returns the total number of characters written if successful, else a negative number

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("file.txt", "w+");
  fprintf(fp, "%s %s %s %s %d", "Hello", "my", "number", "is", 555);
  fclose(fp);
}

/*
O/P:
Hello my number is 555
*/

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*

file positioning:
----------------
accessing data in a file in non-sequential order
1) finding out where you are in a file
2) moving to a given point in a file

you can access a file at a random position regardless of whether you opened the file ​​

Finding out where you are
1) ftell()
2) fgetpos()
~
ftell()
-------
syntax: long fpos = ftell(FILE *pfile);
        specifies the current position in the file
value is the offset in bytes from the beginning of the file

fseek():
-------
syntax: int fseek(FILE *pointer, long int offset, int position);
        pointer: source file
        offset: number of bytes to offset from the position
        position: position from where the offset is added. defines the point WRT which the file pointer needs to be moved
                  has three values:
                  SEEK_END: denotes EOF
                  SEEK_SET: denotes starting of file
                  SEEK_CUR: denotes current position
returns zero if successful, else returns a non-zero value

for text mode file, 2nd argument must be value returned by ftell()
                    3rd argument must be SEEK_SET
                    all operations with fseek() are performed WRT beginning of file

for binary files, offset: relative byte count
                  user can enter (+ve) or (-ve) values when reference point: SEEK_CUR

#include <stdio.h>

int main() {
  FILE *fp = fopen("file.txt", "w+");
  fputs("This is Jason.", fp);

  fseek(fp, 7, SEEK_SET); // 7 bytes from start of file
  fputs(" Hello, how are you?", fp);
  fclose(fp);
}

/*
O/P:
This is Hello, how are you?
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("file.txt", "r");
  if(fp == NULL) {
    perror("Error opening file");
    return -1;
  }
  fseek(fp, 0, SEEK_END); // denotes EOF

  int len = ftell(fp);
  printf("Total size of file.txt = %d bytes \n", len);

  fclose(fp);
}

/*
O/P:
Total size of file.txt = 27 bytes   // from last program when content was "This is Hello, how are you?"
*/

fgetpos()
---------
syntax: int fgetpos(FILE *pfile, fpos_t *position);
        file pointer, pointer to a type that is defined in stdio.h
fpos_t: a type that is able to record every position within a file

designed to be used with the positioning function fsetpos()

fgetpos(): stores current position and file state information for the file in position
          returns 0 if successful
          returns nonzero integer value if unsuccessful

fpos_t here; // variable declaration
fgetpos(pfile, &here);
                      - records the current file position in the variable 'here'
cannot declare a pointer of type fpos_t* because there will not be any memory allocated to store the position data

#include <stdio.h>
#include <stdlib.h>

int main() {
  fpos_t position;
  FILE *fp = fopen("file.txt", "w+"); // opens at the start of file

  fgetpos(fp, &position);
  fputs("Hello, World!", fp);

  fclose(fp);
}

/*
O/P:
Hello, World!
*/

fsetpos()
---------
syntax: int fsetpos(FILE *pfile, const fpos_t *position);
        position that is stored at the address: obtained by calling fgetpos()

fsetpos(pfile, &here);
                      - sets the file position to the value in variable 'here'
                      - value of 'here' is set by previous call to fgetpos()
returns 0 if successful
returns nonzero value if unsuccessful

designed to work with a value returned by fgetpos()
user can only use it to get to a place in a file that user has been before
fseek() allows user to go to any position just by specifying appropriate offset

#include <stdio.h>

int main() {
  fpos_t position;
  FILE *fp = fopen("file.txt", "w+");
  fgetpos(fp, &position); // position = 0 [start of file]
  fputs("Hello, World!", fp);

  fsetpos(fp, &position);
  fputs("This is going to override previous content", fp);
  fclose(fp);
}

/*
O/P:
This is going to override previous content
*/

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
