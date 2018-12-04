#include<iostream>
using namespace std;
int f(int n, int m) {
	if (m==1 || n==1 || n==0) return 1;
	if (n < m) return f(n, n);
	return f(n, m - 1) + f(n - m, m);
}

int main() {
  int n, k;
  while (cin >> n >> k) {
    cout << f(n, k) << endl;
  }
}
