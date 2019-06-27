#include<iostream>
#include<set>
using namespace std;
int main() {
  int n, q;
  cin >> n >> q;
  set<string> sset;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    sset.insert(str);
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      string str;
      cin >> str;
      sset.insert(str);
    } else {
      cout << sset.size() << endl;
    }
  }
  return 0;
}

