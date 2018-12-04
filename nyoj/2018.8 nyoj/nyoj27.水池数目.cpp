#include<iostream>
using namespace std;
const int maxn = 100;
int pool[maxn + 10][maxn + 10], m, n;
int dir[4][4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int cnt;
void dfs(int x, int y) {
  if (x < 0 || x > m || y < 0 || y > n) return;
  if (pool[x][y] == 0) return;
  for (int i = 0; i < 4; i++) {
    pool[x][y] = 0;
    dfs(x + dir[i][0], y + dir[i][1]);
  }
}
int main() {
  int runs;
  cin >> runs;
  while (runs--) {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> pool[i][j];
      }
    }
    cnt = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (pool[i][j] == 1) {
          dfs(i, j);
          cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
