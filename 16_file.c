// ?WAP to illustrate the rewind() in random access file.

#include <stdio.h>

int main()
{
  char ch;

  // Open the file in read and write mode
  FILE *file = fopen("random.txt", "r+");
  if (file == NULL)
  {
    printf("File could not be opened!\n");
    return -1;
  }

  /*
  Suppose random.txt have following contents:
  Education beats the beauty
  */

  fseek(file, 10, SEEK_SET);
  while (!feof(file))
  {
    ch = fgetc(file);
    printf("%c", ch); // output: beats the beauty
  }

  // moves file pointer to beginning of file
  rewind(file);
  printf("\n");
  while (!feof(file))
  {
    ch = fgetc(file);
    printf("%c", ch); // output: Education beats the beauty
  }

  // Close the file
  fclose(file);
  return 0;
}