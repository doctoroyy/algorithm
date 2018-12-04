#include<stdio.h>
#include<string.h>
const int M = 50000;
int a[M+10];
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    memset(a, 0, sizeof(a));
    int sto, sum = 0, max;
    for (int i = 0; i < n; i++) {
      scanf("%d", &sto);
      a[sto]++;
    }
    for (int i = 0; i <= m; i++) sum += a[i];
    max = sum;
    for (int i = m + 1; i < M + 10; i++) {
      sum = sum + a[i] - a[i - m - 1];
      if (sum > max) max = sum;
    }
    printf("%d\n", max);
  }
}
