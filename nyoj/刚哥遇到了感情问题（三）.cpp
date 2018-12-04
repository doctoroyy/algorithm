#include<stdio.h>
int main() {
  int n;
  int strategy[1010] = {1};
  for (int i = 1; i <= 1000; i++) strategy[i] = i * (i - 1) + 1;
  while (scanf("%d", &n), n) {
    printf("%d\n", strategy[n]);
  }
} 
