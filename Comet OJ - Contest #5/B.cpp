#include<iostream>
#include<cmath>
using namespace std;
long long f(long long x) {
  long long sum = 0;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    long long n;
    cin >> n;
    long long cnt = 0;
    for (int i = 2; i <= 18 * 9; i++) {
      if (n % i == 0) {
        if (f(i) == i / 2) cnt++;
        if (f(n / i) == n / i / 2) cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
