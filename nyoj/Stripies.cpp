#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
  double a[1100] = {0};
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a+1, a+n+1);
  for (int i = n - 1; i > 0; i--) {
    a[i] = 2 * sqrt(a[i+1]*a[i]);
  }
  printf("%.3lf", a[1]);
}
