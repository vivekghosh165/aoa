//05_FloydWarshall.c
#include <stdio.h>
#define MAX_VERTICES 100
#define INF 100
void floydWarshall(int graph[][MAX_VERTICES], int n)
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}
int main(void)
{
    int n, i, j;
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the edges: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
	{
            printf("[%d][%d]: ", i, j);
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1)
                graph[i][j] = INF;
        }
    }
    printf("The original graph is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    floydWarshall(graph, n);
    printf("The shortest path matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}
