#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include <iostream>

using namespace std;

typedef struct Label_s {
  char name[16];
  int age;
} Label;

typedef struct LetStats_s {
} LetStats;

typedef struct NameStats_s {
  int cntTotal;
  int cntLong;
} NameStats;

typedef struct AgeStats_s {
  int cntTotal;
  int cntAdults;
  int cntKids;
} AgeStats;

void calcStats(const Label* arr, int cnt, NameStats* oNames, AgeStats* oAges) {
  oNames->cntTotal = oAges->cntTotal = cnt;
  oNames->cntLong = oAges->cntAdults = oAges->cntKids = 0;

  for (int i = 0; i < cnt; i++) {
    if (strlen(arr[i].name) > 10) oNames->cntLong++;

    if (arr[i].age >= 18)
      oAges->cntAdults++;

    else if (arr[i].age < 14)
      oAges->cntKids++;
  }
}

int main() {
  int n;
  std::cin >> n;

  Label* arr = new Label[n];
  string* vsss = new string[n * 3];
  NameStats oNames;
  AgeStats oAges;

  oNames.cntLong = 0;
  oAges.cntAdults = 0;
  oAges.cntKids = 0;

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i].name >> arr[i].age >> vsss[n];
  }
  calcStats(arr, n, &oNames, &oAges);
  std::cout << "names: total = " << oNames.cntTotal << std::endl;
  std::cout << "names: long = " << oNames.cntLong << std::endl;
  std::cout << "ages: total = " << oAges.cntTotal << std::endl;
  std::cout << "ages: adult = " << oAges.cntAdults << std::endl;
  std::cout << "ages: kid = " << oAges.cntKids << std::endl;

  return 0;
}