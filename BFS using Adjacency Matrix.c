#include <stdio.h>

int adj[10][10], visited[10];
int queue[10], front = 0, rear = -1;
int n;

/* Enqueue operation */
void enqueue(int x) {
    queue[++rear] = x;
}

/* Dequeue operation */
int dequeue() {
    return queue[front++];
}

/* BFS traversal */
void BFS(int start) {
    int v, i;

    visited[start] = 1;
    enqueue(start);

    while (front <= rear) {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS traversal: ");
    BFS(start);

    return 0;
}
