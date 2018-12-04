#include<iostream>
#include<cmath>
using namespace std;
int getRow(int num, int w) {
  return (num-1)/w+1;
}
int getCol(int num, int w) {
  if (getRow(num, w) & 1) {
    return num % w == 0 ? w : num % w;
  } else {
    return num % w == 0 ? 1 : (w - num % w) + 1;
  }
}
int main() {
  int w, m, n;
  while (cin >> w >> m >> n) {
    int mx = getRow(m, w), my = getCol(m, w),
    nx = getRow(n, w), ny = getCol(n, w);
    cout << abs(mx - nx) + abs(my - ny) << endl;
  }
}
