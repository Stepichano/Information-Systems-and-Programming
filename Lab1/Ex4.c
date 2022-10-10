#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mas[200000];

int main() {
  int N, Q, n, k = 0;
  scanf(
      "%d"
      "%d",
      &N, &Q);
  if (N < 10) N = 10;
  if (N > 20000000) N = 20000000;
  if (Q < 1) Q = 1;
  if (Q > 200000) Q = 200000;
  for (int i = 0; i < Q; i++) scanf("%d", &mas[i]);
  for (int i = 0; i < Q; i++) {
    n = mas[i];
    if (i != 0) printf("\n");
    k = 0;
    printf("%d ", n);
    if (n < 2 || n > N) {
      printf("not");
      continue;
    }
    for (int j = 2; j * j <= n; j++) {
      if (n % j == 0) {
        k = 1;
        printf("not");
        break;
      }
    }
    if (k == 0) printf("prime");
  }
}