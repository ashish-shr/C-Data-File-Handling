// ?WAP to write a string to a file named test.txt using fprintf() function.

#include <stdio.h>
#include <string.h>

int main()
{
  FILE *input_file;
  char str[50];

  // Open the file named "test.txt" in write mode
  input_file = fopen("test.txt", "w");

  if (input_file == NULL)
  {
    printf("Failed to open input file.\n");
    return -1;
  }

  printf("Enter the string: ");
  gets(str);

  // Write the string to the file using fprintf()
  fprintf(input_file, "%s", str);

  // Close the file
  fclose(input_file);

  printf("Done.\n");
  return 0;
}
