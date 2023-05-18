// ?Write a program to read and write student data having roll and name using random access file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct
{
  int roll;
  char name[MAX];
} Student;

int main()
{
  int num;
  Student student;
  FILE *file = fopen("students.dat", "wb");
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  // Get the number of students from the user
  printf("Enter the number of students: ");
  scanf("%d", &num);

  // Write student data to the file
  for (int i = 0; i < num; i++)
  {
    printf("Enter roll number for student %d: ", i + 1);
    scanf("%d", &student.roll);
    printf("Enter name for student %d: ", i + 1);
    scanf(" %[^\n]s", student.name);

    // Move the file pointer to the correct position for writing
    fseek(file, i * sizeof(Student), SEEK_SET);

    // Write the student record to the file
    fwrite(&student, sizeof(Student), 1, file);
  }

  fclose(file);

  // Read and display student data from the file
  file = fopen("students.dat", "rb");
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  printf("\nStudent data:\n");
  for (int i = 0; i < num; i++)
  {
    // Move the file pointer to the correct position for reading
    fseek(file, i * sizeof(Student), SEEK_SET);

    // Read the student record from the file
    fread(&student, sizeof(Student), 1, file);

    // Display the student record
    printf("Roll: %d, Name: %s\n", student.roll, student.name);
  }
  fclose(file);
  return 0;
}
