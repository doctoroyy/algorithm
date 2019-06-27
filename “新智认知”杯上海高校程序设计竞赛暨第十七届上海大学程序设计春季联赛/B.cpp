#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
map<char, int> order;
int cmp(string s1, string s2) {
  if (s1 == s2) return 0;
  int i = 0;
  while (s1[i] && s2[i]) {
    if (s1[i] != s2[i]) {
      if (order[s1[i]] < order[s2[i]]) {
        return -1;
      } else {
        return 1;
      }
    }
    i++;
  }
  return s1.size() < s2.size() ? -1 : 1;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 26; i++) {
    char ch;
    cin >> ch;
    order[ch] = i;
  }
  string s1, s2;
  for (int i = 0; i < n; i++) {
    cin >> s1 >> s2;
    int t = cmp(s1, s2);
    if (t == 0) {
      cout << "=";
    } else if (t == 1) {
      cout << ">";
    } else {
      cout << "<";
    }
    cout << endl;
  }
  return 0;
}
/*

3
a b c d e f g h i j k l m n o p q r s t u v w x y z
world wolf
app apple
panda panda

*/
