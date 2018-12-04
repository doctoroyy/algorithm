#include<stdio.h>
const int mod = 10003;
long long pow(int n, int k) {
  n %= mod;
  long long ans = 1, p = n;
  while (k) {
    if (k&1) ans = (ans * p) % mod;
    p = (p * p) % mod;
    k >>= 1;
  }
  return ans;
}
int main() {
  int n, p, tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d%d", &n, &p);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      ans = (ans + pow(i, p)) % mod;
    }
    printf("%d\n", ans);
  }
}
