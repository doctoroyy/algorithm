#include<iostream>
#include<cstring>
#include<vector> 
using namespace std;
const int maxn = 1e5 + 10;
int pre[maxn];//pre[i] = j 表示从节点s出发时: 到达节点i时的前驱节点是j 
vector<int> v[maxn];//v[i1] = {j1, j2, j3} 表示节点i1与j1, j2, j3连通 
void dfs(int idx) {
  for (int i = 0; i < v[idx].size(); i++) {
    if (pre[v[idx][i]]) continue;
    pre[v[idx][i]] = idx;
    dfs(v[idx][i]);
  }
} 

int main() { 
  int runs, n, s, a, b;
  cin >> runs;
  while (runs--) {
    memset(pre, 0, sizeof(pre));
    memset(v, 0, sizeof(v));
    cin >> n >> s;
    for (int i = 0; i < n - 1; i++) {
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
//    for (int i = 1; i <= n; i++) {
//      cout << "v[" << i << "] : ";
//      for (int j = 0; j < v[i].size(); j++) {
//        cout << v[i][j] << " ";
//      }
//      cout << endl;
//    }
    dfs(s);
    for (int i = 1; i <= n; i++) {
      if (i == s) {
        cout << "-1 ";
        continue;
      }
      cout << pre[i] << " ";
    }
    cout << endl;
  }
}
