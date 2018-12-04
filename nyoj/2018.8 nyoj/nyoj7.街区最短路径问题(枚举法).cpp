#include<iostream>
#include<cmath>
const int maxn = 100 + 10;
using namespace std;
int main() {
  int x[maxn], y[maxn];
  int runs, n;
  cin >> runs;
  while (runs--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }
    int minStep = 1e9 + 10, tmp;
    for (int i = 1; i < maxn; i++) { 
      for (int j = 1; j < maxn; j++) {
        tmp = 0;
        for (int k = 0; k < n; k++ ) {
          tmp += abs(i - x[k]) + abs(j - y[k]);
        }
        minStep = min(tmp, minStep);
      }
    }
    cout << minStep << endl;
  }
  return 0;
}

