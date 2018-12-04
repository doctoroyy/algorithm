#include<iostream>
using namespace std;
int a[100010];
int fun(int a[], int n) {
  int m = -10000, b = a[0];
  for (int i = 1; i < n; i++) {
    b = max(b + a[i], a[i]);
    m = max(m, b);
  }
  return m;
}
int main() {
  int n;
  while (cin >> n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    int max1 = fun(a, n);
    for (int i = 0; i < n; i++) {
      a[i] = -a[i];
    }
    int max2 = fun(a, n);
    cout << max(max1, sum + max2) << endl;
  }
} 
