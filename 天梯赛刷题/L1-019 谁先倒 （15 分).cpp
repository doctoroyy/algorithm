#include<iostream>
using namespace std;
int main() {
  long long a, b, n;
  cin >> a >> b >> n;
  long long ta = a, tb = b;
  for (int i = 0; i < n; i++) {
    long long a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    long long num = a1 + b1;
    if (a2 == num && b2 != num) {
      a--;
    }
    if (b2 == num && a2 != num) {
      b--;
    }
    if (a < 0 || b < 0) break;
  }
  if (a < b) {
    cout << "A\n";
    cout << tb - b;
  } else {
    cout << "B\n";
    cout << ta - a;
  }
  return 0;
}

