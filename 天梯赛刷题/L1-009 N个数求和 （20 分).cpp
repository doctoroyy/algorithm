#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
//这一题要使用long long才能过全部测试数据 
long long gcd(long long m, long long n) {
  return m % n == 0 ? n : gcd(n, m % n);
}
long long lcm(long long m, long long n) {
  return m * n / gcd(m, n);
}
int main() {
  long long n, a[110], b[110];
  scanf("%lld", &n);
  for (long long i = 0; i < n; i++) {
    scanf("%lld/%lld", &a[i], &b[i]);
  }
  long long final_b = 1, final_a = 0;
  for (long long i = 0; i < n; i++) {
    final_b = lcm(final_b, b[i]);
  }
  for (long long i = 0; i < n; i++) {
    a[i] *= final_b / b[i];
    final_a += a[i];
  }
  long long pre = final_a / final_b;
  final_a = final_a % final_b;

  long long gcd_a_b = gcd(abs(final_a), abs(final_b));
  final_a /= gcd_a_b;
  final_b /= gcd_a_b;

  if (pre) {
    cout << pre;
    if (final_a) cout << " ";
  }
  if (final_a) cout << final_a << "/" << final_b;
  if (final_a == 0 && pre == 0) cout << "0";
  return 0;
}


