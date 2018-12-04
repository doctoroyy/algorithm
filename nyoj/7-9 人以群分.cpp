#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100000];
bool cmp(int a, int b) {
  return a > b;
}
int main() {
  int n;
  while (cin >> n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a, a + n, cmp);
    int sum1 = 0;
    for (int i = 0; i < (n - 1) / 2 + 1; i++) {
      sum1 += a[i];
    }
    cout << "Outgoing #: " << (n - 1) / 2 + 1 << "\n" 
    << "Introverted #: " << n / 2 << "\n" << "Diff = " << sum1 - (sum - sum1) << endl;
  }
}
