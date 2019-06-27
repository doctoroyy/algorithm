#include<iostream>
using namespace std;

int main() {
  long long m, n;
  cin >> m >> n;
  long long r1 = 15 * (m / 15 + 1);
  
  long long ans1 = (r1 - 1 - m + 1) * (m + r1 - 1) / 2;
  
  long long r2 = 15 * (n / 15);
  
  long long ans2 = (n - (r2 + 1) + 1) * (r2 + 1 + n) / 2;
  
  cout << (ans1 + ans2) % 15 << endl;
  
  return 0;
}

