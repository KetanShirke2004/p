#include <stdio.h>

#define MAX 50

long mergeCount = 0;
long quickCount = 0;

/* Merge function */
void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[MAX];

    while (i <= mid && j <= high) {
        mergeCount++;
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

/* Merge Sort */
void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

/* Partition for Quick Sort */
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        quickCount++;
        if (a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

/* Quick Sort */
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

/* Display */
void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n, a[MAX], b[MAX];

    printf("Enter number of elements (max 50): ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];   // copy for quick sort
    }

    mergeSort(a, 0, n - 1);
    quickSort(b, 0, n - 1);

    printf("\nMerge Sort Result:\n");
    display(a, n);
    printf("Comparisons in Merge Sort: %ld\n", mergeCount);

    printf("\nQuick Sort Result:\n");
    display(b, n);
    printf("Comparisons in Quick Sort: %ld\n", quickCount);

    return 0;
}
