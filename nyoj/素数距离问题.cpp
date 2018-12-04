#include<stdio.h>
#include<math.h>
int isprime(int n) {
  if (n == 1) return 0;
  int k = sqrt(n);
  for (int i = 2; i <= k; i++)
    if (n % i == 0) return 0;
  return 1;
}
int main() {
  int x, i = 0, j = 0, u = 0, o;
  int b[1024], a[1024], k;
  int t;
  scanf("%d", &t);
  while(t--) {
    int distance = 0;
    scanf("%d", &x);
    for(int n = x - 10; n <= x + 10; n++)
      if (isprime(n))
        a[i++] = n;
    for(u = 0; u < i; u++)
      b[u] = abs(a[u] - x);
    int min = b[0];
    for(o = 1; o < i; o++)
      if(min > b[o]) {
        min = b[o];
        k = o;
      }
    distance = abs(a[k] - x);
    printf("%d %d\n", a[k], distance);
  }
}
