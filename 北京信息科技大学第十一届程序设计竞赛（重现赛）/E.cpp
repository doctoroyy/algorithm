#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#include<set>
using namespace std;
const int maxn = 10100;
int a[maxn], vis[maxn], prime[maxn];
int n, _min;
void init() {
  prime[0] = prime[1] = 1;
  for (int i = 2; i <= sqrt(1010); i++) {
    if (prime[i] == 0) {
      for (int j = i * i; j <= 1010; j += i) {
        prime[j] = 1;
      }
    }
  }
}

void dfs(const vector<int> &v, int index, int sum) {
  if (index == n) {
    _min = min(_min, sum);
    return;
  }
  for (int i = 0; i < v.size(); i++) {
    if (!vis[i] && a[index] % v[i] == 0) {
      vis[i] = 1;
      dfs(v, index + 1, sum + v[i]);
      vis[i] = 0;
    }
  }
}

int main() {
  init();
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  set<int> sset;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 2; j <= a[i]; j++) {
      if (a[i] % j == 0 && prime[j] == 0) {
        sset.insert(j);
      }
    }
  }
  if (sset.size() < n) {
    cout << -1 << endl;
  } else {
    vector<int> v;
    int sum = 0, cnt = 0;;
    for (auto it : sset) {
      v.push_back(it);
    }
    _min = 0x3f3f3f3f;
    dfs(v, 0, 0);
    cout << _min << endl;
  }
  return 0;
}
