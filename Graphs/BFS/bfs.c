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
    for (int i=front; i<rear; i++) printf("%d ", q[i]);
    printf("\n");
}

void printGraph(int graph[100][100], int v) {
    for (int i=0; i<v; i++) {
        for (int j=0; j<v; j++) printf("%d ", graph[i][j]);
        printf("\n");
    }
}


void BFS(int graph[100][100], int start, int v, int e) {
    int visited[v];
    for (int i=0; i<v; i++) visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        printQueue(front, rear);
        int node = dequeue();
        printf("%d ", node);

        for (int i=0; i<v; i++) {
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
    int graph[v][v];
    for (int i=0; i<v; i++) {
        for (int j=0; j<v; j++) {
            graph[i][j] = 0;
        }
    }

    printGraph(graph, v);

    int e;
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    for (int i=0; i<e; i++) {
        int a, b;
        printf("Enter the vertices of edge %d: ", i+1); 
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    printGraph(graph, v);

    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    BFS(graph, start, v, e);

    return 0;
}