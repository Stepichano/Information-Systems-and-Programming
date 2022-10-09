#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SYS 2

int get_bit(unsigned long numb, int bit);
int calulate(int digit);

int main() {
  int digit;
  scanf("%d", &digit);
  printf("%d", calulate(digit));
  return 0;
}

int calulate(int digit) {
  int ost;
  int min = 0;
  int max = 0;

  for (int i = 0; i < 32; i++) {
    if (get_bit(digit, i)) {
      min++;
      if (min > max) {
        max = min;
      }
    } else {
      min = 0;
    }
  }

  return max;
}

int get_bit(unsigned long numb, int bit) {
  long unsigned mask = 1 << bit;
  return !!(mask & numb);
}