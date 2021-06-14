// https://leetcode.com/problems/longest-palindromic-substring/

#include<iostream>
using namespace std;

string longestPalindrome(string s) {
  if (s.size() < 2) return s;
  int len = s.size();
  int dp[len][len];
  dp[0][0] = 1;
  for (int i = 1; i < len; i++) {
    dp[i][i - 1] = dp[i][i] = 1; // dp[i][i - 1] = 1的是为了处理长度为2的情况
  }
  int start = 0, maxLen = 0;
  for (int i = 2; i <= len; i++) {
    for (int j = 0; j <= len - i; j++) {
      if (s[j] == s[j + i - 1] && dp[j + 1][j + i - 2]) {
        dp[j][j + i - 1] = 1;
        if (i > maxLen) {
          maxLen = i;
          start = j;
        }
      }
    }
  }
  return s.substr(start, maxLen);
}

int main() {
  string s;
  cin >> s;
  cout << longestPalindrome(s) << endl;
}
