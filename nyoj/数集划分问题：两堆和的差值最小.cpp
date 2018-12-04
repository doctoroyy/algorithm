#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
void select(int v[], int n) {
  for (int i = n - 1; i >= n - 2; i--) {
    int temp = i;
    for (int j = i - 1; j >= 0; j--) {
      if (v[j] > v[temp]) {
        temp = j;
      }
    }
    if (v[temp] != v[i]) {
      swap(v[temp], v[i]);
    }
  }
}
int main() {
  int m, n, v[1010];
  scanf("%d", &m);
  while (m--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }
    int size = n;
    while (size != 1) {
      select(v, size);
      v[size - 2] = abs(v[size - 1] - v[size - 2]);
      size--;
    }
    printf("%d\n", v[0]);
  }
}
