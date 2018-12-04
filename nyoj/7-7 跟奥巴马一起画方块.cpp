#include<iostream>
using namespace std;
int main() {
  int n;
  char ch;
  cin >> n >> ch;
  for (int i = 0; i < int(double(n) / 2 + 0.5); i++) {
    for (int j = 0; j < n; j++) {
      cout << ch;
    }
    cout << endl;
  }
}
