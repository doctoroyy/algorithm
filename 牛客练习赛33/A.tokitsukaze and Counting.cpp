#include<iostream>
using namespace std;
int main() {
  long long t, l, r, x;
  cin >> t;
  while (t--) {
    cin >> l >> r >> x;
    if (x == 1) {
      cout << r - l + 1 << endl;
      continue;
    }
    cout << r / x - l / x + (l % x == 0) << endl;
  }

  return 0;
}

