#include<iostream>
using namespace std;
long long f(long long num) {
  long long sum = 0;
  for (int i = 1; i <= num; i++) {
    sum += 
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(false);
  long long l, r;
  cin >> l >> r;
  long long sum = 0;
  for (long long i = l; i <= r; i++) {
    if (f(i) % 3 == 0) {
      sum++;
    }
  }
  cout << sum << endl;
  return 0;
}

