#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("  Enter number %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    printf("Maximum element in the array is %d.", max);

    free(array);
}