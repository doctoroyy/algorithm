#include<iostream>
using namespace std;
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long k, n, a, b;
    scanf("%lld%lld%lld%lld", &k, &n, &a, &b);
    long long turns = (k - 1) / a;
    if (turns >= n) {
      printf("%lld\n", n);
    } else {
      long long charge = k - turns * a; 
      if (charge > b) {
        if (turns + (charge - 1) / b >= n) {
          printf("%lld\n", turns);
        } else {
          puts("-1");
        }
      } else {
        puts("-1");
      }
    }
  }
  return 0;
}

