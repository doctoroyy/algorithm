#include<iostream>
using namespace std;
int main() {
  int a[100];
  for (int i = 0; i < 100; i++) {
    cin >> a[i];
  }
  int s1 = 0, s2 = 0;
  for (int i = 0; i < 100; i++) {
    while (a[i] % 5 == 0) {
      a[i] /= 5;
      s1++;
    }
    while (a[i] % 2 == 0) {
      a[i] /= 2;
      s2++;
    }
  }
  cout << min(s1, s2) << endl;
}
