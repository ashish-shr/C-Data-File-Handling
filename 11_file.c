// ?Suppose there is a given text file myfile.txt, create another text file change.txt, and copying it by deleting all the vowels (a,e, i, o, u) of the file myfile.txt and then display it on screen.

#include <stdio.h>
#define MAX 100

int main()
{
  FILE *input_file, *output_file;
  char contents;

  // Open the input file "myfile.txt" in read mode
  input_file = fopen("myfile.txt", "r");
  if (input_file == NULL)
  {
    printf("File could not be opened!\n");
    return -1;
  }

  // Open the output file "change.txt" in write mode
  output_file = fopen("change.txt", "w");
  if (output_file == NULL)
  {
    printf("File could not be opened!\n");
    return -1;
  }

  // Read each character from the input file
  while ((contents = fgetc(input_file)) != EOF)
  {
    // If the character is not a vowel, write it to the output file
    if (contents != 'a' && contents != 'e' && contents != 'i' && contents != 'o' && contents != 'u')
    {
      fputc(contents, output_file);
    }
  }

  // Close the input and output files
  fclose(input_file);
  fclose(output_file);

  printf("Done\n");
  return 0;
}
