#include<iostream>
#include<cstdio>
using namespace std;
int main() {
  string text, pattern;
  int t;
  cin >> t;
  getchar();
  while (t--) {
    cin >> text >> pattern;
    int cnt = 0;
    for (int i = 0; i < text.size(); i++) {
      if (text.substr(i, pattern.size()) == pattern) cnt++;
    }
    cout << cnt << endl;
  }
}
