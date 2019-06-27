#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
using namespace std;
const int maxn = 1e6 + 10;
int f[maxn], m[maxn], g[maxn];

int dfs(int x, int y, int rank) {
  if (rank >= 5) return 1;
  if ((f[x] == f[y] && f[x] == -1) || (m[x] == m[y] && m[x] == -1)) return 1;
  if ((f[x] == f[y] && f[x] != -1) || (m[x] == m[y] && m[x] != -1) || x == y) return 0;
  return dfs(f[x], f[y], rank + 1)  && dfs(f[x], m[y], rank + 1) && dfs(m[x], f[y], rank + 1) && dfs(m[x], m[y], rank + 1);
}
int main() {
  memset(f, -1, sizeof(f));
  memset(m, -1, sizeof(m));
  int n, k;
  cin >> n;
  while (n--) {
    int id, fid, mid;
    char gender;
    cin >> id >> gender >> fid >> mid;
    f[id] = fid, m[id] = mid;
    if (gender == 'M') 
      g[id] = 1;
    else 
      g[id] = 0;
    if (fid != -1) {
      g[fid] = 1;
    }
    if (mid != -1) {
      g[mid] = 0;
    }
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int id1, id2;
    cin >> id1 >> id2;
    if (g[id1] == g[id2]) {
      cout << "Never Mind";
    } else {
      if (dfs(id1, id2, 1)) {
        cout << "Yes";
      } else {
        cout << "No";
      }
    }
    if (i < k - 1) cout << "\n";
  }
  return 0;
}
