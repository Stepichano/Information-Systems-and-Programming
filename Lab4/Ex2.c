#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE_BIT 32

int get_bit(unsigned long numb, int bit);
void output_digit_bit(int n);
int reverse(int n);

int main() {
  int n, bufer_n;
  scanf("%d", &n);
  bufer_n = n;
  n = reverse(n);
  output_digit_bit(n);
  printf("\n");
  printf("%d\n", n);
  output_digit_bit(bufer_n);
  return 0;
}

int get_bit(unsigned long numb, int bit) {
  long unsigned mask = 1 << bit;
  return !!(mask & numb);
}

void output_digit_bit(int n) {
  for (int i = 0; i < 32; i++) {
    printf("%d", get_bit(n, i));
  }
}

int reverse(int n) {
  long unsigned mask = 0;
  for (int i = 0; i < 32; i++) {
    mask |= (get_bit(n, i) << (31 - i));
  }
  return mask;
}
