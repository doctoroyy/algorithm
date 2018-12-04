#include<stdio.h>
#include<string.h>
#define max(a, b) a > b ? a : b;
int main() {
  int T;
  char a[1100], b[1100], x[1100], y[1100];
  scanf("%d", &T);
  for (int c = 1; c <= T; c++) {
    getchar();
    int temp = 0;
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    scanf("%s%s", a, b);
    int l1 = strlen(a), l2 = strlen(b);
    int l = max(strlen(a), strlen(b));
    for (int i = l1 - 1, j = 0; i >= 0; i--, j++) {
      x[j] = a[i] - '0';
    }
    for (int i = l2 - 1, j = 0; i >= 0; i--, j++) {
      y[j] = b[i] - '0';
    }
    int bits;
    for (bits = 0; bits < l; bits++) {
      x[bits] += y[bits];
      if (x[bits] >= 10) {
        x[bits] -= 10;
        x[bits+1] += 1;
      }
    }
    printf("Case %d:\n", c);
    printf("%s + %s = ", a, b);
    int k;
    for (k = bits; k >= 0; --k ) {
      if (x[k] != 0)
      break;
    }
    for (; k >= 0; --k) {
      printf("%d", x[k]);
    }
    printf("\n");
  }
} 
