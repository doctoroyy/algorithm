#include<iostream>
using namespace std;
const int maxn = 1e9 + 10;
int phi[maxn]; 
void init() {
  phi[1] = 1; 
  for (int i = 2; i < maxn; i++) {
    if (!phi[i]) {
      for (int j = i; j < maxn; j += i) {
        if (!phi[j])
          phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
}

int main() {
  init();
  int n;
  while (cin >> n)
    cout << phi[n] << endl;
  return 0;
}
