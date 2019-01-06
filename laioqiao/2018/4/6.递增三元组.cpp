#include<iostream>
#include<algorithm>
using namespace std;
const int maxsize = 100000;
int main() {
  int a[maxsize+10], b[maxsize+10], c[maxsize+10];
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (a[i] < b[i] && b[i] < c[i]) {
            sum++;
          }
        }
      }
    }
    cout << sum << endl;
  }
}
