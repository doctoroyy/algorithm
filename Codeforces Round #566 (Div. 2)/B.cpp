#include<iostream>
#include<vector>
using namespace std;
const int maxn = 500 + 10;
string maze[maxn];
int h, w;
struct Node {
  int x , y;
};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int vis[maxn][maxn];
int valid(int x, int y) {
  return x >= 0 && x < h && y >= 0 && y < w && maze[x][y] == '*';
}

void dfs(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int nx = x + dir[i][0], ny = y + dir[i][1];
    if (valid(nx, ny) && !vis[nx][ny]) {
      vis[nx][ny] = 1;
      dfs(nx, ny);
    }
  }
}
int check(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    int nx = x + dir[i][0], ny = y + dir[i][1];
    if (valid(nx, ny)) {
      cnt++;
    }
  }
  return cnt == 4;
}
int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) cin >> maze[i];
  int cnt = 0;
  vector<Node> v;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (maze[i][j] == '*') v.push_back(Node {i, j});
      if (!vis[i][j] && valid(i, j)) {
        vis[i][j] = 1;
        dfs(i, j);
        cnt++;
      }
    }
  }
  if (cnt != 1) {
    cout << "NO\n";
  } else {
    int tmp = 0;
    for (int i = 0; i < v.size(); i++) {
      int x = v[i].x, y = v[i].y;
      if (check(x, y)) tmp++;
    }
    if (tmp == 1) {
      cout << "YES\n"; 
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
