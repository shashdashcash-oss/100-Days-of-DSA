#include <stdio.h>
#define INF 100000000

int main() {
    int V, E, S;
    scanf("%d %d %d", &V, &E, &S);

    int u[E], v[E], w[E];
    for (int i = 0; i < E; i++) scanf("%d %d %d", &u[i], &v[i], &w[i]);

    int dist[V];
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[S] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]])
                dist[v[j]] = dist[u[j]] + w[j];
        }
    }

    // Check for negative cycle
    int negCycle = 0;
    for (int j = 0; j < E; j++) {
        if (dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
            negCycle = 1; break;
        }
    }

    if (negCycle) { printf("Negative cycle detected\n"); return 0; }
    for (int i = 0; i < V; i++)
        printf("dist[%d] = %d\n", i, dist[i] == INF ? -1 : dist[i]);
    return 0;
}
