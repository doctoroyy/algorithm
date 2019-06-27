#include<iostream>
#include<queue>
using namespace std;
const int maxn = 2e3  + 10;
int turns[maxn * maxn];
int n, m, start, end0, flag = 0;
string maze[maxn];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int vis[maxn][maxn];
int valid(int x, int y) {
  return !(x < 0 || x > n - 1 || y < 0 || y > m - 1 || maze[x][y] == '*');
}
void bfs() {
  queue<int> q;
  q.push(start);
  vis[start / m][start % m] = 1;
  turns[start] = 0;
  while (!q.empty()) {
    int k = q.front();
    q.pop();
    int x = k / m, y = k % m;
    for (int i = 0; i < 4; i++) {
      int nx = x + dir[i][0], ny = y + dir[i][1];
      while (valid(nx, ny)) {
        if (!vis[nx][ny]) {
          if (nx == end0 / m && ny == end0 % m) {
            cout << turns[k] << endl;
            flag = 1;
            return;
          }
          vis[nx][ny] = 1;
          int node = nx * m + ny;
          q.push(node);
          turns[node] = turns[k] + 1;
        }
        nx += dir[i][0], ny += dir[i][1];
      }
    }
  }

}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> maze[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (maze[i][j] == 'S') start = i * m + j;
      if (maze[i][j] == 'T') end0 = i * m + j;
    }
  }
  bfs();
  if (!flag) cout << "troil\n";
  return 0;
}

