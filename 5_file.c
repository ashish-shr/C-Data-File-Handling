// ?WAP to read a string from an existing file test.txt using fscanf() function

#include <stdio.h>
#include <string.h>

int main()
{
  FILE *input_file;
  char str[50];

  // Open the file named "test.txt" in read mode
  input_file = fopen("test.txt", "r");

  if (input_file == NULL)
  {
    printf("Failed to open input file.\n");
    return -1;
  }

  // Read a string from the file using fscanf()
  fscanf(input_file, "%s", str);

  // Print the string
  printf("The string is: %s\n", str);

  // Close the file
  fclose(input_file);

  printf("Done.\n");
  return 0;
}
