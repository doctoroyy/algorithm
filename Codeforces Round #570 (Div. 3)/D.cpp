#include<iostream>
#include<set>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], b[maxn], vis[maxn];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(vis, 0, sizeof(vis));

    int n;
    scanf("%d", &n);
    set<int> sset;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      b[a[i]]++;
      sset.insert(a[i]);
    }
    vector<int> v;
    for (auto it : sset) {
      v.push_back(b[it]);
    }
    sort(v.begin(), v.end());
    int cnt = 0, len = v.size(), pre = v[len - 1];
    for (int i = len - 1; i >= 0; i--) {
      if (!vis[v[i]]) {
        vis[v[i]] = 1;
        cnt += v[i];
        pre -= 1;
      } else {
        if (pre >= 1 && v[i] >= pre && !vis[pre] ) {
          vis[pre] = 1;
          cnt += pre;
          pre -= 1;
        } 
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}

