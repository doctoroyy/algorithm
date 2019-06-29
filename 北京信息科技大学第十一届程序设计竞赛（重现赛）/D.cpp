#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, start;
const int maxn = 40;
string maze[maxn];
int steps[maxn * maxn], vis[maxn * maxn];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != '*';
}
vector<int> v;
void bfs() {
  queue<int> q;
  q.push(start);
  vis[start] = 1;
  steps[start] = 0;
  while (!q.empty()) {
    int cur = q.front();
    int x = cur / m, y = cur % m;
    q.pop();
    
    if (maze[x][y] == 'e') continue;
    for (int i = 0; i < 4; i++) {
      int nx = x + dir[i][0], ny = y + dir[i][1];
      int next = nx * m + ny;
      if (valid(nx, ny) && !vis[next]) {
//        cout << "pos: "<< nx << " " << ny  <<  " ÐÎ×´ " << maze[nx][ny] << endl;
        vis[next] = 1;
        q.push(next);
        if (maze[nx][ny] == 'e') {
          v.push_back(next);
        }
        steps[next] = steps[cur] + 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> maze[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (maze[i][j] == 'k') {
        start = i * m + j;
      }
    }
  }
  v.clear();
  bfs();
  int _min = 0x3f3f3f3f;
  for (int i = 0; i < v.size(); i++) {
    _min = min(steps[v[i]], _min);
  }
  if (v.size() == 0) cout << "-1\n";
  else cout <<v.size() << " " <<  _min << endl;
  return 0;
}
