#include<iostream>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int idx = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > a[idx]) idx = i;
    }
    int l = m, r = m;
    for (int i = 0; i < n; i = (i + 1) % n) {
      if (a[i] == a[idx]) {
        if (r < 0) {
          cout << "NO\n";
          break;
        } else if (l <= 0) {
          cout << "YES\n";
          break;
        }
        l -= a[i];
        r -= a[i];
      } else {
        if (r <= 0) {
          cout << "NO\n";
          break;
        }
        l -= a[i];
        r -= 1;
      }
    }
  }
  return 0;
}
