#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 110;
int pre[maxn], v[maxn][maxn];
int find(int x) {
  return x == pre[x] ? x : pre[x] = find(pre[x]);
}
void Union(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) pre[fx] = fy;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i <= maxn; i++) pre[i] = i;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (c == 1) Union(a, b);
    v[a][b] = c;
    v[b][a] = c;
  }
  while (k--) {
    int x, y;
    cin >> x >> y;
    if (find(x) == find(y) && v[x][y] != -1) {
      cout << "No problem\n";
    }
    if (find(x) != find(y) && v[x][y] != -1) {
      cout << "OK\n";
    }
    if (find(x) == find(y) && v[x][y] == -1) {
      cout << "OK but...\n";
    }
    if (find(x) != find(y) && v[x][y] == -1) {
      cout << "No way\n";
    }
  }
  return 0;
}

