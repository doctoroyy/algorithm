#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e4 + 10;
struct node {
  int id, cnt, money;
} a[maxn];

bool cmp(const node &a, const node &b) {
  if (a.money != b.money) return a.money > b.money;
  if (a.cnt != b.cnt) return a.cnt > b.cnt;
  return a.id < b.id;
}
int main() {
  int n, k, ni, pi;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    a[i].id = i;
    cin >> k;
    while (k--) {
      cin >> ni >> pi;
      a[i].money -= pi;
      a[ni].money += pi;
      a[ni].cnt++;
    }
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    printf("%d %.2lf", a[i].id, (double) a[i].money / 100);
    if (i <= n - 1) puts("");
  }
  return 0;
}
