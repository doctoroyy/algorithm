#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e5;
int a[N+5];
int BinarySearch(int a[], int k, int n) {
  int left = k, right = n, mid;
  while (left < right) {
    mid = (left + right) / 2;
    if (a[mid] > 2*a[k]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return n - right;
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int sum, res = 1e9;
    for (int i = 0; i < n; i++) {
      sum = i;
      sum += BinarySearch(a, i, n);
      res = min(sum, res); 
    }
    printf("%d\n", res);
  }
}
