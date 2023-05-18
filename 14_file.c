// ?WAP to illustrate the fseek() in random access file.

#include <stdio.h>

int main()
{
  char ch;

  // Open the file in read mode
  FILE *file = fopen("random.txt", "r");
  if (file == NULL)
  {
    printf("File could not be opened!\n");
    return -1;
  }

  /*
  Suppose random.txt have following contents:
  Education beats the beauty
  */

  // SEEK_SET -> Beginning of file
  fseek(file, 5, SEEK_SET);
  ch = fgetc(file);
  printf("%c ", ch); // ch -> t

  // SEEK_CUR -> Current position of file
  fseek(file, -3, SEEK_CUR);
  ch = fgetc(file);
  printf("%c ", ch); // ch -> c

  // SEEK_END -> End position of file
  fseek(file, -3, SEEK_END);
  ch = fgetc(file);
  printf("%c ", ch); // ch -> u

  // Close the file
  fclose(file);
  return 0;
}