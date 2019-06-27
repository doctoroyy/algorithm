#include<iostream>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long num;
    scanf("%lld", &num);
    long long cnt = 0;
    while (num > 1) {
      if (num % 10 == 0) num /= 10;
      else num += 1;
      cnt++;
    }
    printf("%lld\n", cnt);
  }
  return 0;
}

