#include<iostream>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    int flag = 0;
    for (long long i = l; i <= r; i++) {
      if (i % 192 == 1) {
        l = i;
        flag = 1;
        break;
      }
    }
    long long  n = (r - l) / 192 + flag;
    
    printf("%lld\n", n * (2 * l + (n - 1) * 192) / 2);
  }
  return 0;
}

