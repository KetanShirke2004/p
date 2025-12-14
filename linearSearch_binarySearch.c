#include <stdio.h>
#include <string.h>

/* Linear Search (Unsorted array) */
int linearSearch(char arr[][20], int n, char key[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i], key) == 0)
            return i;
    }
    return -1;
}

/* Binary Search (Sorted array) */
int binarySearch(char arr[][20], int n, char key[]) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(arr[mid], key);

        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    char unsorted[][20] = {"apple", "banana", "grape", "orange", "mango"};
    char sorted[][20]   = {"apple", "banana", "grape", "mango", "orange"};
    char key[20];
    int n = 5;

    printf("Enter word to search: ");
    scanf("%s", key);

    int idx1 = linearSearch(unsorted, n, key);
    int idx2 = binarySearch(sorted, n, key);

    printf("\nLinear Search (Unsorted Array): Index = %d\n", idx1);
    printf("Binary Search (Sorted Array): Index = %d\n", idx2);

    return 0;
}
