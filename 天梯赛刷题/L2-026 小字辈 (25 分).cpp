#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1e5 + 10;
int rankk[maxn], root, maxRnk = -1;
int main() {
  int n;
  cin >> n;
  vector<vector<int> > v(n + 1);
  vector<vector<int> > r(n + 1);
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    if (p == -1) {
      root = i;
      continue;
    }
    v[p].push_back(i);
  }
  if (n == 1) {
    cout << 1 << endl;
    cout << root; 
    return 0;
  }
  queue<int> q;
  q.push(root);
  rankk[root] = 1;
  r[rankk[root]].push_back(root);
  while (!q.empty()) {
    int k = q.front();
    q.pop();
    for (int i = 0; i < v[k].size(); i++) {
      q.push(v[k][i]);
      rankk[v[k][i]] = rankk[k] + 1;
      maxRnk = max(maxRnk, rankk[v[k][i]]);
      r[rankk[v[k][i]]].push_back(v[k][i]);
    }
  }
  cout << maxRnk << endl;
  for (int i = 0; i < r[maxRnk].size(); i++) {
    cout << r[maxRnk][i];
    if (i < r[maxRnk].size() - 1) cout << " ";
  }
  return 0;
}

