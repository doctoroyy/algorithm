#include<iostream>
using namespace std;
int main() {
  int t, a[1010] = {0}, n, num;
  cin >> t;
  while (t--) {
    cin >> n;
    while (n--) {
      cin >> num;
      a[num]++;
    }
  }
  int max = 0, pos;
  for (int i = 0; i < 1010; i++) {
    if (a[i] >= max) {
      max = a[i];
      pos = i;
    }
  }
  cout << pos << " " << max << endl;
}
