#include<iostream>
#include<map>
using namespace std;
const int maxn = 20000 + 10;
int pre[maxn];
map<string, int> mmap; 
int find(int x) {
  return x == pre[x] ? x : x = find(pre[x]);
} 
void Union(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) pre[fx] = fy;
}
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;
    mmap[name] = i;
    pre[i] = i;
  }
  while (m--) {
    int opt;
    string x, y;
    cin >> opt >> x >> y;
    int x0 = mmap[x], y0 = mmap[y];
    if (opt == 1) {
      Union(x0, y0);
    } else {
      if (find(x0) == find(y0)) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
  return 0;
}

