#include<cstdio>
#include<algorithm>
using namespace std;
struct cudgel {
  int l, w;
  int visited;
}cub[10010];
bool cmp(cudgel a, cudgel b) {
  return a.l == b.l ? a.w < b.w : a.l < b.l;
}
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &cub[i].l, &cub[i].w);
      cub[i].visited = 0;
    }
    sort(cub, cub + n, cmp);
    for (int i = 0; i < n; i++) printf("%d %d\n", cub[i].l, cub[i].w);
    printf("\n");
    int count = 0;
    for (int i = 0; i < n; i++) {
      int temp = cub[i].w;
      if (cub[i].visited) continue;
      for (int j = i + 1; j < n; j++) {
        if (!cub[j].visited && cub[j].w >= temp) {
          cub[j].visited = 1;
          temp = cub[j].w;
        }
      }
      count++;
    }
    printf("%d\n", count);
  }
}
