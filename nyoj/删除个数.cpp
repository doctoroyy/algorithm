#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100000;
int main(){
  int n, a[N];
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int max = 1, j = 1;
    for (int i = 0; i < n; i++) {
      while (j < n && a[j] <= 2 * a[i]) j++;
      if (j - i > max) max = j - i;
    }
    printf("%d\n", n - max);
  }
}
