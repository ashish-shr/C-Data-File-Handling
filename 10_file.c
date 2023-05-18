// ?WAP to copy the content of file input.txt to the file output.txt.

#include <stdio.h>

int main()
{
  FILE *input_file, *output_file;
  char c;

  // Open the input file "input.txt" in read mode
  input_file = fopen("input.txt", "r");

  // Open the output file "output.txt" in write mode
  output_file = fopen("output.txt", "w");

  if (input_file == NULL || output_file == NULL)
  {
    printf("Failed to open file.\n");
    return -1;
  }

  // Copy the contents of the input file to the output file character by character
  while ((c = fgetc(input_file)) != EOF)
  {
    fputc(c, output_file);
  }

  // Close the files
  fclose(input_file);
  fclose(output_file);

  printf("Done.\n");
  return 0;
}
