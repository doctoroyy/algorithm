#include<iostream>
#include<algorithm>
using namespace std;
const int N = 500, maxn = N * (N - 1) / 2 + 10;
int n, k;
long long res = 0, buf[maxn], a[maxn], flag = 0;
bool cmp(long long a, long long b) {
  return a > b;
}
void dfs(int index, int cnt) {
  if (flag > k) return;
  if (cnt == 2) {
    flag++;
    for (int i = 0; i < cnt; i++) {
//      cout << buf[i] << " ";
      res += buf[i];
    }
//    cout << endl;
    return;
  }
  for (int i = index; i < n; i++) {
    buf[index] = a[i];
    if (flag < k) dfs(i + 1, cnt + 1);
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
//  sort(a, a + n, cmp);
//  dfs(0, 0);
  int index = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      buf[index++] = a[i] + a[j];
    }
  }
  sort(buf, buf + index, cmp);
  for (int i = 0; i < k; i++) {
    res += buf[i];
  }
  cout << res << endl;
  return 0;
}

