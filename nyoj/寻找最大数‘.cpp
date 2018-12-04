#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std
    int main() {
  int N;
  cin >> N;
  while (N--) {
    int m;
    char s[100];
    cin >> s >> m;
    int len = strlen(s);
    char *p = s;
    for (int i = 0; i < len - m; i++) {
      p = max_element(p, s + m + 1 + i);
      cout << *p - '0';
      p++;
    }
    cout << endl;
  }
}
