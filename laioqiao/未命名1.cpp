#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int dir[4][2] = {{0,  1},
  {0,  -1},
  {1,  0},
  {-1, 0} //其实没必要往上走了 
};
int w, h, n;
double x[1010], y[1010], r[1010];
int vis[1010][1010];
int flag;

double dis(double x0, double y0, double x1, double y1) {
  return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

int valid(int x1, int y1) {
  if (x1 < 0 || x1 > w || y1 < 0 || y1 > h) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    if (dis(x1, y1, x[i], y[i]) <= r[i]) return false;
  }
  return true;
}

void dfs(int x, int y) {
  if (x == w) {
    flag = true;
    return;
  }
  for (int i = 0; i < 3; i++) {
    if (valid(x + dir[i][0], y + dir[i][1]) && vis[x + dir[i][0]][y + dir[i][1]] == 0) {
      vis[x + dir[i][0]][y + dir[i][1]] = 1;
      dfs(x + dir[i][0], y + dir[i][1]);
      vis[x + dir[i][0]][y + dir[i][1]] = 0;
    }
  }
}

int main() {
  //cout << dis(0, 0, 1, 1) << endl;
  int t;
  cin >> t;
  while (t--) {
    memset(vis, 0, sizeof(vis));
    cin >> w >> h >> n;

    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i] >> r[i];
    }
    flag = false;
    for (int i = 0; i <= h; i++) {
      dfs(0, i);
      if (flag) break; 
    }
    cout << flag << endl;
  }
}
