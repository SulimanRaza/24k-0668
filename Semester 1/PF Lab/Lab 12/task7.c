#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols, row_to_modify, col_to_modify, new_value;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int **array = (int **)malloc(rows * sizeof(int *));
    if (array == NULL)
    {
        printf("Memory allocation failed for rows.\n");
        return 1;
    }
    for (int i = 0; i < rows; i++)
    {
        array[i] = (int *)malloc(cols * sizeof(int));
        if (array[i] == NULL)
        {
            printf("Memory allocation failed for columns.\n");
            for (int j = 0; j < i; j++)
            {
                free(array[j]);
            }
            free(array);
            return 1;
        }
    }

    printf("Enter the values for the 2D array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    printf("Enter the row and column of the element to modify: ");
    scanf("%d %d", &row_to_modify, &col_to_modify);
    if (row_to_modify >= 0 && row_to_modify < rows && col_to_modify >= 0 && col_to_modify < cols)
    {
        printf("Enter the new value: ");
        scanf("%d", &new_value);
        array[row_to_modify][col_to_modify] = new_value;
    }
    else
    {
        printf("Invalid row or column.\n");
    }

    printf("The 2D array is:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
    {
        free(array[i]);
    }
    free(array);

    return 0;
}