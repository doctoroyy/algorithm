#include<iostream>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    if (n) {
      cout << (2 * n - 1) * (2 * n - 1) + 1 << endl;
    } else {
      cout << "1" << endl;
    }
  }
}
