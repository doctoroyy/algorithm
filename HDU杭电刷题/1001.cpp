#include<iostream>
#include<cmath>
using namespace std;
int main() {
  long long t, n;
  cin >> t; 
  while (t--) {
    cin >> n;
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    int cnt = 0;
    for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0) {
        if (n / i != i) cnt++;
        cnt++;
      }
    }
    
    cout << cnt + 2 << endl;
  }
  return 0;
}
