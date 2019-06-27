#include<iostream>
#include<map>
#include<set>
using namespace std;
int s[26];
int p[26];
int w[26];
map<string, int> mp;
int main() {
  string str[14];
  set<string> sset;
  int wordNum = 0;
  for (int i = 0; i < 14; i++) {
    cin >> str[i];
    if(str[i][0] >= '1' && str[i][0] <= '9') {
      int t = str[i][0] - '0';
      if(str[i][1] == 's') s[t] += 1;
      if(str[i][1] == 'p') p[t] += 1;
      if(str[i][1] == 'w') w[t] += 1;
    } else {
//      mp[str[i]] += 1;
      sset.insert(str[i]);
      wordNum++;
    }
  }

  //shisanyao
  int sSum = 0, pSum = 0, wSum = 0;
  for (int i = 2; i < 9; i++) {
    if(s[i] != 0)
      sSum += 1;
    if(p[i] != 0)
      pSum += 1;
    if(w[i] != 0)
      wSum += 1;
  }
  if (s[1] >= 1 && s[9] >= 1
      && p[1] >= 1 && p[9] >= 1 &&
      w[1] >= 1 && w[9] >= 1 && sset.size() == 7)   {
    if (s[1] >= 2 || s[9] >= 2 ||
        p[1] >= 2 || p[9] >= 2 ||
        w[1] >= 2 || w[9] >= 2 || wordNum == 8) {
      cout << "shisanyao!" << endl;
    } else {
      cout << "I dont know!" << endl;
    }
  } else if ((s[1] >= 3 && s[9] >= 3 && sSum == 7 && wordNum == 0)||
             (p[1] >= 3 && p[9] >= 3 && pSum == 7 && wordNum == 0)||
             (w[1] >= 3 && w[9] >= 3 && wSum == 7 && wordNum == 0)) {
    cout << "jiulianbaodeng!" << endl;
  } else {
    cout << "I dont know!" << endl;

  }
  return 0;
}
/*
1s
9s
1w
9w
1p
8p
dong
nan
xi
bei
zhong
fa
bai
zhong
*/

