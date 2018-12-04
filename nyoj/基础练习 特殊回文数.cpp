#include<iostream>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    for (int i = 1; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        int k = n - 2 * i - 2 * j;
        if (k < 0 || k > 9) continue;
        cout << i << j << k << j << i << endl;
      }
    }
    for (int i = 1; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 10; k++) {
          if (2 * (i + j + k) == n)
            cout << i << j << k << k << j << i << endl;
        }
      }
    }
  }
  return 0;
}

