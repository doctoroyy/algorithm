#include<iostream>
#include<cmath>
using namespace std;
int main() {
  long long n;
  while (cin >> n) {
    int cnt = 0;
    for (long long i = 1; i <= n; i++) {
      double j = sqrt(1.0 * n * n - 1.0 * i * i);
      if (double((int)j) == j && (int)j + i > n) { //j刚好是整数且两边之和大于第三边 
        cout << i << " " << (int)j << " " << n << endl;
        cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}

