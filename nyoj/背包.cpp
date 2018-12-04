#include<iostream>
#include<algorithm>
using namespace std; 
const int N = 10000;
int main() {
  int v[110], w[110], m[N+10], last_m[N+5];
  int n, c, sv;
  while (cin >> n >> c) {
    sv = 0;
    for (int i = 1; i <= n; i++) {
      cin >> w[i] >> v[i];
      sv += v[i];
    }
    for (int i = 1; i <= N; i++) last_m[i] = m[i] = 1e9 + 1;
    m[0] = last_m[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= sv; j++) {
        m[j] = j > v[i] ? min(last_m[j], last_m[j - v[i]] + w[i]) : min(last_m[j], w[i]);
      }
      for (int j = 0; j <= sv; j++) last_m[j] = m[j];
    }
    int value = 1;
    while (value <= sv && last_m[value] <= c) value++;
    cout << value - 1 << endl;
  }
}
