#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* i1 = *(int**)a; int* i2 = *(int**)b;
    return i1[0] - i2[0];
}

int main() {
    int n; scanf("%d", &n);
    int intervals[n][2];
    int* ptrs[n];
    for (int i = 0; i < n; i++) { scanf("%d %d", &intervals[i][0], &intervals[i][1]); ptrs[i] = intervals[i]; }
    qsort(ptrs, n, sizeof(int*), compare);

    int result[n][2]; int idx = 0;
    result[idx][0] = ptrs[0][0]; result[idx][1] = ptrs[0][1];

    for (int i = 1; i < n; i++) {
        if (ptrs[i][0] <= result[idx][1]) { if (ptrs[i][1] > result[idx][1]) result[idx][1] = ptrs[i][1]; }
        else { idx++; result[idx][0] = ptrs[i][0]; result[idx][1] = ptrs[i][1]; }
    }

    for (int i = 0; i <= idx; i++) printf("[%d,%d] ", result[i][0], result[i][1]);
    printf("\n");
    return 0;
}
