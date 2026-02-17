#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    int currSize;
    Node* front;
    Node* rear;
} myQueue;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

myQueue* createQueue() {
    myQueue* q = (myQueue*)malloc(sizeof(myQueue));
    q->front = NULL;
    q->rear = NULL;
    q->currSize = 0;
    return q;
}

bool isEmpty(myQueue* q) { return q->front == NULL; }

void enqueue(myQueue* q, int data) {
    Node* node = newNode(data);
    if (isEmpty(q)) { q->front = q->rear = node; }
    else { q->rear->next = node; q->rear = node; }
    q->currSize++;
}

int dequeue(myQueue* q) {
    if (isEmpty(q)) return -1;
    Node* temp = q->front;
    int removedData = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    q->currSize--;
    return removedData;
}

int main() {
    myQueue* q = createQueue();
    enqueue(q, 10); enqueue(q, 20); enqueue(q, 30);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    return 0;
}
