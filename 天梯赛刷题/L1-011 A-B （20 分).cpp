#include<iostream>
using namespace std;
int ele_in_string(char ch, string str) {
  for (int i = 0; i < str.size(); i++) {
    if (ch == str[i]) return 1;
  }
  return 0;
}
int main() {
  string a, b;
  getline(cin, a);
  getline(cin, b);
//  cout << a << endl << b << endl;
  for (int i = 0; i < a.size(); i++) {
    if (!ele_in_string(a[i], b)) {
      cout << a[i];
    }
  }
  
  return 0;
}

