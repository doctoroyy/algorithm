#include<iostream>
using namespace std;
int main() {
  int runs, k, n;
  cin >> runs;
  while (runs--) {
    cin >> k >> n;
    cout << k << " " << n + (n + 1) * n / 2 << endl;
  }
  return 0;
}
