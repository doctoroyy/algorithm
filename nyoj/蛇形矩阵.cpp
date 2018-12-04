#include<stdio.h>
#include<string.h>
int a[1000][1000];
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
//    memset(a, 0, sizeof(a));
    int i = 1, j = 0, no = 0, t = n;
    for (int k = 0; k < n / 2 + 1; k++) {
      while (j < t) {
        a[i][++j] = ++no;
        //printf("(%d, %d)", i, j);
      }
     // printf("\n");
      while (i < t) {
        a[++i][--j] = ++no;
        //printf("(%d, %d)", i, j);
      }
      //printf("\n");
      while (i > j + 1) {
        a[--i][j] = ++no;
       // printf("(%d, %d)", i, j);
      }
      //printf("\n");printf("\n");
      t -= 2;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n - i + 1; j++) {
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }
  }
}
