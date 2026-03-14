#include <stdio.h>
#include <limits.h>

#define MAX 105
#define INF INT_MAX

int dist[MAX];
int visited[MAX];
int graph[MAX][MAX];
int n;

void dijkstra(int src) {
    for (int i = 0; i < n; i++) { dist[i] = INF; visited[i] = 0; }
    dist[src] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) u = i;

        if (dist[u] == INF) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
}

int main() {
    int m, src;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) graph[i][j] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w; graph[v][u] = w;
    }
    scanf("%d", &src);
    dijkstra(src);
    for (int i = 0; i < n; i++)
        printf("dist[%d] = %d\n", i, dist[i] == INF ? -1 : dist[i]);
    return 0;
}
