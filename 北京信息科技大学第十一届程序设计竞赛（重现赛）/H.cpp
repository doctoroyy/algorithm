#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e3 + 10;
double a[maxn], b[maxn];
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    double ans = 0;
    for (int i = 0; i < n; i++) {
      ans += a[i] * b[n - i - 1];
    }
    printf("%.3lf\n", ans);
  }
  return 0;
}

