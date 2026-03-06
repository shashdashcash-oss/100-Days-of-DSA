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

struct Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;
    int rootVal = preorder[(*preIndex)++];
    struct Node* root = createNode(rootVal);
    if (inStart == inEnd) return root;
    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);
    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);
    return root;
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left); postorder(root->right); printf("%d ", root->data);
}

int main() {
    int n; scanf("%d", &n);
    int pre[n], in[n];
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    int idx = 0;
    struct Node* root = buildTree(pre, in, 0, n - 1, &idx);
    postorder(root); printf("\n");
    return 0;
}
