#include<stdio.h>
int gcd(int m, int n) {
  if (m % n == 0) return n;
  return gcd(n, m%n);
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    int cnt = 0;
    for (int i = 1; i < n; i++) {
      if (gcd(i, n) == 1) cnt++; 
    }
    printf("%d\n", cnt);
  }
}
