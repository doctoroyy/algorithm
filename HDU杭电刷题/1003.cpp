#include<iostream>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int main() {
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; k++) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    int max_so_far = 0, sum_so_far = 0, l = 1, r = 1, tmp_l = 1;
    for (int i = 1; i <= n; i++) {
      sum_so_far += a[i];
      if (sum_so_far > max_so_far) {
        max_so_far = sum_so_far;
        r = i;
        l = tmp_l; //注意应该在这里修改起点 
      }
      if (sum_so_far < 0) {
        sum_so_far = 0;
        tmp_l = i + 1;
      }
    }
    printf("Case %d:\n%d %d %d\n", k, max_so_far, l, r);
    if (k < t) printf("\n"); 
  }
  return 0;
}
/*
3
9 -2 1 -3 4 -1 2 1 -5 4
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5

*/

