#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int q[100];
int front = 0;
int rear = 0;

bool isEmpty() {
    return front == rear;
}

void enqueue(int x) {
    q[rear++] = x;
}

int dequeue() {
    return q[front++];
}

void printQueue(int front, int rear) {
    for (int i = front; i < rear; i++) printf("%d ", q[i]);
    printf("\n");
}


void BFS(int** graph, int start, int v, int e) {
    int visited[v];
    for (int i = 0; i < v; i++) visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < v; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}


int main() {
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    int** graph = (int**)malloc(v * sizeof(int*));
    for (int i = 0; i < v; i++) {
        graph[i] = (int*)calloc(v, sizeof(int));
    }

    int e;
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    for (int i = 0; i < e; i++) {
        int a, b;
        printf("Enter the vertices of edge %d: ", i + 1);
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }


    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    BFS(graph, start, v, e);

    return 0;
}
