#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1e5 + 10;  
int n, m;

struct Node {
  long long di, pi;
}; 
bool cmp(const Node &a, const Node &b) {
  if (a.di == b.di) return a.pi < b.pi;
  return a.di < b.di; 
}
int bin_search(long long key, vector<Node> v) {
  int l = 0, r = n - 1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (v[mid].di > key) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return l;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  vector<Node> v;
  for (int i = 0; i < n; i++) {
    long long di, pi;
    cin >> di >> pi;
    v.push_back(Node{di, pi});
  }
  sort(v.begin(), v.end(), cmp);
  while (m--) {
    int ai;
    cin >> ai;
    //二分查找第一个小于等于ai的 
    int index = bin_search(ai, v) - 1;
    cout <<  v[index].pi << endl; 
  }
  return 0;
}
