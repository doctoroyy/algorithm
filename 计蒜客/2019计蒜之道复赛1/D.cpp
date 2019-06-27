#include<iostream>
#include<cstring>
#include<cstdio> 
using namespace std;
const int maxn = 5e6 + 10;
char out[maxn], str[maxn];
int main() {
  int k;
  scanf("%s", str);
  scanf("%d", &k);
  int len = strlen(str);
  int l = 0, r = len - k, pos = 0;
  for (int i = 0; i < k; i++) {
    char min_ch = 'z' + 1;
    for (int j = l; j <= r; j++) {
      if (str[j] == 'a') {
        min_ch = 'a';
        pos = j;
        break;
      } else {
        if (str[j] < min_ch) {
          min_ch = str[j];
          pos = j;
        }
      }
    }
    l = pos + 1, r = len - (k - (i + 1));
    out[i] = min_ch;
  }
  printf("%s", out);
  return 0;
}
