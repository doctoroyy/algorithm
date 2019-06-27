#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;
bool visit[10010];
int m[100010];
int main() {
  string s, s1;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    m[s[i]]++;
  }
  for (int i = 0; i < s.size(); i++) {
    m[s[i]]--;
    if (visit[s[i]] == false) {
      while (!s1.empty() && s[i] < s1.back() && m[s1.back()]) {
        visit[s1.back()] = false;
        s1.pop_back();
      }
      s1 += s[i];
      visit[s[i]] = true;
    } 
  }
  cout << s1 << endl;
  return 0;
}
