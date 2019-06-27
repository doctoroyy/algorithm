#include<iostream>
using namespace std;
const int mod = 1e9 + 7;
long long quick_pow(long long n, long long k) {
  long long res = 1, base = n % mod;
  while (k) {
    if (k & 1) res = ((res % mod) * (base % mod)) % mod;
    base = ((base % mod) * (base % mod)) % mod;
    k >>= 1; 
  }
  return res;
}
long long C(long long m, long long n) {
  if (n == 0 || (m == n)) return 1;
  n = min(m - n, n);
  long long a = 1, b = 1, res = 1;
  for (long long i = 1; i <= n; i++) {
    a = ((a % mod) * (m - i + 1) % mod) % mod;
    b = ((b % mod) * (i % mod)) % mod;
  }
  return a * quick_pow(b, mod - 2) % mod;
}
int main() {
  long long m, n;
  cin >> n >> m;
  cout << C(m - 1, n - 1) << " " << C(m + n - 1, n - 1) << endl; 
  return 0;
}
