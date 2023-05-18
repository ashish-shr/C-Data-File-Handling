// ?WAP to read information about the student record containing roll, name, age and total marks. Write the records to the file out.dat.

#include <stdio.h>
#define MAX 50

struct student
{
  int roll, age;
  char name[MAX];
  float marks;
};

int main()
{
  struct student s[MAX];
  FILE *file = fopen("out.dat", "wb");

  // Check if the file was opened successfully
  if (file == NULL)
  {
    printf("File could not be opened!\n");
    return -1;
  }

  int size, i;
  printf("No. of students: ");
  scanf("%d", &size);

  // Read student information from the user
  for (i = 0; i < size; i++)
  {
    printf("Roll: ");
    scanf("%d", &s[i].roll);
    printf("Name: ");
    scanf(" %[^\n]s", s[i].name);
    printf("Age: ");
    scanf("%d", &s[i].age);
    printf("Total Marks: ");
    scanf("%f", &s[i].marks);

    // Write the student record to the file
    fwrite(&s[i], sizeof(struct student), 1, file);
  }

  // Close the file
  fclose(file);
  return 0;
}
