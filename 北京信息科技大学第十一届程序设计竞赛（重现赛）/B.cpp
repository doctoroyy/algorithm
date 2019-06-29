#include<iostream>
using namespace std;
#define ll long long 
const int mod = 109;
int main() {
  ios::sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  if (n <= m) {
    cout << 1 << endl;
  } else {
    ll ans = 1;
    for (ll i = n; i >= m; i--) {
      ans = ans * i % mod;
    }
    cout << ans << endl;
  }
  
  return 0;
}

