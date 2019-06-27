#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
const int maxn = 510, inf = 0x3f3f3f3f;
int e[maxn][maxn], vis[maxn], dis[maxn], pre[maxn], W[maxn], cnt[maxn], nums[maxn];
using namespace std;

void printPath(int u, int v) {
  if (u == v) {
    cout << u;
    return;
  }
  printPath(pre[u], v);
  cout << " " << u;
}
int main() {
  int n, m, s, d;
  cin >> n >> m >> s >> d;
  fill(dis, dis + maxn, inf);
  fill(e[0], e[0] + maxn * maxn, inf);

  for (int i = 0; i < n; i++) cin >> cnt[i];

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u][v] = w;
    e[v][u] = w;
  }

  dis[s] = 0;
  nums[s] = 1;
  W[s] = cnt[s];
  for (int i = 0; i < n; i++) {
    int u = -1, mindis = inf;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && dis[j] < mindis) {
        mindis = dis[j];
        u = j;
      }
    }
//    if (u == -1) break;
    vis[u] = 1;
    for (int v = 0; v < n; v++) {
      if (!vis[v] && e[u][v] != inf) {
        if (dis[u] + e[u][v] < dis[v]) {
          dis[v] = dis[u] + e[u][v];
          pre[v] = u;
          nums[v] = nums[u];
          W[v] = W[u] + cnt[v];
        } else if (dis[u] + e[u][v] == dis[v]) {
          nums[v] += nums[u];
          if (W[u] + cnt[v] > W[v]) { //如果新的路救援队数量更多，那么更新这个点的前驱
            W[v] = W[u] + cnt[v];
            pre[v] = u;
          }
        }
      }
    }
  }

  cout << nums[d] << " " << W[d] << "\n";
  printPath(d, s);
  return 0;
}
/*
4 5 1 3
20 30 40 10
0 1 1
1 3 2
0 3 3
0 2 2
2 3 2
*/
