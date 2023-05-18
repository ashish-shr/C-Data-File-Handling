// ?WAP to read the contents of three files and write the file with largest number of characters into an output file.

#include <stdio.h>
#define MAX 50

int main()
{
  char file_name1[MAX], file_name2[MAX], file_name3[MAX], output_file_name[MAX];
  FILE *file1, *file2, *file3, *output_file, *largest_file;
  int file1_size = 0, file2_size = 0, file3_size = 0;
  char c;

  // Get the name of the first file from the user
  printf("Enter the name of the first file: ");
  scanf("%s", file_name1);

  // Open the first file in read mode
  file1 = fopen(file_name1, "r");

  if (file1 == NULL)
  {
    printf("Failed to open file: %s\n", file_name1);
    return -1;
  }

  // Calculate the size of the first file
  while ((c = fgetc(file1)) != EOF)
  {
    file1_size++;
  }

  fclose(file1);

  // Get the name of the second file from the user
  printf("Enter the name of the second file: ");
  scanf("%s", file_name2);

  // Open the second file in read mode
  file2 = fopen(file_name2, "r");

  if (file2 == NULL)
  {
    printf("Failed to open file: %s\n", file_name2);
    return -1;
  }

  // Calculate the size of the second file
  while ((c = fgetc(file2)) != EOF)
  {
    file2_size++;
  }

  fclose(file2);

  // Get the name of the third file from the user
  printf("Enter the name of the third file: ");
  scanf("%s", file_name3);

  // Open the third file in read mode
  file3 = fopen(file_name3, "r");

  if (file3 == NULL)
  {
    printf("Failed to open file: %s\n", file_name3);
    return -1;
  }

  // Calculate the size of the third file
  while ((c = fgetc(file3)) != EOF)
  {
    file3_size++;
  }

  fclose(file3);

  // Determine which file is the largest
  if (file1_size >= file2_size && file1_size >= file3_size)
  {
    largest_file = fopen(file_name1, "r");
  }
  else if (file2_size >= file1_size && file2_size >= file3_size)
  {
    largest_file = fopen(file_name2, "r");
  }
  else
  {
    largest_file = fopen(file_name3, "r");
  }

  // Get the name of the output file from the user
  printf("Enter the name of the output file: ");
  scanf("%s", output_file_name);

  // Create the output file in write mode
  output_file = fopen(output_file_name, "w");

  if (output_file == NULL)
  {
    printf("Failed to create output file.\n");
    return -1;
  }

  // Write the contents of the largest file to the output file
  while ((c = fgetc(largest_file)) != EOF)
  {
    fputc(c, output_file);
  }

  fclose(largest_file);
  fclose(output_file);
  printf("Done.\n");
  return 0;
}
