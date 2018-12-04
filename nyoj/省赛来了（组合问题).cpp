
#include<stdio.h>
#include<iostream>
using namespace std;
int Combine(int m, int n) {
  int i, A = 1, B = 1;
  for (i = m - n + 1; i <= m; i++) {
    A *= i;
  }
  for (i = n; i >= 2; i--) {
    B *= i;
  }
  return A/B;
}
int main() {
  int a, b, count;
  while (~scanf("%d%d", &a, &b)) {
    count = 1;
    while ((a/b)>1) {
      count = count*Combine(a,b)%2013;
//      cout << "res: "<< count << endl; 
      a -= b;
    }
    printf("%d\n", count);
  }
}
