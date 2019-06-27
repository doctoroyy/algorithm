#include<iostream>
#include<algorithm>
using namespace std;
const int N = 200005;
#define LL long long
LL Set[N];
LL sum[N];
LL qmod(LL a, LL b) ;
LL qmod1(LL a, LL b, LL p) ;
int main() {
  LL n, k, m, p;
  cin >> k >> m >> n >> p;
  for (LL i = 1; i <= k; i++) {
    cin >> Set[i]; 
  } 
  sort(Set+1,Set+k+1);
  if (n == 1) {
    LL ans = 0, temp = 0;
    for (LL i = 1; i < m; i++) {
      temp = (temp +Set[i])%p;
      ans = (ans + temp) % p;
    }
    cout << ans << endl;
    return 0;
  }
  LL step = (qmod(n,m)-n)/(n-1);
  for (LL i = 1; i <= step; i++) {
    sum[i] = (sum[i-1] + Set[i])%p;
  }
  LL ans = 0;
  LL t = 1, step1;
  while (m-1 > 0) {
    step = (qmod(n,m)-n)/(n-1);
    step1 = (qmod(n,m-1)-n)/(n-1);
//    ans = ans +((sum[step]-sum[step1])%p*qmod1(n,t,p))%p;
    ans = (ans +(((sum[step]-sum[step1])%p)*((qmod1(n,t,p)-1)/(n-1)%p))) % p;
    m--;
    t++;
  }
  cout << ans << endl;
  return 0;
} 
LL qmod1(LL a, LL b, LL p) {
  LL ans = 1;
  a = a%p;
  while (b) {
    if (b&1) {
      ans = ans*a%p;
    }
    a = a*a%p;
    b >>= 1; 
  }
  return ans;
}
LL qmod(LL a, LL b) {
  LL ans = 1;
  while (b) {
    if (b&1) {
      ans = ans*a;
    }
    a = a*a;
    b >>= 1; 
  }
  return ans;
}
/*
12 3 3 90
1 2 3 4 5 6 7 8 9 10 11 12
39 4 3 10000
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39
*/
