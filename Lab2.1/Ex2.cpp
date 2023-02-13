#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

int readTime(char* iStr, int* oHours, int* oMinutes = nullptr,
             int* oSeconds = nullptr) {
  int hours, minutes, seconds;
  bool flag = true;
  int res{sscanf(iStr, " %d:%d:%d", &hours, &minutes, &seconds)};
  if (res < 1) {
    flag = false;
  }
  if (res == 2) {
    seconds = 0;
  }
  if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 ||
      seconds > 59) {
    flag = false;
  }
  if (flag) {
    *oHours = hours;
  } else {
    *oHours = -1;
  }
  if (oMinutes != nullptr) {
    if (flag) {
      *oMinutes = minutes;
    } else {
      *oMinutes = -1;
    }
  }
  if (oSeconds != nullptr) {
    if (flag) {
      *oSeconds = seconds;
    } else {
      *oSeconds = -1;
    }
  }
  return flag;
}

int main() {
  int hours, minutes, seconds;
  char str[15];
  std::cin >> str;
  int res{readTime(str, &hours, &minutes, &seconds)};
  std::cout << res << " " << hours << " " << minutes << " " << seconds
            << std::endl;
  res = readTime(str, &hours, &minutes);
  std::cout << res << " " << hours << " " << minutes << std::endl;
  res = readTime(str, &hours);
  std::cout << res << " " << hours << std::endl;
  return 0;
}