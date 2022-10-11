#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define T int

void permut_to_invtab(T* table_invers, T* array, int len);
void shift_elem(T* array, int elem, int invers, int len, int index_j);
void input_array(T* array, int len);
void output(T* array, int len);

int main() {
  T* table_invers = NULL;
  T* array = NULL;
  int len;
  scanf("%d", &len);
  table_invers = (T*)calloc(len, sizeof(T));
  array = (T*)calloc(len, sizeof(T));
  if (table_invers && array) {
    input_array(table_invers, len);
    if (table_invers[len - 1] == 0) {
      permut_to_invtab(table_invers, array, len);
      output(array, len);
    } else {
      printf("NO");
    }
  }
}

void permut_to_invtab(T* table_invers, T* array, int len) {
  for (int i = len, j = 0; i > 0; i--, j++) {
    shift_elem(array, i, table_invers[i - 1], len, j);
  }
}

void shift_elem(T* array, int elem, int invers, int len, int index_j) {
  for (int i = len - 1; i > invers; i--) {
    array[i] = array[i - 1];
  }
  array[invers] = elem;
}

void input_array(T* array, int len) {
  for (int i = 0; i < len; i++) {
    scanf("%d", &array[i]);
  }
}

void output(T* array, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", array[i]);
  }
}