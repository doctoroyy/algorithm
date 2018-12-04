#include<iostream>
using namespace std;
int main() {
  double sum = 0;
  for (int i = 1; ; i++) {
    sum += 1.0 / i;
    if (sum >= 15.0) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}

