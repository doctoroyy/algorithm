#include<stdio.h>
//char ch[] = "0123456789ABCDEF";
//
//char *conversion(int num, int ary) {
//  char str[5];
//  int len = 0;
//  while (num) {
//    str[len++] = ch[num % ary];
//    num /= ary;
//  }
//  return str;
//}
int digitsum(int num, int ary) {
  int sum = 0;
  while (num) {
    sum += num % ary;
    num /= ary;
  }
  return str;
}
int main() {
  int num;
  while (scanf("%d", &num), num) {
    printf("%d\n", digitsum(conversion(num, 16)));
//    printf("%d", '9');
  }
}
