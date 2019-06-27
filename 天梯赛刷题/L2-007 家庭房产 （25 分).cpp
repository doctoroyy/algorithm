#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 1e5 + 10;
struct node {
  int id, houses;
  double area;
};
struct family {
  int id, members;
  double ave_houses, ave_area;
};
bool cmp(const family &a, const family &b) {
  if (a.ave_area != b.ave_area) return a.ave_area > b.ave_area;
  return a.id < b.id;
}
int pre[maxn];
int find(int x) {
  return x == pre[x] ? x : pre[x] = find(pre[x]);
}
int union0(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) {
    pre[fx] = fy;
    return 1;
  }
  return 0;
}
int main() {
  for (int i = 0; i < maxn; i++) pre[i] = i;
  set<int> v;
  map<int, node> nodes;
  int n;
  cin >> n;
  while (n--) {
    int id, p1, p2, k, houses;
    double area;
    cin >> id >> p1 >> p2 >> k;
    v.insert(id);
    if (p1 != -1) {
      v.insert(p1);
      union0(p1, id);
    } 
    if (p2 != -1) {
      v.insert(p2);
      union0(p2, id);
    }
    while (k--) {
      int id1;
      cin >> id1;
      v.insert(id1);
      union0(id1, id);
    }
    cin >> houses >> area;
    nodes[id] = node{id, houses, area};
  }
  set<int> sset;
  map<int, vector<int> > mmap;
  for (auto it = v.begin(); it != v.end(); it++) {
    int fa = find(*it);
    mmap[fa].push_back(*it);
    sset.insert(fa);
  }
  cout << sset.size() << endl;
  vector<family> families;
  for (auto it = sset.begin(); it != sset.end(); it++) {
    int fa = find(*it), sz = mmap[fa].size();
    double hs = 0, area = 0;
    for (int i = 0; i < sz; i++) {
      hs += nodes[mmap[fa][i]].houses;
      area += nodes[mmap[fa][i]].area;
    }
    families.push_back(family{mmap[fa][0], sz, hs / sz, area / sz});
  }
  sort(families.begin(), families.end(), cmp);
  
  for (int i = 0; i < families.size(); i++) {
    printf("%04d %d %.3lf %.3lf", families[i].id, families[i].members, families[i].ave_houses, families[i].ave_area);
    if (i < families.size() - 1) puts("");
  }
  return 0;
}
