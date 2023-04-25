//12_Kruskal_Algorithm.c
#include <stdio.h>
#include <stdlib.h>
#define MAX_EDGES 100
#define MAX_VERTICES 26
struct Edge {
    int u, v, weight;
};
int parent[MAX_VERTICES];
int find(int u) {
    while (parent[u] != u) {
        u = parent[u];
    }
    return u;
}
void union_set(int u, int v) {
    parent[v] = u;
}
void kruskal(struct Edge edges[], int n, int e) {
    struct Edge result[MAX_EDGES];
    int i, j, k, u, v, count = 0;
    for (i = 0; i < e - 1; i++) {
        for (j = i + 1; j < e; j++) {
            if (edges[i].weight > edges[j].weight) {
                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (i = 0; i < e && count < n - 1; i++) {
        u = find(edges[i].u);
        v = find(edges[i].v);
        if (u != v) {
            result[count] = edges[i];
            count++;
            union_set(u, v);
        }
    }
    printf("Edges in the MST:\n");
    for (i = 0; i < count; i++) {
        printf("%c - %c (%d)\n", result[i].u + 'A', result[i].v + 'A', result[i].weight);
    }
}
int main() {
    int n, e, i;
    struct Edge edges[MAX_EDGES];
    printf("Enter the number of vertices (max 26): ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    printf("Enter the edges and weights:\n");
    for (i = 0; i < e; i++) {
        char u, v;
        int weight;
        scanf(" %c %c %d", &u, &v, &weight);
        edges[i].u = u - 'A';
        edges[i].v = v - 'A';
        edges[i].weight = weight;
    }
    kruskal(edges, n, e);
    return 0;
}
