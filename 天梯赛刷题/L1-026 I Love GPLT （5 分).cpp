#include<iostream>
using namespace std;
int main() {
  string str = "I Love GPLT";
  for (int i = 0; i < str.size(); i++) {
    cout << str[i];
    if (i < str.size() - 1) cout << endl;
  }
  return 0;
}
