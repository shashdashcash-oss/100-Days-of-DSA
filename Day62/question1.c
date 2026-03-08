#include <stdio.h>
#include <stdlib.h>

struct Node { int val; struct Node* next; };

struct Node* addEdge(struct Node* head, int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = v; n->next = head; return n;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    struct Node* adj[n + 1];
    for (int i = 0; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u] = addEdge(adj[u], v);
        adj[v] = addEdge(adj[v], u);
    }

    printf("Adjacency List:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while (temp) { printf("%d ", temp->val); temp = temp->next; }
        printf("\n");
    }
    return 0;
}
