#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void input_array(int* arr, int n);
int search_index(int* arr, int len, int elem);

int main() {
  int* arr = NULL;
  int n, elem;
  scanf("%d %d", &n, &elem);
  arr = (int*)malloc(sizeof(int) * n);
  input_array(arr, n);
  if (arr) {
    printf("%d", search_index(arr, n, elem));
  }
}

void input_array(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
}

int search_index(int* arr, int len, int elem) {
  int left = 0;
  int index = (len / 2) + (len % 2);
  int right = len;
  for (; left <= right;) {
    if (arr[index] == elem) {
      return index;
    }
    if (arr[index] > elem) {
      right = index - 1;
      index = (right / 2) + (right % 2);
    } else {
      left = index + 1;
      index = left + ((right - left) / 2 + (right - left) % 2);
    }
  }
  return -1;
}