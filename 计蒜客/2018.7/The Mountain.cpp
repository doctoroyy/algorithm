#include<iostream>
using namespace std;
int main() {
  int runs, n, x[110], y[110];
  cin >> runs;
  while (runs--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }
    double area = 0;
    for (int i = 0; i < n - 1; i++) {
      area += 1.0 * (y[i] + y[i+1]) * (x[i+1] -x[i]) / 2;
    }
    cout.precision(6);
    cout << area << endl;
  }
  return 0;
}
