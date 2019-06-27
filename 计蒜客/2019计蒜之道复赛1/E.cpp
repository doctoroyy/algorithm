#include<iostream>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
bool is_match(const string &str) {
  int len = str.size();
  stack<char> s;
  int i;
  int cnt = 0;
  for (i = 0; i < len; ++i) {
    if (str[i] == '(') {
      s.push(str[i]);
      ++cnt;
      continue;
    }
    if (str[i] == ')') {
      ++cnt;
      if (!s.empty() && s.top() == '(') {
        s.pop();
        continue;
      }
    }
  }
  if (!s.empty()) {
    return false;
  }
  if (cnt % 2 != 0) {
    return false;
  }
  return true;
}
int main() {
  string str, tmp;
  cin >> str;
  tmp = str;
  prev_permutation(str.begin(), str.end());
  do {
    if (is_match(str)) {
      cout << str << endl;
      break;
    }
  } while (prev_permutation(str.begin(), str.end()));
  
  next_permutation(tmp.begin(), tmp.end());
  
  do {
    if (is_match(tmp)) {
      cout << tmp << endl;
      break;
    }
  } while (next_permutation(tmp.begin(), tmp.end()));
  return 0;
}
