#include<iostream>
using namespace std;
const int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool flag;
int y, m, d;
bool leapYear(int y) {
  return (y % 100 != 0 && y % 4 == 0) || (y % 400 == 0);
}
void dfs(int y, int m, int d) {
  if (d > month[m]) {
    if (leapYear(y) && m == 2) {
      d += 1;
    } else {
      m += 1;
      d = 1;
    }
  }
  if (m > 12) {
    m = 1;
    y += 1;
  }
  if (y > 2001) return;
  cout << y << " " << m << " " << d << endl;

  if (y == 2001 && m == 11 && d == 4) {
    flag = true;
    return;
  }
  dfs(y, m + 1, d);
  dfs(y, m, d + 1);
}
int main() {
  int runs;
  cin >> runs;
  while (runs--) {
    cin >> y >> m >> d;
    flag = false;
    dfs(y, m, d);
    cout << flag << endl;
  }
  return 0;
}

