// ?WAP that reads all the numbers from the input file values.dat, display these numbers and stores the average of these numbers in an output file named as average.dat.

#include <stdio.h>

int main()
{
  FILE *input_file, *output_file;
  int num, count = 0;
  float sum = 0, avg;

  // Open the input file "values.dat" in read mode
  input_file = fopen("values.dat", "r");

  // Open the output file "average.dat" in write mode
  output_file = fopen("average.dat", "w");

  if (input_file == NULL || output_file == NULL)
  {
    printf("Failed to open file.\n");
    return 1;
  }

  // Read numbers from the input file and calculate their sum
  while (fscanf(input_file, "%d", &num) != EOF)
  {
    printf("%d ", num); // Display each number
    sum += num;
    count++;
  }

  avg = sum / count; // Calculate the average

  // Write the average to the output file
  fprintf(output_file, "%f", avg);

  // Close the files
  fclose(input_file);
  fclose(output_file);

  printf("\nDone.\n");
  return 0;
}
