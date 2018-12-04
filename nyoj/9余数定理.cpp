#include<stdio.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b, t;
    scanf("%lld%lld", &a, &b);
    if (a == 0 || b == 0) {
      printf("0\n");
      continue;
    }
    t = (a%9)*(b%9)%9;
    if (t == 0) printf("9\n");
    else {
      printf("%lld\n", t);
    }
  }
}
