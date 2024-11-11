#include <stdio.h>

int main()
{
    int n;

    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }

        for (int j = n - i; j >= 1; j--)
        {
            printf("%d ", j);
        }
        printf("\n");
    }

    for (int i = n - 2; i >= 0; i--)
    {

        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }

        for (int j = n - i; j >= 1; j--)
        {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}
