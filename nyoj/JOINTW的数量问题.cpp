#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long dp[10][510];
int main() {
  string str, pattern= "JOINTW";
  int pattern_len = pattern.size();
  while (cin >> str) {
    int len = str.size();
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < pattern_len; i++) {
      for (int j = 0; j < len; j++) {
        if (str[j] == pattern[i]) {
          if (i == 0) {
            if (j > 0) dp[i][j] = dp[i][j-1] + 1;
            else dp[i][j] = dp[i][j] + 1;
          }
          else dp[i][j] = dp[i][j-1] + dp[i-1][j];
        } else {
          dp[i][j] = dp[i][j-1];
        }
      }
    }
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < len; j++) {
        printf("%3d", dp[i][j]);
      }
      printf("\n");
    }
//    cout << dp[pattern_len-1][len-1] << endl;
  }
}
