#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
  int t, n, a[10005];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a+n);
    for (int i = 0; i < (n + 1) / 2 - 1; i++) printf("%d ", a[i]);
    for (int i = n - 1; i >= (n + 1) / 2 - 1; i--) printf("%d ", a[i]);
    printf("\n");
  }
}
