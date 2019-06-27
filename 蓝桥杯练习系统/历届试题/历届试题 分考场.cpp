#include<iostream>
using namespace std;
const int maxn = 110;
int e[maxn][maxn], vis[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    e[a][b] = 1;
  }
  
  if (m == n * (n - 1) / 2) cout << n << endl;
  else {
    int cnt = n;
    for (int i = 1; i <= n - 1; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (e[i][j] == 0 && !vis[i] && !vis[j]) {
          cnt--;
          vis[i] = vis[j] = 1;
        }
      }
    }
    cout << cnt << endl;
  } 
  return 0;
}

