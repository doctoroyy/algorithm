#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  ios::sync_with_stdio(false);

  string str;
  int cnt = 0;
  while (cin >> str) {
    do {
      if (str.find("114514") != string::npos) cnt++;
    } while (next_permutation(str.begin(), str.end()));
    cout << cnt << endl;
  }
  return 0;
}

