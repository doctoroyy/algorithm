#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e6 + 10;

int a[maxn], b[maxn], c[maxn];

int binarySearch(int a[], int len, int key) {//返回第一个大于关键字的索引
  int l = 0, r = len - 1, mid, pos = -1;
  while (l <= r) {
    mid = (l + r) / 2;
    if (a[mid] <= key) {
      l = mid + 1;
      pos = l;
    } else {
      r = mid - 1;
      pos = mid;
    }
  }
  return pos;
}
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int bstart = binarySearch(b, n, a[i]);
      int cstart = binarySearch(c, n, b[bstart]);
      sum += (n - bstart) * (n - cstart);
    }
    cout << sum << endl;
  }
  return 0;
}
