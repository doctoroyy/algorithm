#include<iostream>
#include<cstring>
int LCS[1010][1010];
using namespace std;
int main() {
  int N;
  cin >> N;
  while (N--) {
    char s1[1001], s2[1010];
    cin >> s1;
    int len = strlen(s1);
    int i = len, j = 0;
    while (i) s2[j++] = s1[--i];
//abczyxyz
//zyxyzcba
    memset(LCS, 0, sizeof(LCS));
    for (int i = 1; i <= len; i++) {
      for (int j = 1; j <= len; j++) {
        if (s1[i-1] == s2[j-1]) {
          LCS[i][j] = LCS[i-1][j-1] + 1;
        }
        else {
          LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
      }
    }
    cout << len - LCS[len][len] << endl;
  }
}

