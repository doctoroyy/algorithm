#include<stdio.h>
int PrimeCal(int num) {
  int s = 1;
  for(int i = 2; i*i <= num; i++) {
    if(num%i==0) {
      num /= i;
      s *= i-1;
      while(num%i==0) {
        num /= i;
        s *= i;
      } 
    }
  }
  if(num > 1) s *= num-1;
  return s;
}
int main() {
  int num;
  while (~scanf("%d", &num)) {
    printf("%d\n", PrimeCal(num));
  }
}
