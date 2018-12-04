#include<iostream>
using namespace std;
const int mod = 10000;
int main() {
  int a[15010] = {1, 2, 3};
  for (int i = 3; i < 15010; i++) {
    a[i] = (a[i-1] + a[i-2]) % mod;
  }
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << a[n%15000] << endl;
  }
} 
