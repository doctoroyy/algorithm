#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 1e5 + 10;
long long rank0[maxn];
int vis[maxn];
long long n, k, maxNum = -1, start, idx = 1;
void bfs(vector<vector<int> > v) {
  queue<int> q;
  q.push(start);
  rank0[start] = 0;
  while (!q.empty()) {
    int k = q.front();
    q.pop();
    for (int i = 0; i < v[k].size(); i++) {
      q.push(v[k][i]);
      rank0[v[k][i]] = rank0[k] + 1;
      if (rank0[v[k][i]] > maxNum) {
        maxNum = rank0[v[k][i]];
        idx = v[k][i];
      }
    }
  }
}
int main() {
  cin >> n;
  vector<vector<int> > v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> k;
    while (k--) {
      int num;
      cin >> num;
      v[i].push_back(num);
      vis[num] = 1;
    }
  }
  //坑点：入口没有说明，需要判断
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      start = i;
      break;
    }
  }
  bfs(v);
  cout << idx;
  return 0;
}
