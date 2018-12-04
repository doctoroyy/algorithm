#include<bits/stdc++.h>
using namespace std;
int main() {
  long long runs, n, a;
  scanf("%lld", &runs);
  while (runs--) {
    scanf("%lld%lld", &n, &a);
    if (n > 2 || n == 0) {
      printf("-1 -1\n");
      continue;
    }
    if (n == 1) {
      printf("%lld %lld\n", 1, a + 1);
    } else {
      long long b = 1, c = 2, flag = 0;
      for (b = 1; b <= 1000000000; b++) {
        for (c = b + 1; c <= 1000000000; c++) {
          if ((c + b) * (c - b) > a * a) break;
          if ((c + b) * (c - b) == a * a) {
            printf("%lld %lld\n", b, c);
            flag = 1;
//            break;
          }
//          if (flag) break;
        }
      }
    }
  }
  return 0;
}

// a^2 + b^2 = c^2
//3 = c - b
//a^2 = c^2 - b^2 = (c+b)(c-b)   c > b
//a^n + b^n = c^n
//3^2 + 4^2 = 5^2
