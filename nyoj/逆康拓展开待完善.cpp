#include<stdio.h>
const int N = 13;
int main() {
  char str[15];
  int t;
  scanf("%d", &t);
  long long factorial[15] = {1};
  for (int i = 1; i <= 13; i++) {
    factorial[i] = i * factorial[i-1];
  }
  while (t--) {
    long long m;
    scanf("%lld", &m);
    m -= 1;
    int visit[13] = {0};
    for (int i = 0; i <= N; i++) {
      int t = m / factorial[N - i - 1];
      for (int j = 0; j <= t; j++) {
        if (visit[])
      }
    }
  }
}
