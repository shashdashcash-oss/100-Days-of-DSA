#include <stdio.h>
#include <stdlib.h>

typedef struct { int start; int end; } Meeting;

int compare(const void* a, const void* b) {
    return ((Meeting*)a)->start - ((Meeting*)b)->start;
}

void swap(int* heap, int i, int j) { int t = heap[i]; heap[i] = heap[j]; heap[j] = t; }

void heapifyUp(int* heap, int idx) {
    while (idx > 0 && heap[(idx-1)/2] > heap[idx]) { swap(heap, idx, (idx-1)/2); idx = (idx-1)/2; }
}

void heapifyDown(int* heap, int size, int idx) {
    int s = idx, l = 2*idx+1, r = 2*idx+2;
    if (l < size && heap[l] < heap[s]) s = l;
    if (r < size && heap[r] < heap[s]) s = r;
    if (s != idx) { swap(heap, idx, s); heapifyDown(heap, size, s); }
}

int main() {
    int n; scanf("%d", &n);
    Meeting meetings[n];
    for (int i = 0; i < n; i++) scanf("%d %d", &meetings[i].start, &meetings[i].end);
    qsort(meetings, n, sizeof(Meeting), compare);

    int* heap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;
    heap[heapSize++] = meetings[0].end;

    for (int i = 1; i < n; i++) {
        if (heap[0] <= meetings[i].start) { heap[0] = meetings[i].end; heapifyDown(heap, heapSize, 0); }
        else { heap[heapSize] = meetings[i].end; heapifyUp(heap, heapSize); heapSize++; }
    }

    printf("Minimum rooms required: %d\n", heapSize);
    free(heap);
    return 0;
}
