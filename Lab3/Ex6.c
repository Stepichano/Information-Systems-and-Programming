#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

char digit(int num) {
  switch (num) {
    case 0:
      return '0';
    case 1:
      return '1';
    case 2:
      return '2';
    case 3:
      return '3';
    case 4:
      return '4';
    case 5:
      return '5';
    case 6:
      return '6';
    case 7:
      return '7';
    case 8:
      return '8';
    case 9:
      return '9';
    case 10:
      return 'a';
    case 11:
      return 'b';
    case 12:
      return 'c';
    case 13:
      return 'd';
    case 14:
      return 'e';
    case 15:
      return 'f';
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
    case 'a':
      return 10;
    case 'b':
      return 11;
    case 'c':
      return 12;
    case 'd':
      return 13;
    case 'e':
      return 14;
    case 'f':
      return 15;
    case '.':
      return 0;
  }
}

void cel_chast(int chisl, int sis) {
  int c = chisl, ost, sist_sch = chisl, mas = 0;
  int ost_mas[1000];
  if (chisl == 0)
    printf("0");
  else {
    while (c != 0) {
      ost = c % sis;
      c /= sis;
      ost_mas[mas] = ost;
      mas++;
    }
    for (int i = mas - 1; i >= 0; i--) {
      printf("%c", digit((ost_mas[i])));
    }
  }
}

int step_one_cel(int sis, char* str) {
  int stepen = -1, otvet = 0, boofer;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '.') break;
    stepen++;
    str[i] = digit(str[i]);
  }

  for (int i = 0, boof_2 = stepen; i <= boof_2; i++) {
    boofer = pow(sis, stepen);
    otvet += (str[i]) * boofer;
    stepen--;
  }

  return otvet;
}

double step_two_drob(int sis, char* str, int len_str) {
  int stepen = 1;
  double otvet = 0, boofer;

  for (int i = len_str; str[i] != '\0'; i++) {
    stepen++;
    str[i] = digit(str[i]);
  }
  // printf("- %i -\n", stepen);
  for (int i = len_str; i <= stepen + len_str - 2; i++) {
    // printf("\n%d /-/ %d\n", str[i], i-len_str+1);
    boofer = pow(sis, -(i - len_str + 1));
    // printf("%i * %lf\n", str[i], boofer);
    otvet += (str[i]) * boofer;
  }
  // printf("\n--- %lf ---\n", otvet);
  return otvet;
}

void ostatok_chisl(double chisl, float sis, int k) {
  // printf("\n--- %lf ---\n", chisl);
  int boof;
  int ost_mas[1000];
  for (int i = 0; i <= k; i++) {
    boof = chisl;   //получаем целую часть
    chisl -= boof;  //получаем дробную часть
    chisl = (chisl + 0.0000000000001) * sis;  //умножаем
    boof = chisl;
    ost_mas[i] = boof;
    // printf("\n--%d --", boof);
  }

  int check = -1;
  for (int i = k; i >= 0; i--) {
    if (ost_mas[i] == 0)
      check++;
    else
      i = 0;
  };
  if (check == -1)
    for (int i = 0; i <= k - 1; i++) printf("%c", digit(ost_mas[i]));
  else
    for (int i = 0; i <= k - check - 1; i++) printf("%c", digit(ost_mas[i]));
}

void main() {
  char str[80];
  int i = 0, d = 0;

  int one, two, ogran;
  int len_str = 1, otvet_one;
  double otvet_two;

  int checking_one = 0, checking_two = 0;
  scanf("%i %i %i", &one, &two, &ogran);
  scanf("%s", str);

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '.') checking_one++;
    if (digit(str[i]) >= one) checking_two++;
  }

  if (checking_one == 0 && checking_two == 0) {
    otvet_one = step_one_cel(one, str);
    cel_chast(otvet_one, two);
  } else if (checking_one == 1 && checking_two == 0) {
    for (int i = 0; str[i] != '.'; i++) {
      len_str++;
    }
    // printf("%d", len_str);

    otvet_one = step_one_cel(one, str);
    cel_chast(otvet_one, two);
    printf(".");
    otvet_two = step_two_drob(one, str, len_str);
    ostatok_chisl(otvet_two, two, ogran);
  } else
    printf("NO");
}