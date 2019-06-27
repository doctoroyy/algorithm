#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
#include<queue>
#include<cstring>
#include<set>
using namespace std;
const int maxn = 500 + 10;
vector<int> v[maxn];
int vis[maxn], colors[maxn];
int v0, e, k, n;
int valid(int x) {
  for (int i = 0; i < v[x].size(); i++) {
    if (colors[x] == colors[v[x][i]]) return 0;
  }
  return 1;
}
int main() {
  cin >> v0 >> e >> k;
  for (int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    set<int> sset;
    memset(colors, 0, sizeof(colors));
    for (int j = 1; j <= v0; j++) {
      cin >> colors[j];
      sset.insert(colors[j]);
    }
    if (sset.size() != k) {
      cout << "No";
    } else {
      int flag = 0;
      for (int i = 1; i <= v0; i++) {
        if (!valid(i)) {
          flag = 1;
          break;
        }
      }
      if (flag) {
        cout << "No";
      } else {
        cout << "Yes";
      }
    }
    if (i < n - 1) cout << endl;
  }
  return 0;
}
