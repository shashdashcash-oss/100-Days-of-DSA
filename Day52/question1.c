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

struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2) return root;
    struct Node* left = LCA(root->left, n1, n2);
    struct Node* right = LCA(root->right, n1, n2);
    if (left != NULL && right != NULL) return root;
    return left != NULL ? left : right;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node* q[n]; int f = 0, r = 0;
    q[r++] = root; int i = 1;
    while (i < n) {
        struct Node* cur = q[f++];
        if (i < n) { cur->left = createNode(arr[i++]); q[r++] = cur->left; }
        if (i < n) { cur->right = createNode(arr[i++]); q[r++] = cur->right; }
    }
    return root;
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    int n1, n2; scanf("%d %d", &n1, &n2);
    struct Node* lca = LCA(root, n1, n2);
    if (lca) printf("LCA: %d\n", lca->data);
    else printf("Not found\n");
    return 0;
}
