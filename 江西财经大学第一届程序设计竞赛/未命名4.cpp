#include<iostream>
using namespace std;
int main() {
  int t, num0 = 'S' * 19*19 + 'S' * 19 + 'R';
  string str;
  cin >> t;
  while (t--) {
    cin >> str;
    int num = str[0] * 19*19 + str[1] * 19 + str[2];
    cout << num0 - num << endl;
  }
} 
