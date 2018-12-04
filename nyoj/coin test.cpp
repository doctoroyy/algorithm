
#include<iostream>
using namespace std;
int gcd(int m, int n) {
  return m % n == 0 ? n : gcd(n, m % n);
}
char a[70000];
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int k = 0;
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 'S') {
        flag = 1;
        break;
      }
      if (a[i] == 'U') k++;
    }
    double s = (double)k / n;
//    cout << s << endl;
    if (flag) {
      cout << "Bingo" << endl;
    } else if (s <= 0.5+0.003 && s >= 0.5-0.003) {
      cout << k / gcd(k, n) << "/" << n / gcd(k, n) << endl;
    } else cout << "Fail" << endl;
  }
}
