#include <stdio.h>
#include <string.h>

void reverse(char *start, int len) {
  for (int i = 0; i < len / 2; i++) {
    char t = *(start + len - i - 1);
    *(start + len - i - 1) = *(start + i);
    *(start + i) = t;
  }
  printf("%s\n", start);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char s[1000];
    scanf("%s", &s);
    reverse(s, strlen(s));
  }
}