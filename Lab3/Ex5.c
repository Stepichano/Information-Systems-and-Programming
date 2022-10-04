#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
#define SIZE 100

char code(int c);
int ten_sys(int user_sys, char string[SIZE]);
void calculate(int user_sys, int new_sys, char user_digit[SIZE]);

int main() {
  char user_digit[SIZE];
  int user_sys, new_sys;
  if (scanf("%d %d %s", &user_sys, &new_sys, user_digit)) {
    calculate(user_sys, new_sys, user_digit);
  }
  return 0;
}

int de_code(char c) {
  int x;
  if ((int)c - 87 >= 0) {
    x = (int)c - 87;
  } else {
    x = (int)c - 48;
  }
  return x;
}

char code(int ost) {
  char c = ' ';
  if (ost >= 0 && ost <= 9) {
    c = (char)(ost + 48);
  } else if (ost >= 10 && ost <= 36) {
    c = (char)(87 + ost);
  }
  return c;
}

void calculate(int user_sys, int new_sys, char user_digit[SIZE]) {
  int ost, digit, len, array[SIZE];
  digit = ten_sys(user_sys, user_digit);

  for (int i = 0; digit; i++) {
    ost = digit % new_sys;
    digit /= new_sys;
    array[i] = ost;
    len = i;
  }

  for (int i = len; i >= 0; i--) {
    printf("%c", code(array[i]));
  }
}

int ten_sys(int user_sys, char string[SIZE]) {
  int len = strlen(string);
  int ten_digit = 0;

  for (int i = 0; i < len; i++) {
    ten_digit += de_code(string[len - (i + 1)]) * pow(user_sys, i);
  }

  return ten_digit;
}