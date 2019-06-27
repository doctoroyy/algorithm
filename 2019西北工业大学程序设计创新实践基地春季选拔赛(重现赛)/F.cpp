#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
long long ssum[maxn], a[maxn];
int main() {
  long long n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ssum[i] = ssum[i - 1] + a[i];
  }
  while (q--) {
    long long x, l, r;
    cin >> x >> l >> r;
    long long r1 = ssum[r] - ssum[l - 1], r2 = r1 + x, d = r - l + 1;
    double res = 1.0 * r1 * (n - d) / (d * n) + 1.0 * r2 / n;
    printf("%.6lf\n", res);
  }
  return 0;
}

