#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define T char

void input_array(T* array, int len);
void output(T* array, int len);
void next_permut(T* table_permut, int len);
void permut(T* table_permut, int pos, int len);
void sort(T* table_permut, int pos, int len);
int next_elem(T* table_permut, int pos, int len);

int main() {
  T* table_permut = NULL;
  int len;
  scanf("%d", &len);
  table_permut = (T*)calloc(len, sizeof(T));
  if (table_permut) {
    input_array(table_permut, len);
    next_permut(table_permut, len);
    output(table_permut, len);
  }
}

void next_permut(T* table_permut, int len) {
  for (int i = len - 1; i > 0; i--) {
    if (table_permut[i - 1] < table_permut[i]) {
      permut(table_permut, i - 1, len);
      break;
    }
  }
}

void input_array(T* array, int len) {
  char c;
  for (int i = 0; i < len;) {
    scanf("%c", &c);
    if (c != ' ' && c != '\n') {
      array[i] = (int)c;
      i++;
    }
  }
}

void permut(T* table_permut, int pos, int len) {
  int next_i = next_elem(table_permut, pos, len);
  int bufer = table_permut[pos];
  table_permut[pos] = table_permut[next_i];
  table_permut[next_i] = bufer;
  sort(table_permut, pos + 1, len);
}

void sort(T* table_permut, int pos, int len) {
  int bufer;
  for (int i = pos; i < len; i++) {
    for (int j = pos; j < len - 1; j++) {
      if (table_permut[j] > table_permut[j + 1]) {
        bufer = table_permut[j + 1];
        table_permut[j + 1] = table_permut[j];
        table_permut[j] = bufer;
      }
    }
  }
}

void output(T* array, int len) {
  for (int i = 0; i < len; i++) {
    printf("%c ", array[i]);
  }
}

int next_elem(T* table_permut, int pos, int len) {
  sort(table_permut, pos + 1, len);
  for (int i = pos; i < len; i++) {
    if (table_permut[i] > table_permut[pos]) {
      return i;
    }
  }
  return pos;
}
