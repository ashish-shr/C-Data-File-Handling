// ?WAP to read two numbers from the file and save the sum of these numbers in a file sum.dat.

#include <stdio.h>

int main()
{
  int a, b, sum;
  FILE *input_file, *output_file;

  // Open the input file "input.txt" in read mode
  input_file = fopen("input.txt", "r");

  // Open the output file "sum.dat" in write mode
  output_file = fopen("sum.dat", "w");

  if (input_file == NULL || output_file == NULL)
  {
    printf("Failed to open file.\n");
    return -1;
  }

  // Read two numbers from the input file
  fscanf(input_file, "%d %d", &a, &b);

  // Calculate the sum
  sum = a + b;

  // Write the sum to the output file
  fprintf(output_file, "%d", sum);

  // Close the files
  fclose(input_file);
  fclose(output_file);

  printf("Done.\n");
  return 0;
}
