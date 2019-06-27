#include<iostream>
#include<cmath>
using namespace std;
int is_prime(long long num) {
  if (num == 0 || num == 1) return 0;
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) return 0;
  }
  return 1;
}
int main() {
  int runs;
  cin >> runs;
  while (runs--) {
    long long num;
    cin >> num;
    cout << (is_prime(num) ? "Yes\n" : "No\n");
  }
  return 0;
}
