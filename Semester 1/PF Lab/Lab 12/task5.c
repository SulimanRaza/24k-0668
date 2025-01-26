#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertElement(int **array, int value, int pos, int *count)
{
    int *newArray = realloc(*array, sizeof(int) * ((*count) + 1));
    if (!newArray)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    *array = newArray;

    for (int i = (*count); i >= pos; i--)
    {
        (*array)[i] = (*array)[i - 1];
    }

    (*array)[pos - 1] = value;

    (*count)++;
}

void deleteElement(int *array, int *count, int pos)
{
    if (pos < 1 || pos > *count)
    {
        printf("Invalid delete position: %d\n", pos);
        return;
    }

    for (int i = pos - 1; i < *count - 1; i++)
    {
        array[i] = array[i + 1];
    }

    (*count)--;
}

void processTestCase()
{
    int count;
    printf("Enter total elements: ");
    scanf("%d", &count);

    if (count <= 0)
    {
        printf("Invalid number of elements.\n");
        return;
    }

    int *array = (int *)malloc(sizeof(int) * count);
    if (!array)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the numbers: ");
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &array[i]);
    }

    char choice[10];
    do
    {
        printf("Enter operation (I X P / D P / END): ");
        scanf("%s", choice);

        if (strcmp(choice, "I") == 0)
        {
            int value, pos;
            printf("Emter Value and positoin: ");
            scanf("%d %d", &value, &pos);

            if (pos < 1 || pos > count + 1)
            {
                printf("Invalid insert position: %d\n", pos);
                continue;
            }

            insertElement(&array, value, pos, &count);
        }
        else if (strcmp(choice, "D") == 0)
        {
            int pos;
            printf("Enter Position to Delete");
            scanf("%d", &pos);

            deleteElement(array, &count, pos);
        }
        else if (strcmp(choice, "END") != 0)
        {
            printf("Invalid operation. Try again.\n");
        }
    } while (strcmp(choice, "END") != 0);

    printf("Final array: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
}

int main()
{
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        printf("\nProcessing test case %d:\n", t + 1);
        processTestCase();
    }

    return 0;
}