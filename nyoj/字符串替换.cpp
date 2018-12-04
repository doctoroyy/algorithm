#include<cstdio>
#include<iostream>
using namespace std;
int main() {
  string str, me = "ÎÒ", you = "Äã";
  int pattern_len = me.size();
  while (cin >> str, str != "0") {
    for (int i = 0; i < str.size(); i++) {
      if (str.substr(i, pattern_len) == me) {
        str.replace(i, pattern_len, you);
      } else if (str.substr(i, pattern_len) == you) {
        str.replace(i, pattern_len, me);
      }
    }
    cout << str << endl;
  }
}
