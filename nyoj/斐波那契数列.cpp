#include<stdio.h>
struct Fibnum {
  int a1, a2;
}f[30];
int main() {
  f[1].a1 = 1, f[1].a2 = 0;
  f[2].a1 = 0, f[2].a2 = 1;
  for (int i = 3; i <= 20; i++) {
    f[i].a1 = f[i-1].a1 + f[i-2].a1;
    f[i].a2 = f[i-1].a2 + f[i-2].a2;
//    printf("%d %d\n", f[i].a1, f[i].a2);
  }
  int t, n_20;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n_20);
    bool find = false;
    for (int i = 0; i <= n_20 / 2584 + 1; i++) {
      if ((n_20 - f[20].a1 * i) % f[20].a2 == 0) {
        printf("%d %d\n", i, (n_20 - f[20].a1 * i) / f[20].a2);
        find = true;
        break;
      }
    }
    if (!find) {
      printf("No answer\n");
    }
  }
}
