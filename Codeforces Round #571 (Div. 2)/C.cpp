#include<iostream>
#include<string>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  string a, b;
  cin >> a >> b;
  int lena = a.length(), lenb = b.length(), p, sum, ans = 0;
  for (int i = 0; i <= lena - lenb; i++) {
    sum = 0;
    for (int j = 0,p =0; j < lenb; j++, p++) {
      if ((a[i+p]^b[j]) != 0) {
        sum++;
      }
    }
    if ((sum&1) == 0) {
      ans++;
    }
  }
  cout << ans << endl;
  
  return 0;
}

