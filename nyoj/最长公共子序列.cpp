#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100;
int lcs = 0;
string s1, s2;
void dfs(int l1, int l2) {
  if (l1 >= s1.size() || l2 >= s2.size()) return;
  if (l1 == s1.size() - 1 && l2 == s2.size() - 1) {
    
  }
  
  
}
int main() {
  int LCS[maxn][maxn];
//  string s1, s2;
  while (cin >> s1 >> s2) {
    memset(LCS, 0, sizeof(LCS));
    for (int i = 1; i <= s1.size(); i++) {
      for (int j = 1; j <= s2.size(); j++) {
        if (s1[i-1] == s2[j-1]) {
          LCS[i][j] = LCS[i-1][j-1] + 1;
        } else {
          LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
      }
    }
    
    for (int i = 1; i <= s1.size(); i++) {
      for (int j = 1; j <= s2.size(); j++) {
        cout << LCS[i][j] << " ";
      }
      cout << endl;
      
    }
    
    cout << LCS[s1.size()][s2.size()] << endl;
  } 
  return 0;
}

