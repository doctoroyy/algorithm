#include<iostream>
#include<cmath> 
using namespace std;
int main() {
  long long n, k;
  while (cin >> n >> k) {
    int nums = (sqrt(8 * n + 1) - 1) / 2;
    int cnt = 0;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= nums + 2; j++) {
        if (j * (2 * i + (j - 1) * k) / 2 == n) {
//          cout << "首项：" << i << "  项数：" <<  j << endl;
          cnt++;
        }
      }
    }
    cout << cnt << endl; 
  }
  return 0;
}

