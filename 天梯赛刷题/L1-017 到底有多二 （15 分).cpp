#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main() {
  char str[60];
  while (cin >> str) {
    int len = strlen(str), cnt = 0;
    for (int i = 0; i < len; i++) {
      if (str[i] == '2') {
        cnt++;
      }
    }
    if (str[0] == '-') {
      if ((str[len-1] - '0') % 2 == 0) {
        printf("%.2lf", double(cnt)*1.0/(len - 1)*3*100);
      } else {
        printf("%.2lf", double(cnt)*1.0/(len - 1)*1.5*100);
      }
    } else {
      if ((str[len-1] - '0') % 2 == 0) {
        printf("%.2lf", double(cnt)*1.0/len*2*100);
      } else {
        printf("%.2lf", double(cnt)*1.0/len*100);
      }
    }
    printf("%\n");
  }
}
