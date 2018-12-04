//#include<stdio.h>
//int sum = 0, n, m;
//void f(int x, int y) {
//  if (x > n || y > m ) return;
//  if (x == n && y == m) sum++;
//  f(x+1, y);
//  f(x, y+1);
//}
//int main() {
//  while (scanf("%d%d", &n, &m), n || m) {
//    sum = 0;
//    f(0, 0);
//    printf("%d\n", sum);
//  }
//}
#include<stdio.h>
#include<string.h>
long long map[40][40];
void dp() {
  memset(map, 0, sizeof(0));
  for (int i = 0; i < 40; i++) map[i][0] = map[0][i] = 1;
  for (int i = 1; i < 40; i++) {
    for (int j = 1; j < 40; j++) {
      map[i][j] = map[i-1][j] + map[i][j-1];
    }
  }
}
int main() {
  dp();
  int n, m;
  while (scanf("%d%d", &n, &m), n || m) {
    printf("%lld\n", map[n][m]);
  }
}
