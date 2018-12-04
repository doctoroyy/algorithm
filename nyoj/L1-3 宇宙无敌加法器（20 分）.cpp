#include<iostream>
using namespace std;
int main() {
  string refer;
  int a, b, res[30];
  cin >> refer >> a >> b;
  int index = 0, carry = 0;
  for (int i = refer.length() - 1; i >= 0 ; i--) {
    int raw = refer[i] - '0';
    if (raw == 0) raw = 10;
    res[index++] = (a % 10 + b % 10 + carry) % raw;
    carry = (a % 10 + b % 10 + carry) / raw;
    a /= 10;
    b /= 10;
  }
  bool flag = false;
  for (int i = index - 1; i >= 0; i--) {
    if (!flag && res[i] != 0) {
      flag = true;
    }
    if (flag) {
      cout << res[i];
    }
  }
} 
