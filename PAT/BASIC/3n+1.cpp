#include<iostream>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    int cnt = 0;
    while (n != 1) {
      if (n & 1) n = 3 * n + 1;
      n >>= 1;
      cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}

