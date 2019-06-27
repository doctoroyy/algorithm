#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e4 + 10;
int n, m;
int a[maxn], buf[maxn], flag = 0;
void dfs(int index, int cnt, int m) {
  if (flag || m < 0) return;
  if (m == 0) {
    flag = 1;
    for (int i = 0; i < cnt; i++) {
      cout << buf[i];
      if (i < cnt - 1) cout << " ";
    }
    return;
  }
  for (int i = index; i < n; i++) {
    if (flag) return;
    buf[cnt] = a[i];
    dfs(i + 1, cnt + 1, m - a[i]);
  }
}
int main() {
  cin >> n >> m;
  int sum = 0; 
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum < m) {
    cout << "No Solution";+
    return 0;
  }
  sort(a, a + n);
  dfs(0, 0, m);
  if (!flag) cout << "No Solution";
  return 0;
}
