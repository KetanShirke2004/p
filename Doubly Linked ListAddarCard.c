#include <stdio.h>
#include <stdlib.h>

struct node {
    long long aadhar;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* Insert at position */
void insert() {
    int pos, i;
    struct node *new, *temp = head;

    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter Aadhar number: ");
    scanf("%lld", &new->aadhar);

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        new->prev = NULL;
        new->next = head;
        if (head != NULL)
            head->prev = new;
        head = new;
        return;
    }

    for (i = 1; i < pos - 1; i++)
        temp = temp->next;

    new->next = temp->next;
    new->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = new;

    temp->next = new;
}

/* Delete node (by Aadhar number) */
void delete() {
    long long aadhar;
    struct node *temp = head;

    printf("Enter Aadhar number to delete: ");
    scanf("%lld", &aadhar);

    while (temp != NULL) {
        if (temp->aadhar == aadhar) {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            free(temp);
            printf("Aadhar deleted\n");
            return;
        }
        temp = temp->next;
    }
    printf("Aadhar not found\n");
}

/* Search node */
void search() {
    long long aadhar;
    struct node *temp = head;

    printf("Enter Aadhar number to search: ");
    scanf("%lld", &aadhar);

    while (temp != NULL) {
        if (temp->aadhar == aadhar) {
            printf("Aadhar found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Aadhar not found\n");
}

/* Modify Aadhar number */
void modify() {
    long long oldAadhar, newAadhar;
    struct node *temp = head;

    printf("Enter old Aadhar number: ");
    scanf("%lld", &oldAadhar);
    printf("Enter new Aadhar number: ");
    scanf("%lld", &newAadhar);

    while (temp != NULL) {
        if (temp->aadhar == oldAadhar) {
            temp->aadhar = newAadhar;
            printf("Aadhar updated\n");
            return;
        }
        temp = temp->next;
    }
    printf("Aadhar not found\n");
}

/* Display */
void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%lld <-> ", temp->aadhar);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Main */
int main() {
    int ch;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Modify Aadhar\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) insert();
        else if (ch == 2) delete();
        else if (ch == 3) search();
        else if (ch == 4) modify();
        else if (ch == 5) display();
        else break;
    }
    return 0;
}
