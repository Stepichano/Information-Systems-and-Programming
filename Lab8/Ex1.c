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
  for (int d = len / 2; d > 0; d /= 2) {
    for (int i = d; i < len; i++) {
      for (int j = i - d; (j >= 0) && (array[j] > array[j + d]); j -= d) {
        int bufer = array[j];
        array[j] = array[j + d];
        array[j + d] = bufer;
      }
    }
  }
}

void output(int* array, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", array[i]);
  }
}
