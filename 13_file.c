// ?WAP to create a file named "info.dat" and store records of N employee in the file. These records contain name, id, office_name, and designation of the employees. Also display the name of those employees whose office name is "Bent Ray" and designation is "Software Engineering".

#include <stdio.h>
#include <string.h>

#define MAX 100

struct employee
{
  int id;
  char name[MAX], office_name[MAX], designation[MAX];
};

int main()
{
  struct employee e[MAX];
  int n, i;

  // Get the number of employees from the user
  printf("Enter the number of employees: ");
  scanf("%d", &n);

  // Create a binary file named "info.dat" for writing
  FILE *file = fopen("info.dat", "wb");

  // Check if the file was created successfully
  if (file == NULL)
  {
    printf("File could not be created!\n");
    return -1;
  }

  // Read the details of the employees from the user and write them to the file
  printf("Enter the details of the employees:\n");
  for (i = 0; i < n; i++)
  {
    printf("Employee %d:\n", i + 1);
    printf("ID: ");
    scanf("%d", &e[i].id);
    printf("Name: ");
    scanf(" %[^\n]s", e[i].name);
    printf("Office Name: ");
    scanf(" %[^\n]s", e[i].office_name);
    printf("Designation: ");
    scanf(" %[^\n]s", e[i].designation);

    // Write the employee record to the file
    fwrite(&e[i], sizeof(struct employee), 1, file);
  }
  fclose(file);

  // Open the file in binary read mode
  file = fopen("info.dat", "rb");

  // Check if the file was opened successfully
  if (file == NULL)
  {
    printf("File could not be opened!\n");
    return -1;
  }

  // Display the records of employees with office name "Bent Ray" and designation "Software Engineering"
  printf("Records of employees with office name \"Bent Ray\" and designation \"Software Engineering\"\n\n");
  i = 0;
  while (fread(&e[i], sizeof(struct employee), 1, file) == 1)
  {
    if (strcmp(e[i].office_name, "Bent Ray") == 0 && strcmp(e[i].designation, "Software Engineering") == 0)
    {
      printf("ID: %d\nNAME: %s\nOFFICE: %s\nDESIGNATION: %s\n\n", e[i].id, e[i].name, e[i].office_name, e[i].designation);
    }
    i++;
  }
  fclose(file);
  return 0;
}
