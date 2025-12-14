#include <stdio.h>

int findSmallestMissingPositive(int arr[], int size) {
    int expected = 1;

    for (int i = 0; i < size; i++) {
        if (arr[i] == expected) {
            expected++;
        }
    }
    return expected;
}

int main() {
    int arr[] = {-4, -2, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = findSmallestMissingPositive(arr, size);
    printf("Smallest missing positive integer: %d", result);

    return 0;
}
