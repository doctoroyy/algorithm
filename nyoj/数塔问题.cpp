#include<iostream>
using namespace std;
const int maxn = 100;
int main() {
  int data[maxn][maxn], dp[maxn][maxn], n;
  while (cin >> n) {

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        cin >> data[i][j];
      }
    }
    for (int i = n; i >= 1; i--) dp[n][i] = data[n][i];

    for (int i = n - 1; i >= 1; i--) {
      for (int j = 1; j <= i; j++) {
        dp[i][j] = data[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
      }
    }
    cout << dp[1][1] << endl;

    cout << "×î´óÂ·¾¶£º" << data[1][1];
    int j = 1;
    for (int i = 2; i <= n; i++) {
      int currentNode = dp[i - 1][j] - data[i - 1][j];
      if (currentNode != dp[i][j]) j++;
      cout << "->" << data[i][j];
    }
    cout << endl;
  }


  return 0;
}

