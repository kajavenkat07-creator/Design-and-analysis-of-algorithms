
#include <stdio.h>

#define INF 99999

void printSolution(int dist[10][10], int v) {
    int i, j;

    printf("Shortest distance between every pair of vertices:\n");

    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int v, i, j, k;
    int dist[10][10];
    int value;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    printf("Enter the cost adjacency matrix (-1 if there is no edge):\n");

    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            scanf("%d", &value);

            if (i == j)
                dist[i][j] = 0;
            else if (value == -1)
                dist[i][j] = INF;
            else
                dist[i][j] = value;
        }
    }

    for (k = 0; k < v; k++) {
        for (i = 0; i < v; i++) {
            for (j = 0; j < v; j++) {
                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist, v);

    return 0;
}
