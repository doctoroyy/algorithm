#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  double n;

  while (cin >> n) {
    if (log2(n) - (long long)(log2(n)) == 0 ) {
      cout << (long long)log2(n) << endl;
    } else {
      cout << (long long)log2(n) + 1 << endl;
    }
  }


  return 0;
}

