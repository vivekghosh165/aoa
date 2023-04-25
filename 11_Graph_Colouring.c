//11_Graph_Colouring.c
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int graph[MAX][MAX];
int color[MAX];
int n;
int is_safe(int vertex, int c)
{
    int i;
    for (i = 0; i < n; i++) {
        if (graph[vertex][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}
int graph_coloring(int vertex)
{
    int c;
    if (vertex == n) {
        return 1;
    }
    for (c = 1; c <= n; c++) {
        if (is_safe(vertex, c)) {
            color[vertex] = c;
            if (graph_coloring(vertex + 1)) {
                return 1;
            }
            color[vertex] = 0;
        }
    }
    return 0;
}
int main()
{
    int i, j;
    printf("Enter the number of vertices (max %d): ", MAX);
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        color[i] = 0;
    }
    if (graph_coloring(0)) {
        printf("The graph can be colored with %d colors:\n", n);
        for (i = 0; i < n; i++) {
            printf("Vertex %d: Color %d\n", i, color[i]);
        }
    } else {
        printf("The graph cannot be colored with %d colors.\n", n);
    }
    return 0;
}
