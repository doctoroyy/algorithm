#include<iostream>
#include<cstdlib>
using namespace std;
struct Decimal {
  int a, b;
}decimal[110];
int gcd(int m, int n) {
  if (m % n == 0) return n;
  return gcd(n, m % n);
}
int lcm(int m, int n) {
  return m * n / gcd(m, n);
} 
int main() {
  int n;
  char sign;
  while (cin >> n) {
    cin >> decimal[0].a >> sign >> decimal[0].b;
    int down = decimal[0].b;
    for (int i = 1; i < n; i++) {
      cin >> decimal[i].a >> sign >> decimal[i].b;
      down = lcm(down, decimal[i].b);
    }
    int up = 0;
    for (int i = 0; i < n; i++) {
      up += down/decimal[i].b * decimal[i].a;
    }
    int tmp = up;
    up /= gcd(up, down), down /= gcd(tmp, down);
    if (abs(up) % down == 0) {
      cout << up / down << endl;
    } else {
      if (up / down != 0) {
        cout << up / down << " " << abs(up % down) << sign << abs(down) << endl;
      } else {
        cout << up << sign << down << endl;
      }
    }
  }
}
