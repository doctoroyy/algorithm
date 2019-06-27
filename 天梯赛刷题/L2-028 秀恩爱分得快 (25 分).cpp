#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const int maxn = 1e3 + 10;
int rel[maxn][maxn];
int g[maxn];
struct node {
  int a, b, c;
};
bool cmp(node x, node y) {
  if (abs(x.c) == abs(y.c)) return abs(x.b) < abs(y.b);
  return abs(x.c) > abs(y.c);
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    vector<int> v;
    while (k--) {
      int num;
      cin >> num;
      v.push_back(num);
      g[abs(num)] = num < 0;
    }
    for (int k = 0; k < v.size() - 1; k++) {
      for (int j = k + 1; j < v.size(); j++) {
        if (g[abs(v[k])] != g[abs(v[j])]) {
          rel[abs(v[k])][abs(v[j])]++;
          rel[abs(v[j])][abs(v[k])]++;
        }
      }
    }
  }
  int a, b;
  cin >> a >> b;
  vector<node> v1, v2;
  for (int i = 0; i < n; i++) {
    v1.push_back(node {a, g[i] == 1 ? -i : i, rel[abs(a)][i]});
    v2.push_back(node {b, g[i] == 1 ? -i : i, rel[abs(b)][i]});
  }

  sort(v1.begin(), v1.end(), cmp);
  sort(v2.begin(), v2.end(), cmp);
  for (int i = 0; i < v1.size(); i++) {
    printf("(%d, %d) %d\n", v1[i].a, v1[i].b, v1[i].c);
  }
  cout << endl;
  for (int i = 0; i < v2.size(); i++) {
    printf("(%d, %d) %d\n", v2[i].a, v2[i].b, v2[i].c);
  }
  return 0;
}
