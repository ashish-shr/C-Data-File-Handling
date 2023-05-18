// ?WAP to read Roll number and Name of a student from the keyboard(user) and save it in a data file student.dat

#include <stdio.h>
#define MAX 25

// Define a structure to represent a student
struct student
{
  int roll;
  char name[MAX];
};

int main()
{
  struct student s;
  FILE *output_file;

  // Get the roll number from the user
  printf("Enter the roll no.: ");
  scanf("%d", &s.roll);

  // Get the name from the user
  printf("Enter the name: ");
  scanf("%[^\n]s", s.name);

  // Open the output file "student.txt" in write mode
  output_file = fopen("student.txt", "w");

  if (output_file == NULL)
  {
    printf("Failed to create output file.\n");
    return -1;
  }

  // Write the header and student information to the file
  fprintf(output_file, "\tRoll\tName\n");
  fprintf(output_file, "\t%d\t\t\t%s\n", s.roll, s.name);

  // Close the file
  fclose(output_file);

  printf("Done.\n");
  return 0;
}
