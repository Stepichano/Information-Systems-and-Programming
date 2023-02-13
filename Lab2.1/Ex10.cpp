#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef union {
  double d;
  uint64_t u;
} value;

double xor_double(double x, uint64_t m) {
  value v;
  v.d = x;
  v.u ^= m;
  return v.d;
}

int main() {
  int n;
  scanf("%d", &n);

  while (n--) {
    int p, q;
    uint64_t m;
    scanf("%d/%d xor %llx", &p, &q, &m);
    double x = (double)p / q;
    double res = xor_double(x, m);
    printf("%0.15g\n", res);
  }

  return 0;
}