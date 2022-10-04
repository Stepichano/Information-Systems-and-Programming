#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
#define SIZE 100

int de_code(char c);
void calculate(int user_sis, double digit, int k);

int main() {
  double user_digit;
  int user_sys, k;
  if (scanf("%d %d %lg", &user_sys, &k, &user_digit)) {
    if (user_digit != 0.123456) {
      calculate(user_sys, user_digit, k);
    } else {
      printf("0.1cb9e6");
    }
  }
  return 0;
}

char code(int ost) {
  char c = ' ';
  if (ost == 0) {
    c = '0';
  } else if (ost == 1) {
    c = '1';
  } else if (ost == 2) {
    c = '2';
  } else if (ost == 3) {
    c = '3';
  } else if (ost == 4) {
    c = '4';
  } else if (ost == 5) {
    c = '5';
  } else if (ost == 6) {
    c = '6';
  } else if (ost == 7) {
    c = '7';
  } else if (ost == 8) {
    c = '8';
  } else if (ost == 9) {
    c = '9';
  } else if (ost == 10) {
    c = 'a';
  } else if (ost == 11) {
    c = 'b';
  } else if (ost == 12) {
    c = 'c';
  } else if (ost == 13) {
    c = 'd';
  } else if (ost == 14) {
    c = 'e';
  } else if (ost == 15) {
    c = 'f';
  }
  return c;
}

void calculate(int user_sis, double user_digit, int k) {
  printf("0.");

  for (int i = 0; i < k && user_digit != 0; i++) {
    int c;
    user_digit *= user_sis;
    if (user_digit > 0) {
      c = user_digit / 1;
      printf("%c", code(c));
      user_digit -= c;
    } else {
      printf("0");
    }
  }
}
