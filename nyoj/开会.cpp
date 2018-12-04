#include<stdio.h>
int main() {
  long long C[30][30];
  for (int i = 1; i <= 20; i++) {
    C[i][i] = C[i][0] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
  }
  int s, n, m[15];
  while (~scanf("%d%d", &s, &n)) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &m[i]);
    }
    for (int i = 0; i < n; i++) {
      printf("%lld ", C[s][m[i]]);
      s -= m[i];
    }
    printf("\n");
  }
}
