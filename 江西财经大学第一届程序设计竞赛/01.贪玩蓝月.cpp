#include<iostream>
using namespace std;
int main() {
  int t, n, a, b;
  string str;
  cin >> t;
  while (t--) {
    cin >> n;
    if (!n) {
      cin >> a >> b;
      cout << a + b;
    } else {
      cin >> str;
      cout << str.length();
    }
    cout << endl;
  }
}
