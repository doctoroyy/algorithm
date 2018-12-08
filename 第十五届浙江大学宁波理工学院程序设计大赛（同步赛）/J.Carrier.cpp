#include<iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  int a, b, x, y;
  while (t--) {
    cin >> a >> b >> x >> y;
    if (a < 350) {
      cout << "You have not enough minerals.\n";
      continue;
    }
    if (b < 250) {
      cout << "You require more vespene gas.\n";
      continue;

    }
    if (x + 6 > y) {
      cout << "You must construct additional pylons.\n";
      continue;
    }
    cout << "Carrier has arrived.\n";
  }
  return 0;
}

