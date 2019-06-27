#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main() {
  int n;
  char ch;
  cin >> n >> ch;
  getchar();
  string str;
  getline(cin, str);
//  cout << str << endl;
  vector<char> v;
  int len = str.size();
  if (n <= str.size()) {
//    cout << "*\n";
    for (int i = 0; i < n; i++) {
      v.push_back(char(str[len - i - 1]));
    }
    for (int i = v.size() - 1; i >= 0; i--) {
      cout << v[i];
    }
  } else {
//    cout << "*1\n";
    for (int i = 0; i < str.length() - n; i++) {
//      cout << "@\n";
      str = ch + str;
    }
    cout << str;
  }
  
  return 0;
}



