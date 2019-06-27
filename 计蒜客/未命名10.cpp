#include<iostream>
#include<algorithm>
using namespace std;
const int Mod = 192600817, N = 500050;
int f[N] = {1,1}, dp[N] = {1}; 
void init() {
  for (int i = 2; i < N; i++) {
    f[i] = (f[i-1]%Mod+f[i-2]%Mod)%Mod;
  }
  for (int i = 1; i < N; i++) {
    dp[i] = ((f[i]%Mod)*(f[i]%Mod))%Mod + dp[i-1];
  }
}

int main() {
  int n;
  init();
  while (cin >> n) {
    int a, b, c, d;
    for (int i = 0; i < n; i++) {
      cin >> a >> b >> c >> d; 
    
      int l1 = a*4+b, l2 = c*4+d;
      if (l1 > l2) swap(l1,l2);
      if (l1 == 0) {
        cout << dp[l2] << endl;
      } else {
        cout << dp[l2] - dp[l1-1] << endl;
      }
      
//      long long ans = 0;
//      for (int i = l1; i <= l2; i++) {
//        ans += ((f[i]%Mod)*(f[i]%Mod))%Mod;
//      }
//      cout << ans <<endl;
    }
  }
  return 0;
}

