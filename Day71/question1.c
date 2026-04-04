#include <stdio.h>

#define SIZE 7

int table[SIZE];

void init() { for (int i = 0; i < SIZE; i++) table[i] = -1; }

void insert(int key) {
    int h = key % SIZE;
    for (int i = 0; i < SIZE; i++) {
        int index = (h + i * i) % SIZE;
        if (table[index] == -1) { table[index] = key; return; }
    }
    printf("Table full\n");
}

int search(int key) {
    int h = key % SIZE;
    for (int i = 0; i < SIZE; i++) {
        int index = (h + i * i) % SIZE;
        if (table[index] == key) return 1;
        if (table[index] == -1) return 0;
    }
    return 0;
}

int main() {
    init();
    int keys[] = {10, 22, 31, 4, 15, 28, 17};
    for (int i = 0; i < 7; i++) insert(keys[i]);
    printf("Search 15: %s\n", search(15) ? "Found" : "Not Found");
    printf("Search 99: %s\n", search(99) ? "Found" : "Not Found");
    return 0;
}
