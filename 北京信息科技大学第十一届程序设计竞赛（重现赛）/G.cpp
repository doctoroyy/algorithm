#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 50 + 10;

double f(int m, int n) {
  double ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = ans * m / i;
    m--;
  }
  return ans;
}

double _pow(double n, int k) {
  double ans = 1;
  while (k--) {
    ans *= n;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  double n, m;
  cin >> m >> n;
  printf("%.4f\n", f(m, n) * _pow(0.8, n) * _pow(0.2, m - n));
  
  return 0;
}

