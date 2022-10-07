#include <stdio.h>
#include <stdlib.h>
#define T int

void Eratosfen(T* array, int n, int start_pos);
T* alloc_memory(int n);
void input_array(T* array, int n);
void output_array(T* array, int n);

int main() {
  int n;
  T* array = NULL;
  scanf_s("%d", &n);
  if (n >= 2 && n <= 1000000) {
    array = alloc_memory(n);
    if (array != NULL) {
      input_array(array, n);
      Eratosfen(array, n, 3);
      output_array(array, n);
      free(array);
    }
  }
  return 0;
}

void Eratosfen(T* array, int n, int start_pos) {
  int p = start_pos + 2 * start_pos;
  for (int i = p; i <= n; i += 2 * start_pos) {
    array[i] = 0;
  }
  p = start_pos + 2;
  if (p * p <= n) {
    for (int i = p; i <= n; i += 2) {
      if (array[i]) {
        p = i;
        break;
      }
    }
    Eratosfen(array, n, p);
  }
}

T* alloc_memory(int n) {
  T* new_array = NULL;
  new_array = (T*)malloc(sizeof(T) * (n + 1));
  return new_array;
}

void input_array(T* array, int n) {
  for (int i = 3; i <= n; i += 2) {
    array[i] = i;
  }
}

void output_array(T* array, int n) {
  printf("%d ", 2);
  if (n > 2) {
    for (int i = 3; i <= n; i += 2) {
      if (array[i] != 0) {
        printf("%d ", array[i]);
      }
    }
  }
}
