#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int dir[4] = {-1, 1, -4, 4};
int vis[13], cnt;
int ele_in_buff(int ele, vector<int> v) {//判断元素是否在容器中
  for (int i = 0; i < v.size(); i++) {
    if (ele == v[i]) return 1;
  }
  return 0;
}
void dfs(int dot, vector<int> buff) {
  if (dot < 1 || dot > 12) return;
  if (cnt == 5) return;
  for (int i = 0; i < 4; i++) {
    if (dir[i] == 1 && (dot == 4 || dot == 8)) continue; // 4, 8 不能往右走 
    if (dir[i] == -1 && (dot == 5 || dot == 9)) continue; // 5, 9 不能往左走 
    int nx = dot + dir[i];
    if (vis[nx] == 0 && ele_in_buff(nx, buff)) {
      vis[nx] = 1;
      cnt++;
      dfs(nx, buff);
    }
  }
}
int main() {
  int ans = 0;
  for (int a = 1; a <= 8; a++) {
    for (int b = a + 1; b <= 9; b++) {
      for (int c = b + 1; c <= 10; c++) {
        for (int d = c + 1; d <= 11; d++) {
          for (int e = d + 1; e <= 12; e++) {
            vector<int> buff;
            buff.push_back(a);
            buff.push_back(b);
            buff.push_back(c);
            buff.push_back(d);
            buff.push_back(e);
            memset(vis, 0, sizeof(vis));
            cnt = 1;
            vis[a] = 1;
            dfs(a, buff);
            if (cnt == 5) ans++; 
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
