#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

/* Enqueue at rear */
void enqueue() {
    int x;
    if (rear == MAX - 1) {
        printf("Queue is Full\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);

    if (front == -1)
        front = 0;

    queue[++rear] = x;
}

/* Dequeue from front */
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front]);
    front++;
}

/* Peek front element */
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

/* Display queue */
void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

/* Main */
int main() {
    int ch;
    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) enqueue();
        else if (ch == 2) dequeue();
        else if (ch == 3) peek();
        else if (ch == 4) display();
        else break;
    }
    return 0;
}
