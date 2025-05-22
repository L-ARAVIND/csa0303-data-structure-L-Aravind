#include <stdio.h>
#define INF 9999
#define MAX 100

int main() {
    int n, cost[MAX][MAX], visited[MAX] = {0}, edge = 0;
    int min, u = 0, v = 0, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = INF;
        }

    visited[0] = 1;

    printf("Edges in MST:\n");
    while (edge < n - 1) {
        min = INF;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        visited[v] = 1;
        printf("%d - %d : %d\n", u, v, cost[u][v]);
        total += cost[u][v];
        edge++;
    }

    printf("Total cost of MST: %d\n", total);
    return 0;
}

