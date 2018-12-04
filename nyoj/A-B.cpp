#include<iostream>
#include<cstring> 
using namespace std;
int main() {
  string str1, str2;
  getline(cin, str1);
  getline(cin, str2);
  int l1 = str1.length(), l2 = str2.length();
  for (int i = 0; i < l2; i++) {
    int pos = 0;
    while (str1.find(str1[i], pos) != str1.npos) { 
      pos = str1.find(str2[i]);
      str1[pos] = 0;
    }
  }
  for (int i = 0; i < l1; i++) {
    if (str1[i]) {
      cout << str1[i];
    }
  }
//  cout << endl;
}
//I lv GPLT!  It's  fn gm!
//I lv GPLT!  It's  fn gm!
