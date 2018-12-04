#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100;
int LCS[maxn][maxn];

int main() {
  int runs;
  cin >> runs;
  while (runs--) {
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.length(), n = s2.length();
    memset(LCS, 0, sizeof(LCS));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          LCS[i][j] = LCS[i - 1][j - 1] + 1;
        } else {
          LCS[i][j] = max(LCS[i -1][j], LCS[i][j - 1]);
        }
      }
    }
    cout << LCS[m][n] << endl;
  }
  return 0;
}

