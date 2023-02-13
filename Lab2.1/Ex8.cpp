#include <stdio.h>
#include <string.h>

char *concat(char *pref, char *suff) {
  int len_pref = strlen(pref);
  int len_suff = strlen(suff);
  for (int i = 0; i <= len_suff; ++i) {
    pref[len_pref + i] = suff[i];
  }
  return pref + len_pref + len_suff;
}

int main() {
  int n;
  scanf("%d\n", &n);

  char result[100 * 10000 + 1] = "";
  char str[101];
  for (int i = 0; i < n; ++i) {
    scanf("%100s", str);
    concat(result, str);
  }

  printf("%s", result);
  return 0;
}