#include <stdio.h>
int main()
{
    int row;
    printf("Enter Number of Rows: ");
    scanf("%d", &row);
    for (int i = row; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" . ");
        }
        for (int j = row; j >= i; j--)
        {
            printf("o");
        }
        printf("\n");
    }
    for (int i = 2; i <= row; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf(" . ");
        }
        for (int k = row; k >= i; k--)
        {
            printf("o");
        }
        printf("\n");
    }
    return 0;
}