#include <stdio.h>

#define SIZE 50

/* Check if array already sorted in descending order */
int isDescending(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1])
            return 0;   // not descending
    }
    return 1;           // already descending
}

/* Display array */
void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/* Bubble Sort (Descending) */
void bubbleSort(int a[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] < a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;   // early termination
    }
}

/* Selection Sort (Descending) */
void selectionSort(int a[], int n) {
    int temp, max;
    for (int i = 0; i < n - 1; i++) {
        max = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[max])
                max = j;
        }
        temp = a[i];
        a[i] = a[max];
        a[max] = temp;
    }
}

/* Insertion Sort (Descending) */
void insertionSort(int a[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    int a[SIZE], n, ch;

    printf("Enter number of elements (max 50): ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (isDescending(a, n)) {
        printf("Array already sorted in descending order:\n");
        display(a, n);
        return 0;
    }

    printf("\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\nEnter choice: ");
    scanf("%d", &ch);

    if (ch == 1)
        bubbleSort(a, n);
    else if (ch == 2)
        selectionSort(a, n);
    else if (ch == 3)
        insertionSort(a, n);

    printf("\nSorted Array (Descending):\n");
    display(a, n);

    return 0;
}
