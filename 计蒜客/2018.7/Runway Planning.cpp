#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int num = int(n*1.0 / 10 + 0.5);
    if (num == 0) num = 18;
    else if (num > 18) {
      if (num % 18 == 0) {
        num = 18;
      } else {
        num = num % 18;
      }
    }
    printf("%02d\n", num);
  }
  return 0;
}
