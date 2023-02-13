#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printTime(int h, int m, int s);

int main() {
  int count, h, m, s;
  scanf("%d", &count);
  for (int i = 0; i < count; i++) {
    scanf("%d %d %d", &h, &m, &s);
    printTime(h, m, s);
  }
}

void printTime(int h, int m, int s) { printf("%02d:%02d:%02d\n", h, m, s); }
