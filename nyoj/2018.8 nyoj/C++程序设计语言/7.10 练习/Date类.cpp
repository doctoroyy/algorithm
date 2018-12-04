#include<iostream>
using namespace std;
class Date {
    int y, m, d;
    static Date default_date;
  public:
    Date(int yy = 0, int mm = 0, int dd = 0);
    void print(const Date &date) {
      cout << date.y << " " << date.m << " " << date.d << endl;
    }
    static void set_default(int, int, int);
};
Date::Date(int yy, int mm, int dd) {
  d = dd ? dd : default_date.d;
  m = mm ? mm : default_date.m;
  y = yy ? yy : default_date.y;
}
Date Date::default_date(2017, 1, 1);
void Date::set_default(int yy, int mm, int dd) {
  Date::default_date = Date(yy, mm, dd);
}
int main() {
  Date date;
  date.print(date);
  return 0;
}

