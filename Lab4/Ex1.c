#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 100
#define SYS 2

void calulate(int digit);

int main() {
  int digit;
  scanf("%d", &digit);
  calulate(digit);
}

void calulate(int digit) {
  int ost;
  int min = 0;
  int max = 0;

  for (; digit > 0;) {
    ost = digit % SYS;
    digit /= SYS;
    if (ost == 1) {
      min++;
      if (min > max) {
        max = min;
      }
    } else {
      min = 0;
    }
  }

  printf("%d", max);
}