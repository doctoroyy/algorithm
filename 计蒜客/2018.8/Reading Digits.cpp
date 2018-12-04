#include<iostream>
using namespace std;
int main() {
  int k, pos;
  string str;
  while (cin >> k >> pos) {
    cin >> str;
    string newstr = "";
    while (k--) {
      for (int j = 0; j < str.size(); j += 2) {
        for (int l = 0; l < str[j] - '0'; l++) {
          newstr += str[j + 1];
        }
      }
      str = newstr;
      newstr = "";
    }
    cout << str[pos] << endl;
  }
  return 0;
} 
