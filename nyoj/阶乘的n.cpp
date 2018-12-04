#include<stdio.h>
int main() {
  int T, m, n, pow, count;
  scanf("%d", &T);
  while (T--) {
    pow = 1, count = 0;
    scanf("%d%d", &n, &m);
    while (m <= n) {
      count += n / m;
      n /= m;
    }
    printf("%d\n", count);
  }
}
