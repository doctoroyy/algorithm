#include<iostream>
using namespace std;
int main() {
  int col;
  char ch;
  cin >> col >> ch;
  int raw = (col + 1) / 2;
  for (int i = 0; i < raw; i++) {
    for (int j = 0; j < col; j++) cout << ch;
    if (i < raw - 1) cout << endl;
  }
  return 0;
}
