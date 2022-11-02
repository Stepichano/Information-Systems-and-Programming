#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void input(int* array, int len);
void shell_sort(int* array, int len);
void swap(int* array, int idx1, int idx2);
void output(int* array, int len);

int main() {
  int* array = NULL;
  int len;
  scanf("%d", &len);
  array = (int*)malloc(sizeof(int) * len);
  if (array) {
    input(array, len);
    shell_sort(array, len);
    output(array, len);
    free(array);
  }
}

void input(int* array, int len) {
  for (int i = 0; i < len; i++) {
    scanf("%d", &array[i]);
  }
}

void shell_sort(int* array, int len) {
  for (int s = len / 2; s > 0; s /= 2) {
    for (int i = s; i < len; ++i) {
      for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
        int temp = array[j];
        array[j] = array[j + s];
        array[j + s] = temp;
      }
    }
  }
  int left = 0,
      right = len - 1;  // левая и правая границы сортируемой области массива
  int flag = 1;         // флаг наличия перемещений
  // Выполнение цикла пока левая граница не сомкнётся с правой
  // и пока в массиве имеются перемещения
  while ((left < right) && flag > 0) {
    flag = 0;
    for (int i = left; i < right; i++)  //двигаемся слева направо
    {
      if (array[i] > array[i + 1])  // если следующий элемент меньше текущего,
      {  // меняем их местами
        double t = array[i];
        array[i] = array[i + 1];
        array[i + 1] = t;
        flag = 1;  // перемещения в этом цикле были
      }
    }
    right--;  // сдвигаем правую границу на предыдущий элемент
    for (int i = right; i > left; i--)  //двигаемся справа налево
    {
      if (array[i - 1] > array[i])  // если предыдущий элемент больше текущего,
      {  // меняем их местами
        double t = array[i];
        array[i] = array[i - 1];
        array[i - 1] = t;
        flag = 1;  // перемещения в этом цикле были
      }
    }
    left++;  // сдвигаем левую границу на следующий элемент
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