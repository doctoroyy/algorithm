#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long m = sqrt(n);
  long long start = -1, minlen = 0;
  for (int i = 2; i <= m; i++) {
    if (n % i != 0) continue;
    long long res = 1, len = 0;
    for (int j = i; j <= m; j++) {
      if (res * j > n || n % (res * j) != 0) break;
      res *= j;
//      cout << res << endl; 
      len++;
    }
//    cout << endl;
    if (len > minlen) {
      minlen = len;
      start = i;
    }
  }
  if (start == -1) {
    cout << 1 << endl << n;
  } else {
    cout << minlen << endl;
    cout << start;
    for (int i = start + 1; i < start + minlen; i++) {
      cout << "*" << i;
    }
  }
  
  return 0;
}

