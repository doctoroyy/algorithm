#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define _for(n,m,i) for (int i = (n); i < (m); i++)
#define _rep(n,m,i) for (int i = (n); i <= (m); i++)
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define lowbit(x) x & (-x)
int main() {
  fio
  string s, t;
  int n, m, l = 0, r = 0, k = 0, k1 = 0;
  cin >> n >> m;
  cin >> s;
  for(int i = 0; i < m && i < n; i++) {
    if(i == 0) {
      t += to_string(s[i] - '0');
      k1 ^= s[i] - '0';
    } else {
      t += to_string((s[i] - '0') ^ (s[i-1] - '0'));
      k1 ^= (s[i] - '0') ^ (s[i-1] - '0');
    }
  }
  for(int i = t.size(); i < n; i++) {
    t += to_string(((s[i] - '0') ^ (s[i-1] - '0') ^ (t[i - m] - '0')));
  }
  cout << t << endl;
}
