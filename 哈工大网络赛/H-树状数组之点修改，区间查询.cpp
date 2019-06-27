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
int runs, n, a, b;

void update(int index, int val) {
  for (int i = index; i <= maxn; i += lowbit(i))
    sum[i] += val;
}

int getSum(int index) {
  int ans = 0;
  for (int i = index; i; i -= lowbit(i))
    ans += sum[i];
  return ans;
}

int main() {
//  for (int i = 1; i <= maxn; i++) update(i, 0);
  for (int i = 2; i <= maxn; i++) {
    for (int j = i; j <= maxn; j += i) {
      int flag = (getSum(j) - getSum(j - 1)) == 1 ? -1 : 1;

      update(j, flag);
    }
  }
  cin >> runs;
  while (runs--) {
    cin >> n >> a >> b;
    cout << getSum(b) - getSum(a - 1) << endl;
  }
  return 0;
}
