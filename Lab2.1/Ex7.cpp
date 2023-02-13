#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string str;
  int n;
  cin >> str;
  vector<string> kallmass;
  string tmp = "";

  for (int i = 0; i < str.length(); i++) {
    if (!(str[i] > 64 && str[i] < 91 || str[i] > 96 && str[i] < 123)) {
      if (tmp != "") {
        kallmass.push_back(tmp);
        tmp = "";
      }
    } else
      tmp += str[i];
  }

  if (tmp.length() > 0) kallmass.push_back(tmp);
  cout << kallmass.size() << endl;
  for (int i = 0; i < kallmass.size(); i++) {
    cout << kallmass[i] << endl;
  }

  return 0;
}