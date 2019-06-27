#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn], n, k;
bool cmp(int a, int b) {
  return to_string(a) < to_string(b);
}
void init() {
  for (int i = 0; i < maxn; i++) a[i] = i + 1;
  sort(a, a + maxn, cmp);
}
int main() {
  int t;
  init();
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    int idx = 0, cnt = 0;
    while (cnt < k) {
      if (a[idx] <= n) cnt++;
      idx++;
    }
    printf("%d\n", a[idx - 1]);
  }
  return 0;
}

