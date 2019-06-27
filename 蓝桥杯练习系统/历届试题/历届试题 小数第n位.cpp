#include<iostream>
using namespace std;
long long gcd(long long m, long long n) {
  return m % n == 0 ? n : gcd(n, m % n);
}
long long quick_pow(long long n, long long k, long long mod) {
  long long res = 1, base = n % mod;
  while (k) {
    if (k & 1) res = (res % mod) * (base % mod) % mod;
    base = ((base % mod) * (base % mod)) % mod;
    k >>= 1;
  }
  return res;
}
int main() {
  long long m, n, k1, k2;
  cin >> m >> n >> k1;
  k2 = k1 + 2;
  long long gcd_mn = gcd(m, n);
  m /= gcd_mn, n /= gcd_mn;
  long long res = (m * quick_pow(10, k1 - 1, n)) % n;
  for (long long i = k1; i <= k2; i++) {
    res *= 10;
    cout << res / n;
    res %= n;
  }
  return 0;
}

