#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE_ARRAY 1000
#define T int

int search_inversion(T *array, int len, T elem);
int search_position_elem_inversion(T *array, int len, T elem);
void creat_table_inversion(T *array, T *tabel_invers, int len);
void input_array(T *array, int len);
void output_array(T *array, int len);

int main() {
  T *array = NULL;
  T *table_invers = NULL;
  int len;
  scanf("%d", &len);
  array = (T *)calloc(len, sizeof(T));
  table_invers = (T *)calloc(len, sizeof(T));
  if (array && table_invers) {
    input_array(array, len);
    creat_table_inversion(array, table_invers, len);
    output_array(table_invers, len);
    free(array);
    free(table_invers);
  }
  return 0;
}

void input_array(T *array, int len) {
  for (int i = 0; i < len; i++) {
    scanf("%d", &array[i]);
  }
}

void output_array(T *array, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", array[i]);
  }
}

int search_inversion(T *array, int len, T elem) {
  // elem это элемент для которого мы ищем инверсию
  // pos_elem это позиция элемента для которого мы будем искать инверсию
  int count = 0;
  int pos_elem = search_position_elem_inversion(array, len, elem);

  for (int i = 0; i < pos_elem; i++) {
    if (array[i] > elem) {
      count++;
    }
  }

  return count;
}

void creat_table_inversion(T *array, T *tabel_invers, int len) {
  for (int i = 0, elem = 1; i < len; i++, elem++) {
    tabel_invers[i] = search_inversion(array, len, elem);
  }
}

int search_position_elem_inversion(T *array, int len, T elem) {
  int result = 0;

  for (int i = 0; i < len; i++) {
    if (array[i] == elem) {
      result = i;
      break;
    }
  }

  return result;
}
