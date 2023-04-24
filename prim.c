#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 26

int graph[MAX_VERTICES][MAX_VERTICES];
int parent[MAX_VERTICES];
int key[MAX_VERTICES];
int visited[MAX_VERTICES];

void prim(int n) {
    int i, j, u, v, min;
    // initialize key array and visited array
    for (i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }
    // set the key of the starting vertex to 0
    key[0] = 0;
    parent[0] = -1;
    // iterate over all vertices
    for (i = 0; i < n - 1; i++) {
        // find the vertex with the minimum key value
        min = INT_MAX;
        for (j = 0; j < n; j++) {
            if (!visited[j] && key[j] < min) {
                min = key[j];
                u = j;
            }
        }
        // mark the vertex as visited
        visited[u] = 1;
        // update the key values of the adjacent vertices
        for (v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    // print the edges in the minimum spanning tree
    printf("Edges in the MST:\n");
    for (i = 1; i < n; i++) {
        printf("%c - %c (%d)\n", parent[i] + 'A', i + 'A', graph[i][parent[i]]);
    }
}

int main() {
    int n, i, j;
    printf("Enter the number of vertices (max 26): ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    prim(n);
    return 0;
}
