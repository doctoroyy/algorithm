#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
const int maxn = 100000 + 10;
int z[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  int l, r, c;
  for (int i = 0; i < m; i++) {
    cin >> l >> r >> c;
    for (int j = l; j <= r; j++) {
      z[j] = c;
    }
  }
  int x;
  cin >> x; 
  cout << z[x] << endl;
  return 0;
}

