#include<stdio.h>
int f(int n, int m, int &x, int &y) {
  if (m == 0) {
    x = 1; 
    y = 0; 
    return n;
  }
  int a = f(m, n % m, x, y);
  int t = x; 
  x = y;
  y = t - n / m * y;
  return a;
}
int main() {
  int m, n, x, y;
  while (~scanf("%d%d", &m, &n)) {
    f(m, n, x, y);
    printf("%d %d\n", x, y);
  }
}
