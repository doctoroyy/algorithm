#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
#include<cstdio>
using namespace std;
long long ans[10000];
long long pow(int n, int k) {
  long long res = 1, base = n;
  while (k) {
    if (k & 1) res *= base;
    base *= base;
    k /= 2;
  }
  return res;
}
int biSearch(int n, long long key) {
  int mid = n / 2, l = 0, r = n;
  while (l <= r) {
    mid = (l + r) / 2;
    if (ans[mid] == key) {
      return mid;
    } else if (ans[mid] > key) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
}
int main() {

  int a = 0, b = 0, c = 0, d = 0;
  int index = 0;
  for (a = 0; a < 30; a++) {
    for ( b = 0; b < 30; b++) {
      for (c = 0; c < 30; c++) {
        for (d = 0; d < 30; d++) {
          if (abs(pow(2, a) * pow(3, b) * pow(5, c) * pow(7, d)) <= 1000000000) {
            ans[index++] =  (long long) pow(2, a) * pow(3, b) * pow(5, c) * pow(7, d);
          } else {
            break;
          }
        }
      }
    }
  }
  sort(ans, ans + index);
//  cout << index;
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);

    printf("%lld\n", ans[biSearch(index, n)]);

  }
  return 0;
}
