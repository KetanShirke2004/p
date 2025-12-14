#include <stdio.h>
#include <stdlib.h>

struct node {
    int roll, age;
    char name[20];
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* Insert at position */
void insert() {
    int pos, i;
    struct node *new, *temp = head;

    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter Roll No, Name, Age: ");
    scanf("%d %s %d", &new->roll, new->name, &new->age);

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

/* Delete node (by roll number) */
void delete() {
    int roll;
    struct node *temp = head;

    printf("Enter roll no to delete: ");
    scanf("%d", &roll);

    while (temp != NULL) {
        if (temp->roll == roll) {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            free(temp);
            printf("Deleted\n");
            return;
        }
        temp = temp->next;
    }
    printf("Roll not found\n");
}

/* Search node */
void search() {
    int roll;
    struct node *temp = head;

    printf("Enter roll no to search: ");
    scanf("%d", &roll);

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Found: %s Age:%d\n", temp->name, temp->age);
            return;
        }
        temp = temp->next;
    }
    printf("Not found\n");
}

/* Modify roll number */
void modify() {
    int oldRoll, newRoll;
    struct node *temp = head;

    printf("Enter old roll no: ");
    scanf("%d", &oldRoll);
    printf("Enter new roll no: ");
    scanf("%d", &newRoll);

    while (temp != NULL) {
        if (temp->roll == oldRoll) {
            temp->roll = newRoll;
            printf("Roll updated\n");
            return;
        }
        temp = temp->next;
    }
    printf("Roll not found\n");
}

/* Display */
void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("Roll:%d Name:%s Age:%d\n",
               temp->roll, temp->name, temp->age);
        temp = temp->next;
    }
}

/* Main */
int main() {
    int ch;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Modify Roll\n5.Display\n6.Exit\n");
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
