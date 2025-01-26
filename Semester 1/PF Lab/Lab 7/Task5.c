#include <stdio.h>

int main() {
    int arr[20];
    printf("Enter Array Elements:");
    for (int i = 0; i < 20; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Numbers in reverse order are:\n");
    for (int i = 19; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    return 0;
}