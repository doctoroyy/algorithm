#include<iostream>
using namespace std;
int isPalindromes(string str, int len) {
  if (len == 1) return false;
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) return 0;
  }
  return 1;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    string str;
    cin >> str;
    if (str.size() & 1) {
      cout << str.size() << endl;
      continue;
    }
    int len = str.size();
    while (isPalindromes(str, len)) {
      len /= 2;
//      if (len & 1) break;
    }
    cout << len << endl;
  }
}

