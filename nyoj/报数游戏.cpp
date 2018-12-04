#include<stdio.h>
int seven(int num) {
  if (num % 7 == 0) return 1;
  while (num) {
    if (num % 10 == 7) return 1;
    num /= 10; 
  }
  return 0;
}
int playgame(int n, int m, int k) {
  int t = 0, count = 0, num = 1;
  while (true) {
    for (int num = 1; num <= n; num++) {
      if (t == k) return count;
      count++;
      if (num == m && seven(count)) t++;
    }
    for (int num = n - 1; num >= 2; num--) {
      if (t == k) return count;
      count++;
      if (num == m && seven(count)) t++;
    }
  }
}
int main() {
  int n, m, k; 
  while (scanf("%d%d%d", &n, &m, &k), n||m||k) {
    printf("%d\n", playgame(n, m, k));
  }
}
