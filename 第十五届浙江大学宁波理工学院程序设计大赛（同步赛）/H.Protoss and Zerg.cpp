#include<iostream>
using namespace std;
const int N = 998244353;
long long quickpow(int n, int k) {
  long long base = n, res = 1;
  while (k) {
    if (k & 1) res = res % N * base % N;
    base = base  % N * base % N;
    k >>= 1;
  }
  return res;
}
int main() {
  long long t, n, a, b;
  cin >> t;
  while (t--) {
    cin >> n;
    long long res = 1;
    while (n--) {
      cin >> a >> b;
      res = res * ((quickpow(2, a) - 1) % N + (quickpow(2, b) - 1) % N) % N;
    }
    cout << res << endl;
  }
  return 0;
}

