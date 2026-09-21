#include <stdio.h>

#define INF 9999

int main() {
    int n, i, j, min, u, v, cost = 0;
    int graph[100][100];
    int visited[100] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("Edges in MST:\n");

    for (i = 0; i < n - 1; i++) {
        min = INF;

        for (j = 0; j < n; j++) {
            if (visited[j]) {
                for (v = 0; v < n; v++) {
                    if (!visited[v] && graph[j][v] < min) {
                        min = graph[j][v];
                        u = j;
                        break;
                    }
                }
            }
        }

        for (j = 0; j < n; j++) {
            if (visited[j]) {
                for (v = 0; v < n; v++) {
                    if (!visited[v] && graph[j][v] < min) {
                        min = graph[j][v];
                        u = j;
                    }
                }
            }
        }

        v = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[u][j] == min) {
                v = j;
                break;
            }
        }

        printf("%d - %d = %d\n", u, v, min);
        cost += min;
        visited[v] = 1;
    }

    printf("Minimum Cost = %d\n", cost);

    return 0;
}