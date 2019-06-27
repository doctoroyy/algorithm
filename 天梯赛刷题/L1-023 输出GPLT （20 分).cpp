#include<iostream>
#include<vector>
using namespace std;
int main() {
  string str;
  getline(cin, str);
  vector<char> v[26];
  for (int i = 0; i < str.size(); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') str[i] = str[i] - 'a' + 'A';
    v[str[i] - 'A'].push_back(str[i]);
  }
  string s = "GPLT";
  while (!v['G' - 'A'].empty() || !v['P' - 'A'].empty() || !v['L' - 'A'].empty() || !v['T' - 'A'].empty()) {
    for (int i = 0; i < 4; i++) {
      if (!v[s[i] - 'A'].empty()) {
        cout << s[i];
        v[s[i] - 'A'].pop_back();
      }
    }
  }
  return 0;
}


