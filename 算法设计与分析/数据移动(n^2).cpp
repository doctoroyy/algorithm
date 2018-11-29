#include<iostream>
using namespace std;
const int maxn = 100;
int a[maxn];
int main() {
  int n, k;
  while (cin >> n >> k) {
    k %= n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = k; i < n; i++) {
      for (int j = i; j > i - k; j--) {
        swap(a[j], a[j-1]);
        //cout << j << " " << j - 1 << endl; 
      }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
  }
}

