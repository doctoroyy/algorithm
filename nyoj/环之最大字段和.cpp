#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 50000;
int num[maxn + 10];
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> num[i];
    }
   
    int sum = 0, Max = 0;
    for (int i = 0; i < n; i++) {
      if (sum + num[i] < 0) {
        sum = num[i];
      } else {
        sum += num[i];
      }
      if (sum > Max) Max = sum;
    }
    cout << Max << endl;
  }
  return 0;
}

