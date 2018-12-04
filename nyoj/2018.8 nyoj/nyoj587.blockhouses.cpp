#include<iostream>
using namespace std;
char g[10][10];
int maxn, n;
int valid(int x, int y) {
  for (int i = x - 1; i >= 0; i--) {
    if (g[i][y] == '0') return 0;
    if (g[i][y] == 'X') break;
  }
  for (int j = y - 1; j >= 0; j--) {
    if (g[x][j] == '0') return 0;
    if (g[x][j] == 'X') break;
  }
  return 1;
}
void dfs(int pos, int cnt) {
  if (pos == n * n) {
    if (cnt > maxn) {
      maxn = cnt;
    }
    return;
  } else {
    int x = pos / n, y = pos % n;
    if (valid(x, y) && g[x][y] == '.') {
      g[x][y] = '0';
      dfs(pos + 1, cnt + 1);
      g[x][y] = '.';
    }
    dfs(pos + 1, cnt);
  }
}
int main() {
  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> g[i];
    }
    maxn = 0;
    dfs(0, 0);
    cout << maxn << endl;
  }
  return 0;
}
