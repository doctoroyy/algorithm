#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int maxn = 1e3 + 10;
int dp[maxn][maxn];

int main() {
  string s1, s2;
  getline(cin, s1);
  for (int i = s1.size() - 1; i >= 0; i--) s2.push_back(s1[i]);
  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  
  cout << dp[s1.size()][s2.size()]; 
  
  return 0;
}

