#include <stdio.h>
int main() {
    int arr[30], min, max;
    printf("Enter Array Elements:");
    for (int i = 0; i < 30; i++) {
        scanf("%d", &arr[i]);
    }    
    min=arr[0];
    max=arr[0];
    for (int i = 1; i < 30; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Minimum Number = %d\n", min);
    printf("Maximum Number = %d", max);

    return 0;
}