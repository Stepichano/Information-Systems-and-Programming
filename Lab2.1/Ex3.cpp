#include <stdio.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

#define SEKONDS 86400.0
#define MINUNTS 1440.0
#define HOURS 24.0
#define MONTH 31
#define YEAR 365
#define RETURN return 0
#define RUSSIAN setlocale("LC_ALL", "Russian")

typedef struct DateTime_s {
  int year, month, day;
  int hours, minutes, seconds;
} DateTime;

DateTime min(const DateTime* arr, int cnt);

int main() {
  int cnt = 1;
  cin >> cnt;

  DateTime* arr = new DateTime[cnt];

  for (int i = 0; i < cnt; i++) {
    cin >> arr[i].year >> arr[i].month >> arr[i].day >> arr[i].hours >>
        arr[i].minutes >> arr[i].seconds;
  }

  DateTime date = min(arr, cnt);
  cout << date.year << ' ' << date.month << ' ' << date.day << ' ' << date.hours
       << ' ' << date.minutes << ' ' << date.seconds << endl;
  delete arr;

  RETURN;
}

DateTime min(const DateTime* arr, int cnt) {
  double date_min = arr[0].seconds / SEKONDS + arr[0].minutes / MINUNTS +
                    arr[0].hours / HOURS + arr[0].day + arr[0].month * MONTH +
                    arr[0].year * YEAR;
  int min = 0;
  for (int i = 1; i < cnt; i++) {
    double date = arr[i].seconds / SEKONDS + arr[i].minutes / MINUNTS +
                  arr[i].hours / HOURS + arr[i].day + arr[i].month * MONTH +
                  arr[i].year * YEAR;
    DateTime d = arr[i];
    if (date < date_min) {
      date_min = date;
      min = i;
    }
  }
  return arr[min];
}
