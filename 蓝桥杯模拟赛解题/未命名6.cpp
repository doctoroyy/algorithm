#include<iostream>
#include<cstring>
using namespace std;
const int N = 100000;

bool f(int n) {
  int a[10];
  int len = 0;
  while (n) {
    a[len++] = n % 10;
    n /= 10;
  }
  for (int i = 0; i < len; i++) {
    cout << a[i] << " ";
  }
}

int main() {
//  for (int i = 0; i < N + 10; i++) {
//    
//  }
  f(1);
}
