#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
struct Test {
  long long review_times;
  long long time;
}test[maxn];
int cmp(const Test a, const Test b) {
  return a.time < b.time;
}
int f(int n) {
  int time0 = 0;
  for (int i = 0; i < n; i++) {
    time0 += test[i].review_times;
    if (time0 > test[i].time) {
      return 0;
    }
    time0 += 2;
  }
  return 1;
}
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> test[i].review_times;
    } 
    for (int i = 0; i < n; i++) {
      cin >> test[i].time;
    }
    sort(test, test + n, cmp);
    if (f(n)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    
  }
  return 0;
}





