#include<iostream>
using namespace std;
int gcd(int m, int n) {
  return m % n ? gcd(n, m % n) : n;
}
int main() {
  int m, n;
  while (cin >> m >> n) {
    if (gcd(m, n) == 1) {
      cout << "NO\n";
      continue;
    } else {
      cout << n - n / gcd(m, n) << " " ;
      for (int i = 1; i < n; i++) {
        if (i % gcd(m, n) != 0) cout << i << " ";
      }
      cout << endl;
    }
  }
  return 0;
}

