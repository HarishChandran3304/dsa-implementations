#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int stack[100];
int top = -1;

bool isEmpty() {
    return top == -1;
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

void printStack() {
    for (int i = 0; i <= top; i++) printf("%d ", stack[i]);
    printf("\n");
}


void DFS(int** graph, int start, int v, int e) {
    int visited[v];
    for (int i = 0; i < v; i++) visited[i] = 0;

    push(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int node = pop();
        printf("%d ", node);

        for (int i = 0; i < v; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                push(i);
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
        int s, d;
        printf("Enter the vertices of edge %d: ", i + 1);
        scanf("%d %d", &s, &d);
        graph[s][d] = 1;
        graph[s][d] = 1;
    }


    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    DFS(graph, start, v, e);
    printf("\n");

    return 0;
}