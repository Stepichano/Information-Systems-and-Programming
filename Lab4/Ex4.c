#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE_ARRAY 1000000
#define SIZE_T 32
#define SIZE_DOFIGA 100000  // задолбало просто

typedef unsigned int bitword;
void switch_mod(bitword* arr, int t, int* len_arr_out, int* array_out);
void bitsetZero(bitword* arr, int num);
int bitsetGet(const bitword* arr, int idx);
int bitsetAny(const bitword* arr, int left, int right);
void bitsetSet(bitword* arr, int idx, int newval);
void output(int len_arr_out, int array_out[SIZE_DOFIGA]);
void set_bit(bitword* digit, int bit);
int get_bit(bitword numb, int bit);
void output_bit(bitword digit);
int shearch_bit(bitword digit, int left, int right);

int main() {
  int* array_out = NULL;
  bitword* arr = NULL;
  array_out = (int*)calloc(SIZE_DOFIGA, sizeof(int));
  arr = (bitword*)calloc(SIZE_ARRAY, sizeof(bitword));
  int len_arr_out = 0;
  int t, n;
  scanf("%d", &n);
  if (array_out && arr) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &t);
      switch_mod(arr, t, &len_arr_out, array_out);
    }
    output(len_arr_out, array_out);
    free(arr);
    free(array_out);
  }
  return 0;
}

void bitsetZero(bitword* arr, int num) {
  bitword mask = 0;
  for (int i = 0; i <= num / SIZE_T; i++) {
    arr[i] = mask;
  }
}

int bitsetGet(const bitword* arr, int idx) {
  unsigned int mask = (1 << idx);
  return !!(arr[idx / SIZE_T] & mask);
}

void bitsetSet(bitword* arr, int idx, int newval) {
  bitword mask;
  if (newval == 0) {
    mask = ~(1 << idx);
    arr[idx / SIZE_T] &= mask;
  } else {
    mask = (1 << idx);
    arr[idx / SIZE_T] |= mask;
  }
}

int bitsetAny(const bitword* arr, int left, int right) {
  bitword left_mask, right_mask;
  int left_int, right_int;
  int left_shift = left % SIZE_T;
  int right_shift = (SIZE_T - ((right % SIZE_T)));
  //
  left_int = (left / SIZE_T) + 1;
  right_int = right / SIZE_T;
  //
  left_mask = arr[left_int - 1];
  right_mask = arr[right_int];
  if (left_mask != right_mask) {
    left_mask = left_mask >> left_shift;
    right_mask = right_mask << (right_shift - 1);
    set_bit(&right_mask, SIZE_T - 1);
    if (left_mask != 0 || right_mask != 0) {
      return 1;
    }
  } else {
    if (shearch_bit(left_mask, left % SIZE_T, right % SIZE_T)) {
      return 1;
    }
  }
  for (int i = left_int; i < right_int; i++) {
    if (arr[i] != 0) {
      return 1;
    }
  }
  return 0;
}

void switch_mod(bitword* arr, int t, int* len_arr_out, int* array_out) {
  if (t == 0) {
    int num;
    scanf("%d", &num);
    bitsetZero(arr, num);
  } else if (t == 1) {
    int idx;
    scanf("%d", &idx);
    array_out[*len_arr_out] = bitsetGet(arr, idx);
    *len_arr_out += 1;
  } else if (t == 2) {
    int idx, newval;
    scanf("%d%d", &idx, &newval);
    bitsetSet(arr, idx, newval);
  } else {
    int left, right;
    scanf("%d%d", &left, &right);
    if (bitsetAny(arr, left, right)) {
      array_out[*len_arr_out] = 2;
      *len_arr_out += 1;
    } else {
      array_out[*len_arr_out] = 3;
      *len_arr_out += 1;
    }
  }
}

void output(int len_arr_out, int* array_out) {
  for (int i = 0; i < len_arr_out; i++) {
    if (array_out[i] == 2) {
      printf("some\n");
    } else if (array_out[i] == 3) {
      printf("none\n");
    } else {
      printf("%d\n", array_out[i]);
    }
  }
}

void set_bit(bitword* digit, int bit) {
  bitword mask = ~(1 << bit);
  *digit &= mask;
}

int get_bit(bitword numb, int bit) {
  long unsigned mask = 1 << bit;
  return !!(mask & numb);
}

int shearch_bit(bitword digit, int left, int right) {
  for (int i = left; i < right; i++) {
    if (get_bit(digit, i)) {
      return 1;
    }
  }
  return 0;
}
void output_bit(bitword digit) {
  for (int i = 0; i < 32; i++) {
    printf("%d", get_bit(digit, i));
  }
  printf("\n");
}
