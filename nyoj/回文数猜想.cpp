#include<stdio.h>
bool Huiwen(long long n) {
  int a[100], i = 0;
  while (n) {
    a[i++] = n % 10;
    n /= 10;
  }
  for (int j = 0; j < i / 2; j++)
    if (a[j] != a[i-1-j]) return false;
  return true;
}
long long reverse(long long num) {
  long long sum = 0;
  while (num) {
    sum = sum * 10 + num % 10;
    num /= 10; 
  }
  return sum;
}
int main() {
  long long n;
  while (~scanf("%lld", &n)) {
    long long changenum[1000] = {0};
    int count = 0; 
    changenum[0] = n;
    while (!Huiwen(changenum[count])) {
      changenum[++count] = changenum[count-1] + reverse(changenum[count-1]);
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) printf("%lld--->", changenum[i]);
    printf("%lld\n", changenum[count]);
  }
}
