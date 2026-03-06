#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left, *right; };

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val; n->left = NULL; n->right = NULL; return n;
}

int findIndex(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) if (inorder[i] == val) return i;
    return -1;
}

struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;
    int rootVal = postorder[(*postIndex)--];
    struct Node* root = createNode(rootVal);
    if (inStart == inEnd) return root;
    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);
    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);
    return root;
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data); preorder(root->left); preorder(root->right);
}

int main() {
    int n; scanf("%d", &n);
    int in[n], post[n];
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    int idx = n - 1;
    struct Node* root = buildTree(in, post, 0, n - 1, &idx);
    preorder(root); printf("\n");
    return 0;
}
