#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left, *right; };

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data; n->left = NULL; n->right = NULL; return n;
}

void mirror(struct Node* root) {
    if (root == NULL) return;
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left); printf("%d ", root->data); inorder(root->right);
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
    mirror(root);
    inorder(root); printf("\n");
    return 0;
}
