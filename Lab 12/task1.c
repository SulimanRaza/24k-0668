#include <stdio.h>
#include <stdlib.h>
int main()
{
    int numberofstudents;
    printf("Enter the number of students: ");
    scanf("%d", &numberofstudents);
    int *numberofgrades = (int *)malloc(numberofstudents * sizeof(int));
    if (numberofgrades == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    int **grades = (int **)malloc(numberofstudents * sizeof(int *));
    if (grades == NULL)
    {
        printf("Memory allocation failed.\n");
        free(numberofgrades);
        return 1;
    }
    for (int i = 0; i < numberofstudents; i++)
    {
        printf("Enter the number of grades for student %d: ", i + 1);
        scanf("%d", &numberofgrades[i]);
        grades[i] = (int *)malloc(numberofgrades[i] * sizeof(int));
        if (grades[i] == NULL)
        {
            printf("Memory allocation failed.\n");
            for (int j = 0; j < i; j++)
            {
                free(grades[j]);
            }
            free(grades);
            free(numberofgrades);
            return 1;
        }
        printf("Enter grades for student %d:\n", i + 1);
        for (int j = 0; j < numberofgrades[i]; j++)
        {
            printf("Grade %d: ", j + 1);
            scanf("%d", &grades[i][j]);
        }
    }
    printf("\nEntered Grades:\n");
    for (int i = 0; i < numberofstudents; i++)
    {
        printf("Student %d Grades: ", i + 1);
        for (int j = 0; j < numberofgrades[i]; j++)
        {
            printf("%d ", grades[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < numberofstudents; i++)
    {
        free(grades[i]);
    }
    free(grades);
    free(numberofgrades);
    return 0;
}