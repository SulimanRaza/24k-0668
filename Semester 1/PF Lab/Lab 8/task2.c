#include <stdio.h>

int main()
{
    int arr[4][4];

    printf("Enter the grades for each student:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Enter grade for student %d, subject %d: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);

            if (arr[i][j] < 0)
            {
                arr[i][j] = 0;
            }
        }
    }

    printf("Revised Matrix\n");
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
