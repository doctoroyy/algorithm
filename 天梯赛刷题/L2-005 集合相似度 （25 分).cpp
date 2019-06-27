#include<iostream>
#include<set> 
#include<vector>
using namespace std;
int main() {
  int n, m, k;
  scanf("%d", &n);
  vector<set<int> > v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &m);
    while (m--) {
      int num;
      scanf("%d", &num);
      v[i].insert(num);
    }
  }
  cin >> k;
  while (k--) {
    int i, j;
    cin >> i >> j;
    i -= 1, j -= 1;
    int nc = 0, nt = v[j].size();
    for (auto it = v[i].begin(); it != v[i].end(); it++) {
      if (v[j].find(*it) == v[j].end()) nt++;//如果j集合中没有找到i的元素 
      else nc++; 
    }
    printf("%.2lf%\n", 1.0 * nc / nt * 100);
  }
  return 0;
}

