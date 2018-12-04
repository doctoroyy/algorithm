#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e4 + 10;
int nums[maxn], target, len;
int dp[maxn];
int main() {
  char str[maxn];
  while (gets(str)) {
    memset(dp, 0, sizeof(dp));
    scanf("%d", &target);
    getchar();
    len = 0;
    for (int i = 0; str[i]; i++) {
      if (str[i] != ' ') nums[len++] = int(str[i] - '0');
    }
    dp[0] = 1;
    for (int i = 0; i < len; i++) {
      for (int j = target; j >= nums[i]; j--) {
        if (dp[j - nums[i]] == 1) {
          dp[j] = 1;
        }
      }
    }
    printf((dp[target] ? "Yes\n" : "No\n" ));
  }
  return 0;
}

