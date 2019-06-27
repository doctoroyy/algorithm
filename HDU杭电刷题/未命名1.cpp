#include<iostream>
#include<iomanip>
using namespace std;
class Date {
  private:
    int year, month, day;
    bool LeapYear(int) const;
    int DatetoInt() const;
    Date InttoDate(int);
  public:
    Date(int y = 1900, int m = 1, int d = 1);
    int GetYear() {
      return year;
    }
    int GetMonth() {
      return month;
    }
    int GetDay() {
      return day;
    }
    void SetDate(int, int, int);
    friend int operator-(const Date &, const Date &);
    Date operator+(int);
    Date operator-(int);
    Date& operator+=(int);
    Date& operator-=(int);
    friend bool operator==(const Date &, const Date &);
    friend bool operator<(const Date &, const Date &);
    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);
    friend ostream &operator<<(ostream &, const Date &);
    friend istream &operator>>(istream &, Date &);
    int DayOfWeek();
    void ShowCalendar();
};

int MonthDay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool Date::LeapYear(int y) const {
  return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
Date::Date(int y, int m, int d) {
  SetDate(y, m, d);
}
void Date::SetDate(int y, int m, int d) {
  month = (m >= 1 && m <= 12) ? m : 1;
  year = (y >= 1900 && y <= 2100) ? y : 1900;
  if (month == 2 && LeapYear(year))
    day = (d >=1 && d <= 29) ? d : 1;
  else
    day = (d >=1 && d <= MonthDay[month]) ? d : 1;
}
int Date::DatetoInt() const {
  int s = 0, k = year - 1;
  s += k * 365 + k / 4 - k / 100 + k / 400;
  for (int i = 1; i < month; i++) s += MonthDay[i];
  if (LeapYear(year) && month > 2) s++;
  s += day;
  return s;
}
Date Date::InttoDate(int n) {
  int y = 1, days = LeapYear(y) ? 366 : 365;
  while (n > days) {
    n -= days;
    y++;
    days = LeapYear(y) ? 366 : 365;
  }
  if (LeapYear(y)) MonthDay[2] = 29;
  int m = 1;
  while (n > MonthDay[m]) {
    n -= MonthDay[m];
    m++;
  }
  return Date(y, m, n);
}
int operator-(const Date &x, const Date &y) {
  return x.DatetoInt() - y.DatetoInt();
}
Date Date::operator+(int n) {
  return InttoDate(DatetoInt() + n);
}
Date Date::operator-(int n) {
  return InttoDate(DatetoInt() - n);
}
Date& Date::operator+=(int n) {
  *this = *this + n;
  return *this;
}
Date& Date::operator-=(int n) {
  *this = *this - n;
  return *this;
}
Date& Date::operator++() {
  *this += 1;
  return *this;
}
Date Date::operator++(int) {
  Date tmp(year, month, day);
  *this += 1;
  return tmp;
}
Date& Date::operator--() {
  *this -= 1;
  return *this;
}
Date Date::operator--(int) {
  Date tmp(year, month, day);
  *this -= 1;
  return tmp;
}
bool operator==(const Date &x, const Date &y) {
  return x.year == y.year && x.month == y.month && x.day == y.day;
}
bool operator!=(const Date &x, const Date &y) {
  return !(x == y);
}
bool operator<(const Date &x, const Date &y) {
  if (x.year == y.year)
    if (x.month == y.month)
      return x.day < y.day;
    else
      return x.month < y.month;
  else
    return x.year < y.year;
}
bool operator>(const Date &x, const Date &y) {
  return y < x;
}
bool operator<=(const Date &x, const Date &y) {
  return !(y < x);
}
bool operator>=(const Date &x, const Date &y) {
  return !(x < y);
}
ostream &operator<<(ostream &out, const Date &d) {
  out << d.year << "年" << d.month << "月" << d.day << "日" << endl;
  return out;
}
istream &operator>>(istream &in, Date &d) {
  int a, b, c;
  in >> a >> b >> c;
  d.SetDate(a, b, c);
  return in;
}
int Date::DayOfWeek() {
  return DatetoInt() % 7;
}
void Date::ShowCalendar() {
  cout << "             " << year<< " 年 " << month << " 月 " << endl;
  cout<<"   日   一   二   三   四   五   六" << endl;
  int firstday = (DayOfWeek() - day + 36) % 7;
  if (firstday != 0)
    cout << setw(firstday * 5) << ' ';
  int sumday = MonthDay[month];
  if (LeapYear(year) && month == 2) sumday++;
  for (int i = 1; i <= sumday; i++) {
    cout << setw(5) << i;
    if ((i + firstday) % 7 == 0 ) cout << endl;
  }
}
int main() {
  Date a(2019, 4, 8), b(2019, 3, 4), c;
  if (a < b) {
    cout << b;
  } else {
    cout << a;
  }
}
