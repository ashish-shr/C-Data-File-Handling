// ?WAP that opens a given text file, create another text file deleting the following words "three", "bad" and "time".

#include <stdio.h>
#include <string.h>
#define MAX 50

int main()
{
  char input_file_name[MAX], output_file_name[MAX], word[MAX];
  FILE *input_file, *output_file;

  // Get the input file name from the user
  printf("Enter input file name: ");
  scanf("%s", input_file_name);

  // Open the input file in read mode
  input_file = fopen(input_file_name, "r");

  if (input_file == NULL)
  {
    printf("Failed to open input file.\n");
    return -1;
  }

  // Get the output file name from the user
  printf("Enter output file name: ");
  scanf("%s", output_file_name);

  // Create the output file in write mode
  output_file = fopen(output_file_name, "w");

  if (output_file == NULL)
  {
    printf("Failed to create output file.\n");
    return -1;
  }

  // Read words from the input file until the end
  while (fscanf(input_file, "%s", word) != EOF)
  {
    // Check if the current word is "three", "bad", or "time"
    // If not, write it to the output file
    if (strcmp(word, "three") != 0 && strcmp(word, "bad") != 0 && strcmp(word, "time") != 0)
    {
      fprintf(output_file, "%s ", word);
    }
  }

  // Close the input and output files
  fclose(input_file);
  fclose(output_file);

  printf("Done.\n");
  return 0;
}
