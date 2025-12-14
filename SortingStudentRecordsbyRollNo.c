#include <stdio.h>
#include <string.h>

struct student {
    char name[20];
    int roll;
    int age;
};

/* Display records */
void display(struct student s[], int n) {
    for (int i = 0; i < n; i++)
        printf("%s  %d  %d\n", s[i].name, s[i].roll, s[i].age);
}

/* Bubble Sort */
void bubbleSort(struct student s[], int n) {
    struct student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (s[j].roll > s[j + 1].roll) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

/* Selection Sort */
void selectionSort(struct student s[], int n) {
    struct student temp;
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (s[j].roll < s[min].roll)
                min = j;
        }
        temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }
}

/* Insertion Sort */
void insertionSort(struct student s[], int n) {
    struct student key;
    int j;
    for (int i = 1; i < n; i++) {
        key = s[i];
        j = i - 1;
        while (j >= 0 && s[j].roll > key.roll) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

int main() {
    struct student s[5] = {
        {"Ravi", 5, 20},
        {"Amit", 2, 21},
        {"Neha", 4, 19},
        {"Pooja", 1, 20},
        {"Kiran", 3, 22}
    };

    int n = 5, ch;

    printf("Original Records:\n");
    display(s, n);

    printf("\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\nEnter choice: ");
    scanf("%d", &ch);

    if (ch == 1)
        bubbleSort(s, n);
    else if (ch == 2)
        selectionSort(s, n);
    else if (ch == 3)
        insertionSort(s, n);

    printf("\nSorted Records by RollNo:\n");
    display(s, n);

    return 0;
}
