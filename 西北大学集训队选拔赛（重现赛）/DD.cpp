#include<iostream>
using namespace std;
const int N = 1e5+5;
#define LL long long
int arr[N];
int main() {
  ios::sync_with_stdio(false);
  int n, m, k, l, r;
  cin >> n >> m;
//  dp[1] = 1;
//  arr[1] = 1;
  for (int i = 1; i <= n; i++) {
//    dp[i] = dp[i-1] + i;
    arr[i] = i;
  }
  while (m--) {
    cin >> k >> l >> r;
    LL sum = 0;
    if (k == 2) {
      for (int i = l; i <= r; i++) {
        sum += arr[i];
      }
      cout << sum << endl;
    } else {
      for (int i = l, j = 1; i <= r, j <= r - l + 1; i++, j++) {
//        dp[i] += arr[j]-arr[i];
        arr[i] = j;
      } 
    }
  }
  return 0;
}

