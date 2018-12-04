#include <stdio.h>
long long bar(int n, int r) {
  if (n == 0) return 0;
  return r * bar(n / 10, r) + n % 10;
}
bool exits_num(int num, int ary) {
  while (num) {
    if (num % 10 == ary) return true;
    num /= 10;
  }
  return false;
}
int main() {
  int a, b, c, d;
  while(~scanf("%d%d%d", &a, &b, &c)){
    int k = 0;
    for (int i = 2; i <= 16; i++) {
      if (!exits_num(a, i) && !exits_num(b, i) && !exits_num(c, i)) {
        if (bar(a, i) * bar(b, i) == bar(c, i)) {
          k = i;
          break;
        }
      }
    }
    printf("%d\n", k);
  }
}

