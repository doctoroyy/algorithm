#include<stdio.h>
int main() {
//  int a[100000], b[100000];
//  int num[200010] = {0};
//  a[0] = b[0] = 0;
//  for (int i = 1; i <= 100000; i++) {
//    int j = i;
//    while (num[j] != 0) j++;
//    a[i] = j;
//    b[i] = a[i] + i;
//    num[a[i]] = num[b[i]] = 1;
//    printf("%d %d\n", a[i], b[i]);
//  }
  int n;
  while (~scanf("%d", &n)) {
    int num[200010] = {0};
    int j = 0;
    for (int i = 0; j <= n; i++) {
      if (num[i] == 0) {
        printf("(%d,%d)", i, i + j);
        num[i+j] = 1;
        j++;
      }
    }
    printf("\n");
  }
}        
