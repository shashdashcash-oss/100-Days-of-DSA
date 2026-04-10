#include <stdio.h>
#include <stdlib.h>

struct Node { int vertex; struct Node* next; };

struct Node* addNode(struct Node* head, int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->vertex = v; n->next = NULL;
    if (!head) return n;
    struct Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    return head;
}

void dfs(int node, struct Node* adj[], int visited[]) {
    visited[node] = 1;
    struct Node* t = adj[node];
    while (t) { if (!visited[t->vertex]) dfs(t->vertex, adj, visited); t = t->next; }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    struct Node* adj[105] = {NULL};
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        adj[u] = addNode(adj[u], v);
        adj[v] = addNode(adj[v], u);
    }
    int visited[105] = {0};
    dfs(1, adj, visited);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) { printf("NOT CONNECTED\n"); return 0; }
    }
    printf("CONNECTED\n");
    return 0;
}
