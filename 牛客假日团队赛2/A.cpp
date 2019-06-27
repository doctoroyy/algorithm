#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e4 + 10;
int a[maxn], b[maxn], vis[maxn];
int n, m;
bool cmp(int a, int b) {
  return a > b;
}
//int biSearch(int key) {//找到最后一个小于关键字的索引 
//  int l = 0, r = m - 1;
//  while (l <= r) {
//    int mid = l + (r - l) / 2; 
//    if (b[mid] < key) {
//      l = mid + 1;
//    } else {
//      r = mid - 1;
//    }
//  }
//  return r >= 0 ? r : -1;
//}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n, cmp), sort(b, b + m, cmp);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[j] < a[i] && !vis[j]) {
        vis[j] = 1;
        cnt++;
        break;
      }
    }
  }
  cout << cnt + n << endl;
  return 0;
}
/*
3 4
6 3 1
5 4 3 1

6 3 2
3 2 1 

4 3
6 4 3 2
3 2 1
*/

