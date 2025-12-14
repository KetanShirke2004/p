#include <stdio.h>
#include <stdlib.h>

struct node {
    long pan;              // PAN number
    struct node *next;
};

struct node *head = NULL;

/* Insert at position */
void insert() {
    int pos, i;
    struct node *new, *temp = head;

    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter PAN number: ");
    scanf("%ld", &new->pan);

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        new->next = head;
        head = new;
        return;
    }

    for (i = 1; i < pos - 1; i++)
        temp = temp->next;

    new->next = temp->next;
    temp->next = new;
}

/* Delete node */
void delete() {
    long pan;
    struct node *temp = head, *prev = NULL;

    printf("Enter PAN number to delete: ");
    scanf("%ld", &pan);

    while (temp != NULL) {
        if (temp->pan == pan) {
            if (temp == head)
                head = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            printf("Deleted\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("PAN not found\n");
}

/* Search node */
void search() {
    long pan;
    struct node *temp = head;

    printf("Enter PAN number to search: ");
    scanf("%ld", &pan);

    while (temp != NULL) {
        if (temp->pan == pan) {
            printf("PAN found\n");
            return;
        }
        temp = temp->next;
    }
    printf("PAN not found\n");
}

/* Display */
void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%ld -> ", temp->pan);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Main */
int main() {
    int ch;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) insert();
        else if (ch == 2) delete();
        else if (ch == 3) search();
        else if (ch == 4) display();
        else break;
    }
    return 0;
}
