#include<iostream>
using namespace std;
const int mod = 10;
long long pow(int n, int m) {
  long long res = 1, base = n;
  while (m) {
    if (m % 2 == 1) res = res * base % mod;
    base = base * base % mod;
    m /= 2; 
  }
  return res;
}
int main() {
  int n, m;
  while (cin >> n >> m) {
    cout << pow(n, m) << endl;
  }
  return 0;
}

