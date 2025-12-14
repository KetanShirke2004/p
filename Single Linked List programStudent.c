#include <stdio.h>
#include <stdlib.h>

struct node {
    int roll, age;
    char name[20];
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
    int roll;
    struct node *temp = head, *prev = NULL;

    printf("Enter roll no to delete: ");
    scanf("%d", &roll);

    while (temp != NULL) {
        if (temp->roll == roll) {
            if (temp == head)
                head = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

/* Search node */
void search() {
    int roll;
    struct node *temp = head;

    printf("Enter roll no to search: ");
    scanf("%d", &roll);

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Found: %s Age: %d\n", temp->name, temp->age);
            return;
        }
        temp = temp->next;
    }
    printf("Not Found\n");
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
}

/* Reverse list */
void reverse() {
    struct node *prev = NULL, *cur = head, *next;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

/* Display */
void display() {
    struct node *temp = head;
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
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Reverse\n5.Modify Roll\n6.Display\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) insert();
        else if (ch == 2) delete();
        else if (ch == 3) search();
        else if (ch == 4) reverse();
        else if (ch == 5) modify();
        else if (ch == 6) display();
        else break;
    }
    return 0;
}
