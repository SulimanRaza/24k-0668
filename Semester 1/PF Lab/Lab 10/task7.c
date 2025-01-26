#include <stdio.h>
void bubblesort(int arr[], int n)
{
    if (n == 1)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    bubblesort(arr, n - 1);
}
int main(void)
{
    int size;
    printf("Enter total numbers: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter numbers: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nUnsorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    bubblesort(arr, size);
    printf("\nSorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}