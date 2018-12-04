#include<stdio.h>
const int mod = 10003;
int pow(int n, int k) {
  int res = 1, t = n;
  while (k) {
    if (k&1) res = (res * t) % mod;
    t = (t * t) % mod;
    k >>= 1;
  }
  return res;
}
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", pow(n, n-2));
  }
  return 0;
}
