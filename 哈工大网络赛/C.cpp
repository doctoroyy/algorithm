#include<iostream>
using namespace std;
long long a, n, b;
long long quickPow(long long n, long long k) {
  long long res = 1, base = n % b;
  while (k) {
    if (k & 1) res = ((res % b) * (base % b)) % b;
    base = (base % b) * (base % b) % b;
    k >>= 1;
  }
  return res;
}
int main() {
  int runs;
  cin >> runs;
  while (runs--) {
    cin >> a >> n >> b;
    cout << quickPow(a, n) << endl;
  }
  return 0;
}

