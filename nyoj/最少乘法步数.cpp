#include<stdio.h>
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int cnt = 0;
    while (n > 1) {
      if (n & 1) cnt++;
      cnt++;
      n >>= 1;
    }
    printf("%d\n", cnt);
  }
}
