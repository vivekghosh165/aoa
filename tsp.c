#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

int tsp(int current, int count, int cost, int min_cost)
{
    int i;

    if (count == n && graph[current][0] != 0) {
        cost += graph[current][0];
        if (cost < min_cost) {
            min_cost = cost;
        }
        return min_cost;
    }

    for (i = 0; i < n; i++) {
        if (graph[current][i] != 0 && !visited[i]) {
            visited[i] = 1;
            min_cost = tsp(i, count + 1, cost + graph[current][i], min_cost);
            visited[i] = 0;
        }
    }

    return min_cost;
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
        visited[i] = 0;
    }
    visited[0] = 1;

    int min_cost = tsp(0, 1, 0, INT_MAX);

    printf("Minimum cost: %d\n", min_cost);

    return 0;
}
