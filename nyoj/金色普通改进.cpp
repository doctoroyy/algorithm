/*
金色普通

改进
*/
#include<iostream>
#include<cmath>
using namespace std;
int main() {
  int n, k;
  while (cin >> n >> k) {
    int cnt = 0; 
    int nums = (sqrt(8 * n + 1) - 1) / 2;
    for (int i = 1; i <= nums + 2; i++) {
      int a1 = n * 1.0 / i - (i - 1) * 1.0 * k / 2.0;
      if ((a1 + a1 + (i - 1) * k) * i / 2 == n && a1 > 0) {
//        cout << a1 << " " << i << endl;
        cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}

