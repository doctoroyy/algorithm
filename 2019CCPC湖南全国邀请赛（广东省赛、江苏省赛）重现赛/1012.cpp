#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int a[26];
int b[26];
int main() {
  string s1, s2;
  while (cin >> s1 >> s2) {
    if (s1 == s2) {
      cout << "Equal\n";
    } else {
      memset(a, 0, sizeof(a));
      memset(b, 0, sizeof(b));
      for(int i = 0; i < s1.size(); ++i) {
        a[s1[i] - 'a'] += 1;
      }
      for(int i = 0; i < s2.size(); ++i) {
        b[s2[i] - 'a'] += 1;
      }
      bool flag = true;
      for(int i = 0; i < 26; ++i) {
        if(a[i] != b[i]) {
          flag = false;
          break;
        }
      }
      if(flag == false) {
        printf("No\n");
      } else {
        if(s1[0] == s2[0] && s1[s1.size() - 1] == s2[s2.size() - 1]) 
          printf("Yes\n");
        else 
          printf("No\n");
      } 
//      if (*s1.begin() == *s2.begin() && *s1.end() == *s2.end()) {
//        s1 = s1.substr(1, s1.size() - 2);
//        s2 = s2.substr(1, s2.size() - 2);
////        cout << s1 << " " << s2 << endl;
//        sort(s1.begin(), s1.end());
//        sort(s2.begin(), s2.end());
//        if (s1 == s2) {
//          cout << "Yes\n";
//        } else {
//          cout << "No\n";
//        }
//      } else {
//        cout << "No\n";
//      }
    }
  }
  return 0;
}

