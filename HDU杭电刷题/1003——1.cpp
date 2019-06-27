#include<iostream>
#include<string.h>
using namespace std;
long long a[1000000];
int main() {
  long long T, n, t, m, len;
  long long count = 0;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    t = 1;
    m = 1;
    long long maxSum = a[0];
    long long thisSum = 0;
    for (int j = 0; j < n; j++) {
      thisSum += a[j];
      if (thisSum > maxSum) {
        maxSum = thisSum;
        t = j+1;
      }
      else {
        if (thisSum < 0) {
          thisSum = 0;
          m = j+2;
        }
      }
    }
    cout << "Case " << ++count << ":" << endl << maxSum << " " << m << " " << t << endl;
    if (T > 0) 
      cout << endl;
  }
}


