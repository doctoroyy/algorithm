#include<iostream>
using namespace std;
const int weekDay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLeapYear(int year) {
  return (year % 100 != 0 && y % 4 == 0) || (year % 400 == 0);
}
int dateToInt(int year, int month, int day) {
  int sumDays = 0;
  for (int i = 1; i < year; i++) {
    sumDays += 365;
    if (isLeapYear(i)) sumDays++;
  }
  for (int i = 1; i < month; i++) {
    sumDays += weekDay[i]; 
  }
  sumDays += day;
  if (month > 2 && isLeapYear(year)) sumDays++;
  return sumDays; 
}

int main() {

  return 0;
}

