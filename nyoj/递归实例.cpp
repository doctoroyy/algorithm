#include<iostream>
using namespace std;
int f(int n) {
  if (n == 1 || n == 2) return 1;
  return f(n-1) + f(n-2);
}
int main() {
  for (int i = 1; i < 10; i++) {
    cout << f(i) << endl;
  }
}
