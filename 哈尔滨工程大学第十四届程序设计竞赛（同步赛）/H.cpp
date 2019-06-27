#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
int main() {
  int t;
  cin >> t;
  ll n;
  while (t--) {
    ll k;
    cin >> n;
    cin >> k;
    ll m = 1e16;
    for (int i = 0; i < k-1; i++) {
      cin >> a[i];
      m = min(m, a[i]);
    }
    printf("%.0lf\n", 1.0 * n / m + 0.5 + k - 2);
  }
  return 0;
}
