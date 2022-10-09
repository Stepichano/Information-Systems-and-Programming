#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 2000000

int search_k(int n);

int main() {
  int array[SIZE];
  int n, k, x;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }
  for (int i = 0; i < n; i++) {
    k = search_k(array[i]);
    printf("%lg", pow(2, k));
    if (i != n - 1) {
      printf("\n");
    }
  }
  return 0;
}

int search_k(int n) {
  int r;
  int result = 1;
  for (int i = 1; i <= 17; i++) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      result = i - 1;
      break;
    }
  }
  return result;
}
