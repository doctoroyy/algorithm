#include<iostream>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  cout << 5000 - ((100 - x) * (100 - y) / 2 + x * y / 2 + (100 - x) * y);
  return 0;
}

