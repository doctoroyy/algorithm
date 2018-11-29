#include<iostream>
using namespace std;
int gcd(int m, int n) {
  return m % n ? gcd(n, m % n) : n; 
}
void fun(int a, int b) {
  while (a > 1) {
    int nextb = b / a + 1;
    cout << "1/" << nextb << "+";
    a = nextb * a - b;
    b = nextb * b;
    
    int tmp = gcd(a, b);
    a /= tmp, b /= tmp;
  }
  cout << "1/" << b << endl;
}
int main() {
  int a, b;
  while (cin >> a >> b) {
    fun(a, b);
  }
} 
