#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100;
int vis[maxn];
int a[maxn];
int n, k, cnt;
void comb(int index) {
  if (index > k) return;
  if (index == k) {
//    for (int i = 0; i < k; i++) {
//      cout << a[i] << " ";
//    }
//    cout << endl;
    cnt++;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0 && i > a[index - 1]) {
      vis[i] = 1;
      a[index] = i;
      comb(index + 1);
      vis[i] = 0;
    }
  }
}
int main() {
  while (cin >> n >> k) {
    cnt = 0;
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
    comb(0);
    cout << cnt << endl;
  }
}

/*
1 2 3 4 5

1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5
*/
