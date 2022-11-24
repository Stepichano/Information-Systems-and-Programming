#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void input(int* array, int len);
void heap_sort(int* array, int len);
void swap(int* array, int idx1, int idx2);
void output(int* array, int len);
void heapify(int* array, int len, int pos);

int main() {
  int* array = NULL;
  int len;
  scanf("%d", &len);
  array = (int*)malloc(sizeof(int) * len);
  if (array) {
    input(array, len);
    heap_sort(array, len);
    output(array, len);
    free(array);
  }
}

void input(int* array, int len) {
  for (int i = 0; i < len; i++) {
    scanf("%d", &array[i]);
  }
}

void heap_sort(int* array, int len) {
  for (int i = 0; i < len / 2; i++) {
    heapify(array, len, i);
  }

  for (int i = len - 1; i >= 0; i--) {
    swap(array, 0, i);
    heapify(array, i, 0);
  }
}

void output(int* array, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", array[i]);
  }
}

void heapify(int* array, int len, int pos) {
  int largest = pos;
  int r = pos * 2 + 2;
  int l = pos * 2 + 1;

  if (l < len && array[l] > array[largest]) largest = l;

  if (r < len && array[r] > array[largest]) largest = r;

  if (largest != pos) {
    swap(array, largest, pos);
    heapify(array, len, largest);
  }
}

void swap(int* array, int idx1, int idx2) {
  int bufer = array[idx1];
  array[idx1] = array[idx2];
  array[idx2] = bufer;
}
