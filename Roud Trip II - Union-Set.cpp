#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;

const int maxN = 1e5+10;

int pre[maxN];
int pre2[maxN];

vector<vector<int> > res;
// const edges = [[1, 2], [2, 3], [3, 1], [1, 4], [4, 6], [6, 5], [5, 4]];


void buildCycle(int start, int end) {
  vector<int> cycle;
  cycle.push_back(start);
  for (int cur = end; cur != start; cur = pre2[cur]) {
    if (cur == -1) {
      return;
    }
    cycle.push_back(cur);
  }
  cycle.push_back(start);

  vector<int> reversedCycle;

  for (int i = cycle.size() - 1; i >= 0; i--) {
    reversedCycle.push_back(cycle[i]);
  }

  res.push_back(reversedCycle);
}

int find(int x) {
  // cout << "find" << x << endl;
  return x == pre[x] ? x : pre[x] = find(pre[x]); // 路径压缩，边查找边压缩
}

// 5 7
// 1 5
// 1 2
// 1 3
// 3 4
// 4 2
// 2 5
// 4 1

void _union(int x, int y) {
  if (pre2[y] == -1) pre2[y] = x;
  
  int fx = find(x), fy = find(y);
  if (fx != fy) {
    pre[fx] = fy;
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i <= n; i++) {
    pre[i] = i;
    pre2[i] = -1;
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    if (find(a) == find(b) ) {
      buildCycle(b, a);
      continue;
    }
    _union(a, b);
  }

  if (res.size() != 0) {
    for (int i = 0; i < res.size(); i++) {
      cout << res[i].size() << endl;
      for (int j = 0; j < res[i].size(); j++) {
        cout << res[i][j] << " ";
      }
      cout << endl;
    }
  } else {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}