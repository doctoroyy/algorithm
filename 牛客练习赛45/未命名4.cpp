#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e4 + 10;
int a[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
      sum += a[i];
    }
    sort(a, a + n);
    printf("%lld\n", sum - a[n - 1]);
  }
  return 0;
}

