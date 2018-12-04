 
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio> 
using namespace std;
const int N = 2000000;
bool num[N+10];
int main() {
  memset(num, true, sizeof(num));
  num[1] = false;
  for (int i = 2; i*i <= N; i++) {
    if (num[i]) {
      for (int j = i*i; j <= N; j+=i) {
        num[j] = false;
      }
    }
  }
  int T, n;
  scanf("%d", &T);;
  while (T--) {
    scanf("%d", &n);
    int sum = 0;
    if (num[n]) printf("Yes\n");
    else {
      int sum = 0;
      for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
          if (i != n/i) {
            sum += (i + n / i);
          } else {
            sum += i;
          }
        }
      }
      printf("No %d\n", sum); 
    }
  }
}        
