#include<iostream>
using namespace std;
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 1e5 + 10;
int sum[maxn], a[maxn];

int n, q, l, r;

int lowbit(int x) {
  return x & (-x);
}
void update(int index, int val) {
  for (int i = index; i > 0; i -= lowbit(i))
    sum[i] += val;
}
int ask_point(int index) {
  int ans = a[index];
  for (int i = index; i <= n; i += lowbit(i))
    ans += sum[i];
  return ans;
}


int main() {
  ios::sync_with_stdio(false);
  cin >> n >> q;
  while (q--) {
    cin >> l >> r;
    update(r, 1);
    update(l - 1, -1);
  }
  for (int i = 1; i <= n; i++) {
    cout << getSum(i) << " ";
  }
  return 0;
}

