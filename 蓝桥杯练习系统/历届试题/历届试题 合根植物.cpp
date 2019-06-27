#include<iostream>
using namespace std;
const int maxn = 5e3 + 10;
int m, n, k;
int e[maxn][maxn], vis[maxn][maxn];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int valid(int x, int y) {
  return x < m && x >= 0 && y < n && y >= 0;
}
void dfs(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int nx = x + dir[i][0], ny = y + dir[i][1];
    if (!vis[nx][ny] && valid(nx, ny) && e[nx * n + ny][x * n + y]) {
      vis[nx][ny] = 1;
      dfs(nx, ny);
    }
  }
}
int main() {
//  cin >> m >> n >> k;
  scanf("%d%d%d%", &m, &n, &k);
  while (k--) {
    int a, b;
//    cin >> a >> b;
    scanf("%d%d", &a, &b);
    a -= 1;
    b -= 1;
    e[a][b] = 1;
    e[b][a] = 1;
  }
  int cnt = 0;
  for (int i = 0; i < m * n; i++) {
    int x = i / n, y = i % n;
    if (!vis[x][y]) {
      vis[x][y] = 1;
      dfs(x, y);
      cnt++;
    }
  }
  printf("%d\n", cnt);
//  cout << cnt << endl;
  return 0;
}
