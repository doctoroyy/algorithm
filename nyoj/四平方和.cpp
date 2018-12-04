#include<iostream>
#include<cmath>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    int t = sqrt(n);
    for (int i = 0; i < t + 1; i++) {
      for (int j = 0; j < t + 1; j++) {
        for (int k = 0; k < t + 1; k++) {
          if (i*i + j*j + k*k == n) {
            cout << i << " " << j << " " << k << endl;
            break;
          }
        }
      } 
    }
  }
}
