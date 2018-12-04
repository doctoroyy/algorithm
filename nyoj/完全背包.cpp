#include<iostream>
#include<cstring>
using namespace std;
#define max(x, y) x > y ? x : y 
int dp[50010];
int main() {
  int T, M, V, c, w;
  cin >> T;
  while (T--) {
    cin >> M >> V;
    memset(dp, -0x3f3f3f, sizeof(dp));
    dp[0] = 0; 
    for (int i = 0; i < M; i++) {
      cin >> c >> w;
      for (int j = c; j <= V; j++) {
        dp[j] = max(dp[j], dp[j-c]+w);
      }
    }
    if (dp[V] < 0) {
      cout << "NO" << endl;
    } else {
      cout << dp[V] << endl;
    }
  }
}
