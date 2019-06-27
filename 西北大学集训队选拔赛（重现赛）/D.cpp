#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 1e6 + 10;
int lowbit(int x) {
  return x & (-x);
}
int sum[maxn];
int n, m, k, l, r;


void update(int index, int val) {
  for (int i = index; i <= n; i += lowbit(i))
    sum[i] += val;
}

int getSum(int index) {
  int ans = 0;
  for (int i = index; i; i -= lowbit(i))
    ans += sum[i];
  return ans;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) update(i, i);
  while (m--) {
    scanf("%d%d%d", &k, &l, &r);
    if (k == 2) {
      printf("%d\n", getSum(r) - getSum(l - 1));
    } else {
      for (int i = l, j = 1; i <= r, j <= r - l + 1; i++, j++) {
        update(i, j - (getSum(i) - getSum(i - 1)));
      }
    }
  }
  return 0;
}
