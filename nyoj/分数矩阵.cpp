#include<stdio.h>
double a[50100] = {0, 1};
int main() {
  double s = 1;
  for (int i = 2; i < 50100; i++) {
    s += 2 * 1.0 / i;
    a[i] = a[i-1] + s;
  }
  int n;
  while (scanf("%d", &n), n) {
    printf("%.2lf\n", a[n]);
  }
}
