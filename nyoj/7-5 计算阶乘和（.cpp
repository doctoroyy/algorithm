#include<iostream>
using namespace std;
int main() {
  int n, s = 1, sum = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    s *= i;
    sum += s;
  }
  cout << sum << endl;
}
