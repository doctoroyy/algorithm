#include<iostream>
#include<cstring>
using namespace std;
int main() {
  int N;
  cin >> N;
  while (N--) {
    char s1[110], s2[110];
    cin >> s1;
    int len = strlen(s1);
    int t = len, p = 0;
    while (t) s2[p++] = s1[--t];
//abczyxyz
//zyxyzcba
    int pos, j;
    for (int i = 0; i < len; i++) {
      int k = i;
      for (j = 0; j < len; j++) {
        if (s1[k] == s2[j]) {
          k++;
        } else {
          break;
        }
      }
      if (k == len) {
        pos = j;
        break;
      }
    }
    printf("%s", s1);
    for (int i = pos; i < len; i++) printf("%c", s2[i]);
    printf("\n");
  }
}

