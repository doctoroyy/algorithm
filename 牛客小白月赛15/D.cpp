#include<iostream>
#include<cmath>
using namespace std;
long long gcd(long long m, long long n) {
  if (m % n == 0) return n;
  return gcd(n, m % n);
}
long long lcm(long long m, long long n) {
  return m  / gcd(m, n) * n;
}
int main() {
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int base = lcm(y1, y2);
  x1 *= (base / y1);
  x2 *= (base / y2);
  int ans1 = x1 + x2, ans2 = x1 - x2;  
  cout << ans1 / gcd(ans1, base)<< " " << base / gcd(ans1, base) << endl;
  if (ans2 == 0) {
    cout << "0 0\n";
  } else {
    cout << ans2 / gcd(ans2, base) << " " << base / gcd(ans2, base) << endl;
  }
  cout << x1 * x2 / gcd(x1 * x2, base * base) << " " << base * base / gcd(x1 * x2, base * base) << endl;
  cout << x1 / gcd(x1, x2) << " " << x2 / gcd(x1, x2);
  return 0;
}
