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
    if (root == NULL) return createNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

int search(struct Node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

int main() {
    int n, val, key;
    scanf("%d", &n);
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    scanf("%d", &key);
    printf("%s\n", search(root, key) ? "Found" : "Not Found");
    return 0;
}
