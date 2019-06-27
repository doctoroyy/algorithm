#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn = 1e4 + 10;
int prime[maxn] = {1, 1};
int vis[maxn];
void seive() {
  for (int i = 2; i <= sqrt(maxn); i++) {
    if (prime[i] == 0) {
      for (int j = i * i; j <= maxn; j += i) {
        prime[j] = 1;
      }
    }
  }
}

int f(int num) {
  int res = num, tot = 0;
  vis[num] = 1;
  while (res != 1) {
    int tmp = res;
    res = 0;
    while (tmp) {
      res += (tmp % 10) * (tmp % 10);
      tmp /= 10;
    }
    if (vis[res] == 1) return 0;
    vis[res] = 1;
    tot++;
  }
  return tot;
}
int main() {
  seive();
  int a, b;
  cin >> a >> b;
  vector<int> buff1, buff2;
  set<int> sset;
  int flag = 0;
  for (int i = a; i <= b; i++) {
    memset(vis, 0, sizeof(vis));
    int tot = f(i);
    if (tot != 0) {
      int res = i;
      while (res != 1) {
        int tmp = res;
        res = 0;
        while (tmp) {
          res += (tmp % 10) * (tmp % 10);
          tmp /= 10;
        }
        sset.insert(res);
      }
      buff1.push_back(i);
      buff2.push_back(prime[i] == 0 ? 2 * tot : tot);
      flag = 1;
    }
    
  }
  if (flag == 0) {
    cout << "SAD\n";
  } else {
    set<int>::iterator it;
    for (int i = 0; i < buff1.size(); i++) {
      int t = 0;
      for (it = sset.begin(); it != sset.end(); it++) {
        if (buff1[i] == *it) {
          t = 1;
          break;
        }
      }
      if (!t) cout << buff1[i] << " " << buff2[i] << endl;
    }
  }
  return 0;
}

