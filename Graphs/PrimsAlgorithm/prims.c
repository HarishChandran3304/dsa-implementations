#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

int n; // Number of vertices in the graph

// Function to find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], int mstSet[])
{
    int min = INT_MAX;
    int min_index;
    for (int v = 0; v < n; v++)
    {
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[n][n])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[n][n])
{
    int parent[n]; // Array to store constructed MST
    int key[n]; // Key values used to pick minimum weight edge in cut
    int mstSet[n]; // To represent set of vertices not yet included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Always include first 1st vertex in MST
    key[0] = 0; // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have n vertices
    for (int count = 0; count < n - 1; count++)
    {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex. Consider only those vertices which are not yet included in MST
        for (int v = 0; v < n; v++)
        {
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph);

    return 0;
}