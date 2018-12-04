#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  string str;
  int num[5050];
  while (cin >> str) {
    int cnt = 0;
    int sum = 0, slen = str.length();
    bool flag = false;
    for (int i = 0; i < slen; i++) {
      while (str[i] == '5') i++;
      while (str[i] != '5' && i < slen) {
        sum = sum * 10 + str[i++] - '0';
        flag = true;
      }
      if (flag) num[cnt++] = sum, flag = false, sum = 0;
    }
    if (cnt == 0) {
      cout << "0" << endl;
      continue;
    }
    sort(num, num+cnt);
    for (int i = 0; i < cnt; i++) cout << num[i] << " ";
    cout << endl;
  }
}
