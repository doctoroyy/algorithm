#include<iostream>
#include<cstring>
using namespace std;
int main() {
  string str1, str2;
  while (cin >> str1 >> str2) {
    str1 += str1;
    if (str1.find(str2) != -1) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}
