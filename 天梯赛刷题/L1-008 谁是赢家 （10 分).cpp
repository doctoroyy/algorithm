#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int main() {
  int pa, pb, a, b, c;
  cin >> pa >> pb >> a >> b >> c;
  if (pa > pb) {
    if (a == 0 || b == 0 || c == 0) {
      int ans = 0;
      if (a == 0) ans++;
      if (b == 0) ans++;
      if (c == 0) ans++;
      cout << "The winner is a" << ": " << pa << " + " << ans;
    } else if (a == 1 && b == 1 && c == 1) {
      cout << "The winner is b" << ": " << pb << " + " << 3;
    }
  } else {
    if (a == 1 || b == 1 || c == 1) {
      int ans = 0;
      if (a == 1) ans++;
      if (b == 1) ans++;
      if (c == 1) ans++;
      cout << "The winner is b" << ": " << pb << " + " << ans;
    } else if (a == 0 && b == 0 && c == 0) {
      cout << "The winner is a" << ": " << pa << " + " << 3;
    }
  }
  return 0;
}

