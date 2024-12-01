#include <stdio.h>
#include <stdlib.h>
void displayArray(float *array, int size)
{
    if (size == 0)
    {
        printf("Empty Array.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}
int main()
{
    int capacity = 4;
    int size = 0;
    float *array = (float *)malloc(capacity * sizeof(float));
    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    int choice;
    do
    {
        printf("\nMenu:\n");
        printf("1. Add a new number to the array\n");
        printf("2. Display all numbers in the array\n");
        printf("3. Remove the last number from the array\n");
        printf("4. Reduce memory size to fit current elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            float num;
            printf("Enter a floating-point number: ");
            scanf("%f", &num);
            if (size == capacity)
            {
                capacity *= 2;
                float *newArray = (float *)realloc(array, capacity * sizeof(float));
                if (newArray == NULL)
                {
                    printf("Memory allocation failed during resizing.\n");
                    free(array);
                    return 1;
                }
                array = newArray;
            }
            array[size++] = num;
            break;
        }
        case 2:
            displayArray(array, size);
            break;
        case 3:
            if (size > 0)
            {
                size--;
                printf("Last number removed.\n");
            }
            else
            {
                printf("The array is already empty.\n");
            }
            break;
        case 4:
            if (size < capacity)
            {
                float *newArray = (float *)realloc(array, size * sizeof(float));
                if (newArray == NULL)
                {
                    printf("Memory reallocation failed.\n");
                }
                else
                {
                    array = newArray;
                    capacity = size;
                    printf("Memory size reduced to fit current elements.\n");
                }
            }
            else
            {
                printf("No need to reduce memory; capacity already matches the size.\n");
            }
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    free(array);
    return 0;
}