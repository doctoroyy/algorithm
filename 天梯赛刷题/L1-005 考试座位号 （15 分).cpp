#include<iostream>
#include<vector>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  long long v[1010][2];
  for (int i = 0; i < n; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    v[b][0] = a;
    v[b][1] = c;
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    cout << v[t][0] << " " << v[t][1] << endl;
  }
  return 0;
}

