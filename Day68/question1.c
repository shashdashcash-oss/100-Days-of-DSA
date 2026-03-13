#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int n;

void topoSort() {
    int front = 0, rear = 0;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0) queue[rear++] = i;

    printf("Topological Sort (Kahn's): ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0) queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) indegree[i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        adj[u][v] = 1; indegree[v]++;
    }
    topoSort();
    return 0;
}
