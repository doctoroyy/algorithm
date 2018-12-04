#include<stdio.h>
int main() {
  int t, n, op, num[410], x;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int head = 200, size = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &op, &x);
      if (op == 0) {
        num[head--] = x;
        size++;
      } else if (op == 1) {
        num[head+size+1] = x;
        size++;
      } else if (op == 2) {
        head++;
        size--;
      } else {
//        tail--;
        size--;
      }
    }
    for (int i = head+1; i <= head + size; i++) printf("%d ", num[i]);
  }
}
