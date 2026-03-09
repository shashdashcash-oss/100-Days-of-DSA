#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int vis[MAX];
int queue[MAX];
int n;

void bfs(int start) {
    int front = 0, rear = 0;
    vis[start] = 1;
    queue[rear++] = start;
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !vis[i]) {
                vis[i] = 1;
                queue[rear++] = i;
            }
        }
    }
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
    bfs(0);
    printf("\n");
    return 0;
}
