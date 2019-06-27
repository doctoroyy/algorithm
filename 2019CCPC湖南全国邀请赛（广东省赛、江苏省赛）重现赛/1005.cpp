#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define _rep(n,m,i) for (int i = n; i <= m; i++)
#define _for(n,m,i) for (int i = n; i < m; i++)
#define ff first
#define ss second
#define It iterator
#define me(a) memset(a, 0, sizeof(a))
inline int read() {
  int x = 0;
  char s = getchar();
  while(s < '0' || s > '9') s = getchar();
  while(s >= '0' && s <= '9') x = x * 10 + s - '0', s = getchar();
  return x;
}
LL a[5];
int main() {
  string s;
  int n;
  while(cin >> n >> s) {
    memset(a,0,sizeof(a));
    _for(0,n,i) {
      if(s[i] == 'g')
        a[0]++;
      if(s[i] == 'd')
        if(a[0] > a[1])
          a[1]++;
      if(s[i] == 'C')
        if(a[1] > a[2])
          a[2]++;
      if(s[i] == 'p')
        if(a[2] > a[3])
          a[3]++;
      if(s[i] == 'c')
        if(a[3] > a[4])
          a[4]++;
    }
    cout << a[4] << endl;
  }

}

