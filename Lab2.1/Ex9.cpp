#include <unordered_map>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include <iostream>

using namespace std;

int main() {
  int nq, w, kel, l, c, id = 0;
  char chich, *tst;
  // tst = (char*)malloc(100000);
  unordered_map<int, char*> data;
  cin >> nq;
  for (int i = 0; i < nq; i++) {
    cin >> w >> kel;
    switch (w) {
      case 0: {
        data[id] = (char*)malloc(kel + 1);
        cin >> data[id];
        id++;
      } break;
      case 1: {
        free(data[kel]);
        data.erase(kel);
      } break;
      case 2:
        cout << data[kel] << endl;
        break;
      case 3: {
        cin >> chich;
        l = strlen(data[kel]);
        c = 0;
        for (int j = 0; j < l; j++)
          if (data[kel][j] == chich) c++;
        cout << c << endl;
      }
    }
  }
}