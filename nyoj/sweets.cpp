#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 100;
int main() {
  int a[maxn + 10];
  int n;
  while (cin >> n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % n != 0) {
      cout << "-1" << endl;
      continue;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int tmp = abs(a[i] - sum / n);
      if (tmp % 2 != 0) {
        cnt = -1;
        break;
      } else {
        if (a[i] > sum / n)
          cnt += tmp / 2;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}

