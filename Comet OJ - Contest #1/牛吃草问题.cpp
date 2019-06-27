#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 50 + 10;
char maze[maxn][maxn];
int n, m;
int valid(int r, int x, int y) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (maze[i][j] == '.') {
        if (abs(x - i) + abs(y - j) > r) {
          return 0;
        }
      }
    }
  }
  return 1;
}

void find() {
  int r0, x0, y0;
  for (int r = 0; r < n && r < m; r++) {
    for (int i = r + 1; i + r <= n; i++) {
      for (int j = r + 1; j + r <= m; j++) {
        if (valid(r, i, j)) {
          r0 = r;
          x0 = i;
          y0 = j;
        }
      }
    }
  }
  printf("%d %d %d\n", r0, x0, y0);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      scanf("%s", maze[i] + 1);
    }
    find();
  }
  return 0;
}
