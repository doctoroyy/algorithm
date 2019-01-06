#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn = 20;
int n, cnt = 0;
int m[maxn]; // m[i] = j 代表第i行第j列放置皇后 
int valid(int raw, int col) {
  for (int i = 1; i <= raw - 1; i++) {
    //如果这一列在前raw - 1行里已经放置过 或者 这个位置与之前行的皇后位置在同一对角线.返回0 
    if (m[i] == col || abs(i - raw) == abs(m[i] - col)) return 0;
  }
  return 1;
}
void print() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (m[i] != j) {
        printf("%2s", "X");
      } else {
        printf("%2s", "Q");
      }
    }
    printf("\n");
  }
}
void dfs(int raw) {
  if (raw == n + 1) {
    cnt++;
    print();
    printf("\n");
    return;
  }
  for (int col = 1; col <= n; col++) {
    if (valid(raw, col)) {
      m[raw] = col;
      dfs(raw + 1);
    }
  }


}
int main() {
  scanf("%d", &n);
  dfs(1);
  printf("%d\n", cnt);
  return 0;
}

