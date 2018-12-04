#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e3 + 10;
int nums[maxn], flag, target, len;
void dfs(int index, int sum) {
  if (sum == target) {
    flag = 1;
    return;
  }
  if (sum > target || index >= len) return;
//  if (!flag) {
  if (nums[index] <= target)
    dfs(index + 1, sum + nums[index]);
  dfs(index + 1, sum);
//  }

}
int dp[maxn];
int main() {
  char str[maxn];
  while (gets(str)) {
    scanf("%d", &target);
    getchar();
    len = 0;
    for (int i = 0; str[i]; i++) {
      if (str[i] != ' ') nums[len++] = int(str[i] - '0');
    }
    flag = 0;
    cout << "target = " << target << endl;
    dfs(0, 0);
    printf((flag ? "Yes\n" : "No\n" ));
  }
  return 0;
}

