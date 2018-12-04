#include<cstdio>
#include<cstring>
char str[1000010];
const int mod = 10003;
int main() {
  int n, m;
  scanf("%d", &n);
  getchar();
  while (n--) {
    gets(str);
    int t = 0, len = strlen(str);
    for (int i = 0; i < len; i++) {
      t = ((t * 10) % mod + (str[i] - '0') % mod) % mod;
    }
    printf("%d\n", t);
  }
}
