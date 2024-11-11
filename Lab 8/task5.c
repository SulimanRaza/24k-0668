#include <stdio.h>
int main()
{
    int arr[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Matrix before:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4 - 1; i++)
        {
            for (int k = i + 1; k < 4; k++)
            {
                if (arr[i][j] > arr[k][j])
                {
                    int temp = arr[i][j];
                    arr[i][j] = arr[k][j];
                    arr[k][j] = temp;
                }
            }
        }
    }
    printf("Matrix after sorted in ascending order:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
