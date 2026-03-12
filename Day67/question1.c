#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int vis[MAX];
int stack[MAX], top = -1;
int n;

void dfs(int node) {
    vis[node] = 1;
    for (int i = 0; i < n; i++)
        if (adj[node][i] && !vis[i]) dfs(i);
    stack[++top] = node;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    for (int i = 0; i < n; i++) vis[i] = 0;
    for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);
    printf("Topological Sort: ");
    while (top >= 0) printf("%d ", stack[top--]);
    printf("\n");
    return 0;
}
