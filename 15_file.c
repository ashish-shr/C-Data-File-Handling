// ?WAP to illustrate the ftell() in random access file.

#include <stdio.h>

int main()
{
  char ch;
  long int pos;

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

  pos = ftell(file);
  printf("%ld ", pos); // pos ->0

  fseek(file, 5, SEEK_SET);
  pos = ftell(file);
  printf("%ld ", pos); // pos ->5

  fseek(file, -3, SEEK_CUR);
  pos = ftell(file);
  printf("%ld ", pos); // pos ->2

  fseek(file, -3, SEEK_END);
  pos = ftell(file);
  printf("%ld ", pos); // pos ->23

  // Close the file
  fclose(file);
  return 0;
}