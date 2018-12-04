#include<stdio.h>
#include<math.h>
#include<string.h>
const int N = 10000;
int factor[N+10];
bool prime[N+10];
int main() {
  int t, num;
  memset(prime, 1, sizeof(prime));
  memset(factor, 0, sizeof(factor));
  for (int i = 2; i <= sqrt(N); i++) {
    if (prime[i]) {
      for (int j = i*i; j <= N; j += i) {
        prime[j] = 0;
      }
    }
  }
  scanf("%d", &t);
  while (t--) {
    int sum = 1, max = -1;
      memset(factor, 0, sizeof(factor));
    for (int i = 0; i < 10; i++) {
      scanf("%d", &num);
      if (num > max) max = num;
      if (num == 1) continue;
      for (int j = 2; j <= num; j++) {
        if (prime[num]) {
          factor[num]++;
          break;
        } else {
          if (num % j == 0) {
            while (num % j == 0) {
              factor[j]++;
              num /= j;
            }
          }
        }
      }
    }
    for (int i = 2; i <= max; i++) {
      if (factor[i])
        sum *= (factor[i] + 1);
    }
    printf("%d\n", sum % 10);
  }
}
