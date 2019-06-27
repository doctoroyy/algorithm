#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define LL long long
const int N = 1e6+10;
LL arr[N];
LL gcd(LL m, LL n) {
  return m % n == 0 ? n : gcd(n, m % n);
}
LL lcm(LL m, LL n) {
  return m / __gcd(m, n) * n ;
}
int main() {
//  cout << gcd(12, 6);
  int t;
  scanf("%d",&t);
  while (t--) {
    LL n, c;
    scanf("%lld%lld",&n,&c);
    if (c <= n) {
      printf("%lld",c*c);
      if (t != 0) {
        printf("\n");
      }
      continue;
    }
    if (sqrt(c) >= n) {
      printf("-1");
      if (t != 0) {
        printf("\n");
      }
      continue;
    }

    int k = 0;
    for (LL i = 1; i <= sqrt(c); i++) {
      if (c%i == 0) {
        arr[k++] = i;
        if (i*i != c) {
          arr[k++] = c/i;
        }
      }
    }

//    sort(arr,arr+k);
//    for (int i = 0; i < k; i++) {
//      cout << arr[i] << " ";
//    }
//    cout << endl;
//    cout << "------------" << endl;
    LL sum = -1;
    for (int i = 0; i < k - 1; i++) {
      for (int j = i + 1; j < k; j++) {
        if (lcm(arr[i], arr[j]) == c && arr[i] <= n && arr[j] <= n) {
//          cout << arr[i] << " " << arr[i-1] << endl;
          sum = max(sum, arr[i] * arr[j]);
        }
      }
    }

//    for (int i = k-1; i >= 0; i--) {
//      if (arr[i] <= n && lcm(arr[i], arr[i - 1]) == c) {
//        sum = arr[i]*arr[i-1];
////        cout << arr[i] << " " << arr[i-1] << endl;
//        break;
//      }
//    }
//    cout << "------------" << endl;
    printf("%lld",sum);
    if (t != 0) {
      printf("\n");
    }
  }
  

  return 0;
}
/*
10
10 15
7 36
5 36
10 12
1 1
*/

