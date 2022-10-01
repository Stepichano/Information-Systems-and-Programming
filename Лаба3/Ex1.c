#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char code(int ost);
void calculate(int user_chisl, int user_sis);

int main() {
  int user_sis, user_chisl;
  scanf("%d%d", &user_sis, &user_chisl);
  calculate(user_chisl, user_sis);
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

void calculate(int user_chisl, int user_sis) {
  int ost;
  int mas = 0;
  int ost_mas[1000];

  while (user_chisl != 0) {
    ost = user_chisl % user_sis;
    ost_mas[mas] = ost;
    user_chisl /= user_sis;
    mas++;
    if (user_sis == 1) {
      break;
    }
  }

  for (int i = mas - 1; i >= 0; i--) {
    int c = ost_mas[i];
    printf("%c", code(c));
  }

  if (user_chisl == 0 && mas == 0) {
    printf("0");
  }
}