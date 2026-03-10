#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int vis[MAX];
int n;

int dfs(int node, int parent) {
    vis[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!vis[i]) {
                if (dfs(i, node)) return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; adj[v][u] = 1;
    }
    for (int i = 0; i < n; i++) vis[i] = 0;
    int hasCycle = 0;
    for (int i = 0; i < n; i++)
        if (!vis[i] && dfs(i, -1)) { hasCycle = 1; break; }
    printf("%s\n", hasCycle ? "Cycle Detected" : "No Cycle");
    return 0;
}
