#include<iostream>
using namespace std;
const int maxn = 1e6 + 10;
int pre[maxn];
int find(int x) {
  return x == pre[x] ? x : pre[x] = find(pre[x]);
}
void Union(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) pre[fx] = fy;
}
int main() {
  for (int i = 0; i < maxn; i++) pre[i] = i;
  int n, m, k;
  cin >> n >> m >> k;
  while (k--) {
    int a, b;
    cin >> a >> b;
    Union(a, b);
  }
  int cnt = 0;
  for (int i = 1; i <= m * n; i++) {
    if (find(i) == i) cnt++;
  }
  cout << cnt << endl;
  return 0;
}

