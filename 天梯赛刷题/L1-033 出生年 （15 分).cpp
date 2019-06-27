#include<iostream>
#include<vector>
#include<set>
using namespace std;
void find(long long num, long long n) {

  for (long long i = num; i; i++) {
    set<long long> sset;
    long long tmp = i;
    for (int i = 0; i < 4; i++) {
      sset.insert(tmp % 10);
      tmp /= 10;
    }
    if (sset.size() == n) {
      printf("%lld %04lld", i - num, i);
      return;
    }
  }
}
int main() {
  long long n, y;
  cin >> y >> n;
  find(y, n);
  return 0;
}

