#include<iostream>
#include<cstdio>
using namespace std;
long long a, b, c;
int valid(long long num) {
  long long res = 0, tmp = num;
  while (num) {
    res += (num % 10) * (num % 10);
    num /= 10;
  }
  return res * c == tmp;
}
int main() {
  scanf("%lld%lld%lld", &a, &b, &c);
  long long t = 0;
  for (long long i = a; i <= b; i++) {
    if (valid(i)) t++;
  }
  printf("%lld\n", t);
  
  return 0;
}

