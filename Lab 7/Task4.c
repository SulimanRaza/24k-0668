#include <stdio.h>
int main() {
    int arr[15],sum=0;  
    printf("Enter Array Elements:");
    for (int i = 0; i < 15; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 15; i++) {
        sum += arr[i];
    }
    printf("Sum of the elements is: %d", sum);
    return 0;
}