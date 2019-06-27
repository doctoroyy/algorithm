#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 100  + 10;
int a[maxn];
vector<int> v[maxn];
int main() {
  int n;
  cin >> n;
  int maxRaw = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    maxRaw = max(maxRaw, a[i]);

//    v.push_back(vector<int>());
//    v[i].push_back(0);
  }
  int an = 0, ss = n, d = 1, pre = 0;
  for (int i = 1; i <= maxRaw; i++) {
    for (int k = 1; k <= 10; k++) {
      for (int j = 1; j <= n; j++) {
        if (v[j].size() == a[j] * 10) {
          if (j != pre) {
            ss--;
            pre = j;
          }
          continue;
        }
        if (ss == 1) d = 2;
        an += d;
        v[j].push_back(an);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << "#" << i << endl;
    for (int j = 0; j < v[i].size(); j++) {
      cout << v[i][j];
      if ((j + 1) % 10 != 0) cout << " "; 
//      printf("%3d", v[i][j]);
      if ((j + 1) % 10 == 0 && j != 0) cout << endl;
    }
//    cout << endl;
  }
  return 0;
}

