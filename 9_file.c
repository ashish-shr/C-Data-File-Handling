// ?WAP to append some content in an existing file append.txt

#include <stdio.h>

int main()
{
  FILE *output_file;
  char str[50];

  // Open the file "append.txt" in append mode
  output_file = fopen("append.txt", "a");

  if (output_file == NULL)
  {
    printf("Failed to open input file.\n");
    return -1;
  }

  printf("Enter the string: ");
  gets(str);

  // Append the string to the file
  fprintf(output_file, "%s ", str);

  // Close the file
  fclose(output_file);

  printf("Done.\n");
  return 0;
}
