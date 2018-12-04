#include<stdio.h>
int main() {
  int t, n, num;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int x = 0, flag = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &num);
      x = x^num;
      if (num > 1) flag = 1;
    }
    if ((flag && x) || (!flag && !x)) {
      printf("Yougth\n");
    } else {
      printf("Hrdv\n");
    }
  }
}
