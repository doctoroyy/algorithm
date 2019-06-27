#include<iostream>
using namespace std;
int n, m;
string str;
int getVal(char c) {
  int cnt = 0, res = 0;
  for (int i = 0, j = 0; i < n; i++) {
    if (str[i] == c) {
      cnt++;
      cout << " +1\n";
    }
    while (cnt > m) {
      if (str[j++] == c) cnt--; 
    }
    res = max(res, i - j + 1);
    cout << j << " " << i << " cnt = " << cnt <<  endl;
  }
  cout << endl;
  return res;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    cin >> n >> m;
    cin >> str;
    
    getVal('1');
    getVal('0');
//    cout << max(, ) << endl;
  }
  return 0;
}
