#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int test_ferma(int x);
long long gcd(long long a, long long b);
long long mul(long long a, long long b, long long m);
long long pows(long long a, long long b, long long m);

int main() {
  int n;
  scanf_s("%d", &n);
  if (n >= 1 && n <= 10000) {
    if (test_ferma(n)) {
      printf("YES");
    } else {
      printf("NO");
    }
  }
  return 0;
}

int test_ferma(int x) {
  if (x == 1) return 0;
  if (x == 2) return 1;
  srand(time(NULL));
  for (int i = 0; i < 100; i++) {
    int a = (rand() % (x - 2)) + 2;
    if (gcd(a, x) != 1) return 0;
    if (pows(a, x - 1, x) != 1) return 0;
  }
  return 1;
}

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

long long mul(long long a, long long b, long long m) {
  if (b == 1) return a;
  if (b % 2 == 0) {
    long long t = mul(a, b / 2, m);
    return (2 * t) % m;
  }
  return (mul(a, b - 1, m) + a) % m;
}

long long pows(long long a, long long b, long long m) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    long long t = pows(a, b / 2, m);
    return mul(t, t, m) % m;
  }
  return (mul(pows(a, b - 1, m), a, m)) % m;
}