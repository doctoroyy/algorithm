#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 110;
long long a[maxn];
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long n, k;
    scanf("%lld%lld", &n, &k);
    long long min_ai = 0x3f3f3f3f,max_ai = -1;
    for (int i = 0; i < n; i++) {
      scanf("%lld", a + i);
      min_ai = min(min_ai, a[i]);
      max_ai = max(max_ai, a[i]);
    }
    if (abs(min_ai + k - max_ai) <= k) {
      printf("%lld\n", min_ai + k);
    } else {
      puts("-1");
    }
  }
  return 0;
}

