#include<stdio.h>
int main() {
  int n, a[110];
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    int index = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] < a[index]) {
        index = i;
      }
    }
    int temp = a[0];
    a[0] = a[index];
    a[index] = temp;
    for (int i = 0; i < n; i++) {
      printf("%d ", a[i]);
    }
    printf("\n"); 
  }
  return 0;
}

