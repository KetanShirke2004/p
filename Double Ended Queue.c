#include <stdio.h>
#define MAX 5

int dq[MAX];
int front = -1, rear = -1;

/* Enqueue at rear */
void enqueueRear() {
    int x;
    if (rear == MAX - 1) {
        printf("Queue is Full\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);

    if (front == -1)
        front = 0;

    dq[++rear] = x;
}

/* Enqueue at front */
void enqueueFront() {
    int x;
    if (front <= 0) {
        printf("Cannot insert at front\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);

    dq[--front] = x;
}

/* Dequeue from front */
void dequeueFront() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Deleted: %d\n", dq[front]);
    front++;
}

/* Dequeue from rear */
void dequeueRear() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Deleted: %d\n", dq[rear]);
    rear--;
}

/* Peek front */
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Front element: %d\n", dq[front]);
}

/* Display */
void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    for (i = front; i <= rear; i++)
        printf("%d ", dq[i]);
    printf("\n");
}

/* Main */
int main() {
    int ch;
    while (1) {
        printf("\n1.Enqueue Rear\n2.Enqueue Front\n3.Dequeue Front\n4.Dequeue Rear\n5.Peek\n6.Display\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) enqueueRear();
        else if (ch == 2) enqueueFront();
        else if (ch == 3) dequeueFront();
        else if (ch == 4) dequeueRear();
        else if (ch == 5) peek();
        else if (ch == 6) display();
        else break;
    }
    return 0;
}
