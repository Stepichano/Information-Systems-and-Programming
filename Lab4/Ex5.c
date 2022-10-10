#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE_ARRAY 100
#define SIZE_T 32
#define MASK 2147483648

typedef int bitword;
void bitsetZero(bitword* arr, int num);
void bitsetSet(bitword* arr, int idx, int newval);
void input_arr(bitword* arr, int n);
void output(bitword* arr, int n);
void work_in_arr(bitword* arr, int m);

int main() {
  bitword* arr = NULL;
  arr = (bitword*)calloc(SIZE_ARRAY, sizeof(bitword));
  int len_arr_out = 0;
  int n, m;
  scanf("%d %d", &n, &m);
  if (arr) {
    bitsetZero(arr, SIZE_ARRAY);
    input_arr(arr, n);
    work_in_arr(arr, m);
    output(arr, n);
    free(arr);
  }
  return 0;
}

void bitsetZero(bitword* arr, int num) {
  bitword mask = 0;
  for (int i = 0; i <= num / SIZE_T; i++) {
    arr[i] = mask;
  }
}

void bitsetSet(bitword* arr, int idx, int newval) {
  bitword mask;
  if (newval == 0) {
    mask = ~(MASK >> (idx % SIZE_T));
    arr[idx / SIZE_T] &= mask;
  } else {
    mask = (MASK >> (idx % SIZE_T));
    arr[idx / SIZE_T] |= mask;
  }
}

void output(bitword* arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

void input_arr(bitword* arr, int n) {
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
}

void work_in_arr(bitword* arr, int m) {
  int bit, num_bit;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &bit, &num_bit);
    bitsetSet(arr, num_bit, bit);
  }
}
