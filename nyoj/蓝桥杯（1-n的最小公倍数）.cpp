#include<cstdio>
int main() {
  int factor[105];
  for (int i = 1; i <= 105; i++) factor[i] = i;
  for (int i = 1; i <= 105; i++) {
    for (int j = 2; j < i; j++) {
      if (factor[i] % factor[j] == 0) factor[i] = factor[i] / factor[j];
    }
  }
  int n;
  while (~scanf("%d", &n)) {
    int num[20000] = {1, 1}, len = 1;
    for (int i = 2; i <= n; i++) {
      int carry = 0;
      for (int j = 1; j <= len; j++) {
        int s = num[j] * factor[i] + carry;
        carry = s / 10;
        num[j] = s % 10;
      }
      while (carry > 0) {
        num[++len] = carry % 10;
        carry /= 10;
      }
    }
    for (int i = len; i >= 1; i--) printf("%d", num[i]);
    printf("\n");
  }
}
