#include<iostream>
using namespace std;
const int maxn = 100 + 10;
int a[maxn], b[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int flag = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] == a[j] + b[j] && a[j] == a[i] + b[i]) {
        flag = 1;
        break;
      }
    }
    if (flag) break;
  }
  if (flag) cout << "YE5\n";
  else cout << "N0\n"; 
  return 0;
}

