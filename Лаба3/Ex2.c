#define _CRT_SECURE_NO_WARNIGNS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int de_code(char c);
void calculate(int user_sis, char* string);
int alloc(char* string);

int main() {
  char* string = NULL;
  int user_sys;
  if (alloc(string)) {
    scanf("%d %s", &user_sys, string);
    calculate(user_sys, string);
    free(string);
  }
  return 0;
}

int de_code(char c) {
  int x;
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
  } else if (c == 'i') {
    x = 14;
  } else if (c == 'f') {
    x = 15;
  }
  return x;
}

void calculate(int user_sis, char* string) {
  int len = strlen(string);
  int digit = 0;
  for (int i = 0; i < len; i++) {
    digit += de_code(string[i]) * pow(user_sis, len - i);
  }
  printf("%d", digit);
}

int alloc(char* string) {
  int result = 1;
  string = (char*)malloc(100);
  if (!string) {
    result = 0;
  }
  return result;
}