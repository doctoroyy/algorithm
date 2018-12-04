#include<stdio.h>
int f(int m, int n) {
  if (m < n) return 0;
  if (n == 1 || m == n) return 1;
  else return f(m - 1, n - 1) + f(m - n, n);
}
int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &m, &n);
    printf("%d\n", f(m, n));
  }
}
