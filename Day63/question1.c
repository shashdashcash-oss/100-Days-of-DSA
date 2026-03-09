#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int vis[MAX];
int n;

void dfs(int node) {
    vis[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < n; i++)
        if (adj[node][i] && !vis[i])
            dfs(i);
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
    dfs(0);
    printf("\n");
    return 0;
}
