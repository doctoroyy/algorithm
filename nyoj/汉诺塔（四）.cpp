#include<stdio.h>
#include<math.h> 
bool SquareNumber(int num) {
  for (int i = 2; i <= sqrt(num); i++) {
    if (i*i == num) return true;
  }
  return false;
}
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int no = 1;
    while (n) {
      if (SquareNumber(2 * no + 1)) {
        no++;
      } else {
        n--;
      }
    }
    printf("%d\n", no);
  }
}
