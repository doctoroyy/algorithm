
#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;

const int maxN = 1e5+10;
vector<int> color(maxN,0) , pre(maxN,0), adj[maxN];

vector<vector<int> > res;

void buildCycle(int start, int end) {
  vector<int> cycle;
  cycle.push_back(start);
  for (int cur = end; cur != start; cur = pre[cur]) {
    cycle.push_back(cur);
  }
  cycle.push_back(start);

  cycle.reserve(cycle.size());
//  cout << cycle.size() << endl;
  res.push_back(cycle);
}

void dfs(int source) {
//  cout << "endter!" << endl;
  color[source] = 1;
  for (int &target: adj[source]) {
    pre[target] = source;
    if (color[target] == 0) {
      dfs(target);
    } else if (color[target] == 1) {
      buildCycle(source, target);
    }
  }
  color[source] = 2;
}

int main() {
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  

  for (int i = 1; i <= n; i++) {
    if (color[i] == 0) {
      dfs(i);
    }
  }

  for (int i = 0; i < res.size(); i++) {
    cout << res[i].size() << endl;
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}