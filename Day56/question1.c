#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left, *right; };

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data; n->left = NULL; n->right = NULL; return n;
}

int isMirror(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL) return 1;
    if (t1 == NULL || t2 == NULL) return 0;
    if (t1->data != t2->data) return 0;
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

int isSymmetric(struct Node* root) {
    if (root == NULL) return 1;
    return isMirror(root->left, root->right);
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node* q[n]; int f = 0, r = 0; q[r++] = root; int i = 1;
    while (i < n) {
        struct Node* cur = q[f++];
        if (i < n) { cur->left = createNode(arr[i++]); q[r++] = cur->left; }
        if (i < n) { cur->right = createNode(arr[i++]); q[r++] = cur->right; }
    }
    return root;
}

int main() {
    int n; scanf("%d", &n);
    int arr[n]; for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    printf("%s\n", isSymmetric(root) ? "Symmetric" : "Not Symmetric");
    return 0;
}
