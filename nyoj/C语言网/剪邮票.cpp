#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

set<vector<int> > sset;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int vis[4][5];
int valid(int x, int y) {
  if (x < 1 || x > 3 || y < 1 || y > 4) return 0;
  return 1;
}

void dfs(int x, int y, int cnt, vector<int> &q) {
  if (cnt == 5) {
    vector<int> tmp = q;
    
    sort(tmp.begin(), tmp.end());
    sset.insert(tmp);
    for (int i = 0; i < tmp.size(); i++) {
      cout << tmp[i] << " ";
    }
    cout << endl;
    return;
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dir[i][0], ny = y + dir[i][1];
    if (valid(nx, ny) && vis[nx][ny] == 0) {
      vis[nx][ny] = 1;
      q.push_back((nx - 1) * 4 + ny);
      dfs(nx, ny, cnt + 1, q);
      vis[nx][ny] = 0;

      q.pop_back();
    }
  }
}
int main() {
//  for (int i = 1; i <= 3; i++) {
//    for (int j = 1; j <= 4; j++) {
      memset(vis, 0, sizeof(vis));
      vis[1][1] = 1;
      vector<int> q;
      q.push_back(1);
      dfs(1, 1, 1, q);
//    }
//  }
  
  cout << sset.size() << endl;
  return 0;
}

