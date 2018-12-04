#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<fstream>
using namespace std;
int a[55];
int n, cnt;
//bool valid(int a[], int n) {
//  if (a[0] != 1) return false;
//  for (int i = 1; i < n; i++) {
//    if (abs(a[i] - a[i - 1]) > 2) return false;
//  }
//  return true;
//}
int vis[55];
void dfs(int index) {
  if (index == 1 && a[0] != 1) return;
  if (index > n) return;
  if (index == n) {

//    if (valid(a, n)) {
//    for (int i = 0; i < n; i++) cout << a[i] << " ";
//    cout << endl;
    cnt++;
//    }

  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      if (index > 0 && abs(i - a[index - 1]) > 2) continue;
      a[index] = i;

      vis[i] = 1;
      dfs(index + 1);
      vis[i] = 0;
    }
  }
}
int main() {
//  while (~scanf("%d", &n)) {
  ofstream fout("out.txt");
  for (n = 1; n <= 55; n++) {
    
    memset(vis, 0, sizeof(vis));
    memset(a, 0, sizeof(a));
    cnt = 0;
    dfs(0);
    printf("%d,", cnt);
//    fout << cnt << ",";
  }

//  }
  return 0;
}
/*
1思路：递推
2分析：为了简便起见，我们用Ai代表第i个数字 ， 由于A1一直是1，所以A2只能是2或3。假设dp[n]表示1->n这个序列的方案数
?????????? 1.当A2=2时，从A2到An的排列（2~n）相当于从A1到An-1的排列（1~n-1）（把每个数字都加1），一共有dp[n-1]种情况。
?????????? 2.当A2=3时，A3可能为2，4，5。
?????????????? 1、当A3=2时，A4一定等于4，此时从A4到An的排列（4~n)相当于从A1到An-3的排列（把每个数字都加3），一共有dp[n-3]种情况。
?????????????? 2、当A3=4时，不管A4取不取2，都不能形成满足题意的排列，故此种情况不可能发生。
?????????????? 3、当A3=5时，排列只可能是1 ,3, 5,7,9......10,8,6,4,2,所以一共有1种情况。
?????????? 3综上所述，dp[n]=dp[n-3]+dp[n-1]+1；(n>3)
--------------------- 


