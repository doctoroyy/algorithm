#include<iostream>
#include<cstdio>
using namespace std;
int main() {
  int t;
  cin >> t;
  double l, v1, v2;
  while (t--) {
    cin >> l >> v1 >> v2;
    double l1 = 1.0 / 2 * 9.8 * (l/v1) * (l/v1);
    double l2 = v2 * l / v1;
    printf("%.6f %.6f\n", l1, l2);
    return 0;
  }
}
