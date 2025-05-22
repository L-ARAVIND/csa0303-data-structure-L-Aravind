#include <stdio.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], n;

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    for (int i = 0; i < n; i++) visited[i] = 0;

    printf("DFS traversal: ");
    DFS(start);

    return 0;
}

