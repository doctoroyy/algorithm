#include<iostream>
#include<cstring>
using namespace std;
int main() {
  bool a[1001];
  int cnt = 0;
  memset(a, true, sizeof(a));
  for (int i = 1; i <= 1000; i++) {
    if (i % 3 == 0) {
      a[i] = !a[i];
    }
    if (i % 5 == 0) {
      a[i] = !a[i];
    }
    if (i % 7 == 0) {
      a[i] = !a[i];
    }
  }
  for (int i = 1; i <= 1000; i++) {
    if (a[i]) {
      cnt++;
    }
  }
  cout << cnt << endl;
}
