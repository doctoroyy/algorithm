#include<stdio.h>
//int getRoot(int num) {
//  while (num > 9) {
//    int sum = 0;
//    while (num) {
//      sum += num % 10;
//      num /= 10;
//    }
//    num = sum;
//  }
//  return num;
//}
int get_digit_root(int n) {
  int ans = 1, pow = n;
  while (n) {
    if (n&1) ans = (ans * pow) % 9;
    pow = (pow * pow) % 9;
    n /= 2;
  }
  return ans;
}
int main() {
  int n;
  while (scanf("%d", &n), n) {
    printf("%d\n", get_digit_root(n) == 0 ? 9 : get_digit_root(n));
  }
}
