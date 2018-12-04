#include<iostream>
#include<algorithm>
using namespace std;
string add(string s1, string s2) {
  string res;
  int carry = 0;//进位
  if (s1.length() < s2.length()) swap(s1, s2);
//  cout << s1 << "  " << s2 << endl;
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  bool flag = false;
  for (int i = 0; i < s1.length(); i++) {
    int sum;
    if (s2[i] && !flag) {
      sum = s1[i] - '0' + s2[i] - '0' + carry;
    } else {
      flag = true;
      sum = s1[i] - '0' + carry;
      cout << " 特别地：" << s1[i] << " " << sum << endl;
    }
    if (sum > 9) {
      carry = 1;
      sum %= 10;
    } else {
      carry = 0;
    }
    cout << sum << endl;
    res.push_back(sum + '0');
  }
  if (carry > 0) res.push_back(carry + '0');
  reverse(res.begin(), res.end());
  return res;
}
int main() {
//85678978979
//5474854645646
  string s1, s2, res;
  while (cin >> s1 >> s2) {
    cout << add(s1, s2) << endl;
  }
  return 0;
}
