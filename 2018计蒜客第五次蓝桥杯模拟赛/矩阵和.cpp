#include<iostream>
using namespace std;
int main() {
  int a[110][110], n;
  cin >> n;
  int num = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = ++num;
    }
  }
//  for (int i = 1; i <= n; i++) {
//    for (int j = 1; j <= n; j++) {
//      printf("%3d", a[i][j]);
//    }
//    cout << endl;
//  }
  int mid = (n + 1) / 2, l = mid, r = mid, tmp = 1, sum = 0;
  for (int i = 1; i <= n; i++) {
    if (l == 1) {
      tmp = -tmp;
    }
    for (int j = l; j <= r; j++) {
//      printf("%d\n", a[i][j]);
      sum += a[i][j];
    }
    l -= tmp, r += tmp;
  }
  cout << sum << endl;
}
