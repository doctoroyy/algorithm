#include<stdio.h>
long long a[15] = {0, 1};
long long counter(long long num) {
  if (num == 0) return 0;
  int temp = num, mod = 1, bit = 1;
  while (temp >= 10) {
    mod *= 10;
    temp /= 10;
    bit++;
  }
  int l = num / mod, r = num % mod, sum = 0;
  sum += l * a[bit-1];
  if (l > 1) sum += mod;
  else if (l == 1) sum += r + 1;
  sum += counter(r);
  return sum;
}
void swap(long long &a, long long &b) {
  long long t = a;
  a = b;
  b = t;
}
int main() {
  long long k = 1;
  for (int i = 2; i <= 12; i++) {
    k *= 10;
    a[i] = a[i-1] * 10 + k;
  }
  long long a, b;
  while (scanf("%lld%lld", &a, &b), a || b) {
    if (a < b) swap(a, b);
    printf("%lld\n", counter(b) - counter(a-1));
  }
}
