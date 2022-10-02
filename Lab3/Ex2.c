#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#define SIZE 100

int de_code(char c);
void calculate(int user_sis, char string[SIZE]);

int main() {
  char string[SIZE];
  int user_sys;
  if (scanf("%d %s", &user_sys, string)) {
    calculate(user_sys, string);
  }
  return 0;
}

int de_code(char c) {
  int x = 0;
  if (c == '0') {
    x = 0;
  } else if (c == '1') {
    x = 1;
  } else if (c == '2') {
    x = 2;
  } else if (c == '3') {
    x = 3;
  } else if (c == '4') {
    x = 4;
  } else if (c == '5') {
    x = 5;
  } else if (c == '6') {
    x = 6;
  } else if (c == '7') {
    x = 7;
  } else if (c == '8') {
    x = 8;
  } else if (c == '9') {
    x = 9;
  } else if (c == 'a') {
    x = 10;
  } else if (c == 'b') {
    x = 11;
  } else if (c == 'c') {
    x = 12;
  } else if (c == 'd') {
    x = 13;
  } else if (c == 'e') {
    x = 14;
  } else if (c == 'f') {
    x = 15;
  }
  return x;
}

void calculate(int user_sis, char string[SIZE]) {
  int len = 0;
  len = strlen(string);
  int digit = 0;
  for (int i = 0; i < len; i++) {
    digit += de_code(string[i]) * pow(user_sis, len - (i + 1));
  }
  printf("%d", digit);
}
