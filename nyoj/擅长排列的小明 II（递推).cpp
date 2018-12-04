#include<iostream>
using namespace std;
int main() {
  int n, a[60] = {0, 1, 1, 2};
  for (int i = 4; i <= 56; i++) {
    a[i] = a[i - 1] + a[i - 3] + 1;
  }
  while (cin >> n) {
    cout << a[n] << endl;
  }
  return 0;
}
