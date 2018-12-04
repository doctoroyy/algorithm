#include<stdio.h>
#include<string.h>
int main() {
//  1
//  1  1
//  1  2  1
//  1  3  3  1
//  1  4  6  4  1
//  1  5 10 10 5  1 
  long long C[30][30], D[30] = {0, 0, 1};
  memset(C, 0, sizeof(C));
  for (int i = 1; i <= 20; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
  }
//  错排数递推公式 
//  D(n) = (n-1) [D(n-2) + D(n-1)] (D(1) = 0, D(2) = 1).  
  for (int i = 3; i <= 20; i++) {
    D[i] = (i-1)*(D[i-1] + D[i-2]);
  }
  long long n, m;
  while (~scanf("%lld%lld", &n, &m)) {
    printf("%lld\n", C[n][n-m] * D[m]);
  }
}
