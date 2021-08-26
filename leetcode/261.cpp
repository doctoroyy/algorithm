// https://leetcode-cn.com/problems/graph-valid-tree/

#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;

// Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
// Output: true

// Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
// Output: false

const int maxN = 2010;
int pre[maxN];

int find(int x) {
  return x == pre[x] ? x : pre[x] = find(pre[x]);
}

void _union(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) {
    pre[y] = fx;
  }
}
class Solution {
  public:
    bool validTree(int n, vector<vector<int> >& edges) {
      for (int i = 0; i < n; i++) {
        pre[i] = i;
      }
      for (int i = 0; i < edges.size(); i++) {
        int a = edges[i][0], b = edges[i][1];
        if (find(a) == find(b)) {
          cout << 'enter' << endl;
          return false;
        }
        _union(a, b);
      }
      set<int> preSet;
      for (int i = 0; i < n; i++) {
        int res = find(i);
        cout << i << "'s pre is " << res << endl;
        preSet.insert(res);
      }
      return preSet.size() == 1;
    }
};

int main() {
  int n;
  cin >> n;
  bool flag = true;
  for (int i = 0; i < n; i++) pre[i] = i;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (find(a) == find(b)) {
      cout << 'enter' << endl;
      flag = false;
    }
    _union(a, b);
  }
  set<int> preSet;
  for (int i = 0; i < n; i++) {
    int res = find(i);
    cout << i << "'s pre is " << res << endl;
    preSet.insert(find(i));
  }
  cout << (preSet.size() == 1) << endl;
  return 0;
}