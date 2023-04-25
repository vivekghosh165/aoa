//13_Prims_Algorithm.c
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
    for (i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (i = 0; i < n - 1; i++) {
        min = INT_MAX;
        for (j = 0; j < n; j++) {
            if (!visited[j] && key[j] < min) {
                min = key[j];
                u = j;
            }
        }
        visited[u] = 1;
        for (v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
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
