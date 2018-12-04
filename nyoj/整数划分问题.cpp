#include<iostream>
using namespace std;
int f(int m, int n) {
  if (m < n) return f(m, m);
  if (n == 1 || m == 1 || n == 0) return 1;
  return f(m, n - 1) + f(m - n, n);
}
int main() {
  int m, n;
  while (cin >> m >> n) {
    cout << f(m, n) << endl;
  }
  return 0;
}

