#include<iostream>
using namespace std;

int sum(int x) {
  int tmp = 0;
  while (x) {
    tmp += x % 10;
    x /= 10; 
  }
  return tmp;
} 
int main() {
  int n;
  while (~scanf("%d", &n)) {
    while (sum(n) % 4 != 0) {
      n++;
    }
    printf("%d\n", n);
  }
  
  return 0;
}

