#include <stdio.h>
#define SIZE 10

int hash[SIZE];

/* Initialize hash table */
void init() {
    int i;
    for (i = 0; i < SIZE; i++)
        hash[i] = -1;
}

/* Insert key */
void insert() {
    int key, index, i;

    printf("Enter key: ");
    scanf("%d", &key);

    index = key % SIZE;

    for (i = 0; i < SIZE; i++) {
        if (hash[index] == -1) {
            hash[index] = key;
            printf("Key inserted\n");
            return;
        }
        index = (index + 1) % SIZE;   // Linear probing
    }
    printf("Hash table is full\n");
}

/* Search key */
void search() {
    int key, index, i;

    printf("Enter key to search: ");
    scanf("%d", &key);

    index = key % SIZE;

    for (i = 0; i < SIZE; i++) {
        if (hash[index] == key) {
            printf("Key found at index %d\n", index);
            return;
        }
        if (hash[index] == -1)
            break;
        index = (index + 1) % SIZE;
    }
    printf("Key not found\n");
}

/* Display hash table */
void display() {
    int i;
    printf("Hash Table:\n");
    for (i = 0; i < SIZE; i++)
        printf("Index %d : %d\n", i, hash[i]);
}

/* Main */
int main() {
    int ch;
    init();

    while (1) {
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) insert();
        else if (ch == 2) search();
        else if (ch == 3) display();
        else break;
    }
    return 0;
}
