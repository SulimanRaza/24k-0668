#include <stdio.h>

int main()
{
    int arr[3][3];
    int rowsum[3] = {0, 0, 0};
    int columnsum[3] = {0, 0, 0};

    printf("Enter the elements of the matrix\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            rowsum[i] += arr[i][j];
            columnsum[j] += arr[i][j];
        }
    }

    printf("Total score for each participant:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Row %d sum: %d\n", i + 1, rowsum[i]);
    }

    printf("Total score for each activity:\n");
    for (int j = 0; j < 3; j++)
    {
        printf("Column %d sum: %d\n", j + 1, columnsum[j]);
    }

    return 0;
}
