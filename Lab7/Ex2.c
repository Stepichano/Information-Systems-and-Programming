#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void input(int* array, int len);
void ins_sort(int* array, int len);
void swap(int* array, int idx1, int idx2);
void output(int* array, int len);

int main() {
  int* array = NULL;
  int len;
  scanf("%d", &len);
  array = (int*)malloc(sizeof(int) * len);
  if (array) {
    input(array, len);
    ins_sort(array, len);
    output(array, len);
    free(array);
  }
}

void input(int* array, int len) {
  for (int i = 0; i < len; i++) {
    scanf("%d", &array[i]);
  }
}

void ins_sort(int* array, int len) {
  for (int i = 0; i < len - 1; i++) {
    int min_i = i;
    for (int j = i; j < len; j++) {
      if (array[j] < array[min_i]) min_i = j;
    }
    if (min_i != i) swap(array, i, min_i);
  }
}

void swap(int* array, int idx1, int idx2) {
  int bufer = array[idx1];
  array[idx1] = array[idx2];
  array[idx2] = bufer;
}

void output(int* array, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", array[i]);
  }
}