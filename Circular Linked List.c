#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Create circular linked list */
void create() {
    int n, i, x;
    struct node *new, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &x);
        new->data = x;

        if (head == NULL) {
            head = new;
            new->next = head;
        } else {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = new;
            new->next = head;
        }
    }
}

/* Display list */
void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (1) {
        printf("%d -> ", temp->data);
        temp = temp->next;
        if (temp == head)
            break;
    }
    printf("HEAD\n");
}

/* Delete from any position */
void deletePos() {
    int pos, i;
    struct node *temp = head, *del;

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos == 1) {
        while (temp->next != head)
            temp = temp->next;
        del = head;
        temp->next = head->next;
        head = head->next;
        free(del);
        return;
    }

    for (i = 1; i < pos - 1; i++)
        temp = temp->next;

    del = temp->next;
    temp->next = del->next;
    free(del);
}

/* Search element */
void search() {
    int x;
    struct node *temp = head;

    printf("Enter element to search: ");
    scanf("%d", &x);

    if (head == NULL)
        return;

    while (1) {
        if (temp->data == x) {
            printf("Element found\n");
            return;
        }
        temp = temp->next;
        if (temp == head)
            break;
    }
    printf("Element not found\n");
}

/* Main */
int main() {
    int ch;
    while (1) {
        printf("\n1.Create\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) create();
        else if (ch == 2) deletePos();
        else if (ch == 3) search();
        else if (ch == 4) display();
        else break;
    }
    return 0;
}
