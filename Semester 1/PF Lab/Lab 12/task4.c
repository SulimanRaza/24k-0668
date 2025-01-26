#include <stdio.h>
#include <stdlib.h>
int findMostFrequentNumber(int *arr, int n)
{
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    int range = max - min + 1;
    int *frequency = (int *)calloc(range, sizeof(int));
    if (frequency == NULL)
    {
        printf("Memory allocation failed for frequency array.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        frequency[arr[i] - min]++;
    }
    int maxFreq = 0, result = max;
    for (int i = 0; i < range; i++)
    {
        if (frequency[i] > maxFreq || (frequency[i] == maxFreq && (i + min) < result))
        {
            maxFreq = frequency[i];
            result = i + min;
        }
    }
    free(frequency);
    return result;
}
int main()
{
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);
    while (T--)
    {
        int N;
        printf("Enter the number of elements: ");
        scanf("%d", &N);
        int *arr = (int *)malloc(N * sizeof(int));
        if (arr == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }
        printf("Enter the elements of the array:\n");
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }
        int result = findMostFrequentNumber(arr, N);
        printf("\nThe smallest number with highest frequency is: %d\n", result);
        free(arr);
    }
    return 0;
}