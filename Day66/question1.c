#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int vis[MAX], pathVis[MAX];
int n;

int dfsCheck(int node) {
    vis[node] = 1; pathVis[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!vis[i]) { if (dfsCheck(i)) return 1; }
            else if (pathVis[i]) return 1;
        }
    }
    pathVis[node] = 0;
    return 0;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    for (int i = 0; i < n; i++) vis[i] = pathVis[i] = 0;
    int hasCycle = 0;
    for (int i = 0; i < n; i++)
        if (!vis[i] && dfsCheck(i)) { hasCycle = 1; break; }
    printf("%s\n", hasCycle ? "Cycle Detected" : "No Cycle");
    return 0;
}
