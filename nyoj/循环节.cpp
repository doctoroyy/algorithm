#include<cstdio>
#include<cstring>
using namespace std;
int main() {
  int n, num[100010], t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d",&n);
    memset(num, 0, sizeof(num));
    if (n == 1 || n == -1) {
      printf("%d\n", n);
      continue;
    }
    if (n < 0) {
      n = -n;
      printf("-0.");
    } else {
      printf("0.");
    }
    int t = 1;
    while (num[t] != 1 && t != 0) {
      num[t] = 1;
      t *= 10;
      printf("%d", t/n);
      t %= n;
    }
    printf("\n");
  }
}

