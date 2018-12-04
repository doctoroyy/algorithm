
//DFS求连通块
//如果两个字符'@'相邻（横竖斜8个方向）,则它们属于一个连通块 
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100 + 10;
char pic[maxn][maxn];
int m, n, vis[maxn][maxn];
void dfs(int r, int c, int id) {
  if (r < 0 || r >= m || c < 0 || c >= n) return; //越界
  if (vis[r][c] > 0 || pic[r][c] != '@') return; //不是'@'格子或者已经访问过
  vis[r][c] = id;//连通分量编号
  for (int dr = -1; dr <= 1; dr++) {//访问8个方向 
    for (int dc = -1; dc <= 1; dc++) {
      if (dr != 0 || dc != 0) {
        dfs(r+dr, c+dc, id);
      }
    }
  } 
}
int main() {
  while (cin >> m >> n) {
    
    for (int i = 0; i < m; i++) cin >> pic[i];
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (vis[i][j] == 0 && pic[i][j] == '@') {
          dfs(i, j, ++cnt);
        }
      }
    }
    cout << cnt << endl;
  }
}
