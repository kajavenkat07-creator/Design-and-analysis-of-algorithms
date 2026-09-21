#include <stdio.h>

struct Edge {
    int u, v, w;
};

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;
    return find(parent[x]);
}

void sort(struct Edge e[], int m) {
    int i, j;
    struct Edge temp;

    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < m - i - 1; j++) {
            if (e[j].w > e[j + 1].w) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, m, i, count = 0, cost = 0;
    struct Edge e[100];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v w):\n");
    for (i = 0; i < m; i++)
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);

    for (i = 0; i < n; i++)
        parent[i] = i;

    sort(e, m);

    printf("Edges in MST:\n");

    for (i = 0; i < m && count < n - 1; i++) {
        int a = find(e[i].u);
        int b = find(e[i].v);

        if (a != b) {
            printf("%d - %d = %d\n", e[i].u, e[i].v, e[i].w);
            cost += e[i].w;
            parent[a] = b;
            count++;
        }
    }

    printf("Minimum Cost = %d\n", cost);

    return 0;
}