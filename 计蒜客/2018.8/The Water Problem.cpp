#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  int water[1010];
  int runs, n, q, l, r;
  cin >> runs;
  while (runs--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> water[i];
    cin >> q;
    for (int i = 0; i < q; i++) {
      cin >> l >> r;
      cout << *max_element(water + l - 1, water + r) << endl;
    }
  }
}
