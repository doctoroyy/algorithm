#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int dir[4][2]= { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
int w, h, n;
double x[1010], y[1010], r[1010];
int flag;
double dis(double x0, double y0, double x1, double y1) {
  return sqrt((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1));
}
int valid(int x1, int y1) {
  for (int i = 0; i < n; i++) {
    if (dis(x1, y1, x[i], y[i]) <= r[i]) return false;
  }
  return true;
}
void dfs(int x, int y) {
  if (x < 0 || x > w || y < 0 || y > h) {
    return;
  }
  if (x == w) {
    flag = true;
    return;
  }
  for (int i = 0; i < 4; i++) {
    if (valid(x + dir[i][0], y + dir[i][1])) {
      //cout << "*" << endl;
      dfs(x + dir[i][0], y + dir[i][1]);
    }
  }
}

int main() {
  //cout << dis(0, 0, 1, 1) << endl;
  int t;
  cin >> t;
  while (t--) {
    cin >> w >> h >> n;
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i] >> r[i];
    }
    flag = false;
    dfs(0, 0);
    cout << flag << endl;
  }
}
