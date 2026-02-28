#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left, *right; };
struct Pair { struct Node* node; int hd; };

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data; n->left = NULL; n->right = NULL; return n;
}

void verticalOrder(struct Node* root) {
    if (root == NULL) return;
    struct Pair q[1000];
    int front = 0, rear = 0;
    int hdArr[1000], valArr[1000], count = 0;
    q[rear].node = root; q[rear].hd = 0; rear++;
    while (front < rear) {
        struct Pair cur = q[front++];
        struct Node* temp = cur.node; int hd = cur.hd;
        hdArr[count] = hd; valArr[count] = temp->data; count++;
        if (temp->left) { q[rear].node = temp->left; q[rear].hd = hd - 1; rear++; }
        if (temp->right) { q[rear].node = temp->right; q[rear].hd = hd + 1; rear++; }
    }
    for (int i = -100; i <= 100; i++) {
        int printed = 0;
        for (int j = 0; j < count; j++) {
            if (hdArr[j] == i) { printf("%d ", valArr[j]); printed = 1; }
        }
        if (printed) printf("\n");
    }
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
    verticalOrder(root);
    return 0;
}
