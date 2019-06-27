#include<iostream>
#include<cmath>
using namespace std;
int main() {
  int n, h, w;
  cin >> n;
  while (n--) {
    cin >> h >> w;
    double w0 = (h - 100) * 1.8;
    if (fabs(w0 - w) < w0 * 0.1) {
      cout << "You are wan mei!\n";
    } else if (fabs(w0 - w) >= w0 * 0.1 && w < w0) {
      cout << "You are tai shou le!\n";
    } else if (fabs(w0 - w) >= w0 * 0.1 && w > w0){
      cout << "You are tai pang le!\n";
    }
  }
  return 0;
}

