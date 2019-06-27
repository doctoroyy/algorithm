#include<iostream>
#include<vector>
using namespace std;
int main() {
  string str;
  vector<string> v;
  while (cin >> str && str != ".") {
    v.push_back(str);
  }
  if (v.size() >= 14) {
    cout << v[1] << " and " << v[13] << " are inviting you to dinner...";
  } else if (v.size() >= 2) {
    cout << v[1] << " is the only one for you...";
  } else {
    cout << "Momo... No one is for you ...";
  }
  return 0;
}

