#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data; n->left = NULL; n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int val) {
    if (!root) return createNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

struct Node* LCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        if (n1 < root->data && n2 < root->data) root = root->left;
        else if (n1 > root->data && n2 > root->data) root = root->right;
        else return root;
    }
    return NULL;
}

int main() {
    int n, val, n1, n2;
    scanf("%d", &n);
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) { scanf("%d", &val); root = insert(root, val); }
    scanf("%d %d", &n1, &n2);
    struct Node* lca = LCA(root, n1, n2);
    if (lca) printf("LCA: %d\n", lca->data);
    else printf("Not found\n");
    return 0;
}
