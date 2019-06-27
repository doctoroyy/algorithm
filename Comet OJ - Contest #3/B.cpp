#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int m[2][maxn], vis[2][maxn], dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n;
int valid(int x, int y) {
  return x >= 0 && x < 2 && y >= 0 && y < n && m[x][y] == 1;
}
void dfs(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int nx = x + dir[i][0], ny = y + dir[i][1];
    if (!vis[nx][ny] && valid(nx, ny)) {
      vis[nx][ny] = 1;
      dfs(nx, ny);
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> m[i][j]; 
    }
  }
  int cnt = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      if (!vis[i][j] && valid(i, j)) {
        vis[i][j] = 1;
        dfs(i, j);
        cnt++;
      }
    }
  }
  cout << cnt << endl; 
  return 0;
}
