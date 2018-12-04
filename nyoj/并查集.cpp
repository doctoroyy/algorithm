#include<stdio.h>
const int N = 1000;
int father[N+10];
int find(int x) {
  return x == father[x] ? x : father[x] = find(father[x]);
}
int main() {
  int n, m, a, b;
  while (scanf("%d", &n), n) {
    scanf("%d", &m);
    for (int i = 1; i <= n; i++) father[i] = i; 
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &a, &b);
      father[find(a)] = find(b);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (father[i] == i) cnt++;
    }
    printf("%d\n", cnt - 1);
  }
}
