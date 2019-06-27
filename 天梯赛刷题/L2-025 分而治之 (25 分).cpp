#include<iostream>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
const int maxn = 1e4 + 10;
int pre[maxn], e[maxn][maxn], mark[maxn];
int find(int x) {
  return x == pre[x] ? x : pre[x] = find(pre[x]);
}
void Union(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) {
    pre[fx] = fy;
  }
}
void init() {
  for (int i = 0; i < maxn; i++) pre[i] = i;
  memset(mark, 0, sizeof(mark));
}
int main() {
  int n, m;
  cin >> n >> m;
  init();
  vector<vector<int> > v(n + 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int k;
  cin >> k;
  while (k--) {
    init();
    int np;
    cin >> np;
    while (np--) {
      int id;
      cin >> id;
      mark[id] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < v[i].size(); j++) {
        if (!mark[i] && !mark[v[i][j]]) {
          Union(i, v[i][j]);
        }
      }
    }
    set<int> sset;
    for (int i = 1; i <= n; i++) {
      sset.insert(find(i));
    }
    if (sset.size() == n) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
