#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX];
int parent[MAX];

int find(int i) {
    while (parent[i]) i = parent[i];
    return i;
}
int unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    if (a != b) {
        parent[b] = a;
        return 1;
    }
    return 0;
}

int main() {
    int n, e, i, total = 0, count = 0;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    printf("Enter %d edges (u v weight):\n", e);
    for (i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    for (i = 0; i < e - 1; i++)
        for (int j = i + 1; j < e; j++)
            if (edges[i].w > edges[j].w) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }

    printf("Edges in MST:\n");
    for (i = 0; i < e && count < n - 1; i++) {
        if (unionSets(edges[i].u, edges[i].v)) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w;
            count++;
        }
    }

    printf("Total cost of MST: %d\n", total);
    return 0;
}

