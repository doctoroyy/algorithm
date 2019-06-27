#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1e7 + 10;
struct node {
  int tags;
  double ave;
  string name;
};
bool cmp(const node &a, const node &b) {
  if (a.tags != b.tags) return a.tags > b.tags;
  return a.ave < b.ave;
}
int main() {
  string name;
  int n, k, tag_id;
  cin >> n;
  vector<set<int> > v(n);
  vector<node> v1;
  for (int i = 0; i < n; i++) {
    cin >> name >> k;
    for (int j = 0; j < k; j++) {
      cin >> tag_id;
      v[i].insert(tag_id);
    }
    int tags = v[i].size();
    v1.push_back(node {tags, (double) k / tags, name});
  }
  sort(v1.begin(), v1.end(), cmp);
  if (v1.size() < 3) {
    for (int i = 0; i < 3 - v1.size(); i++) v1.push_back(node {0, 0, "-"});
  }
  for (int i = 0; i < 3; i++) {
    cout << v1[i].name;
    if (i < 2) cout << " ";
  }
  return 0;
}
