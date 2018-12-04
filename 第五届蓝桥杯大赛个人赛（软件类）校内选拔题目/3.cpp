#include<iostream>
#include<cmath> 
using namespace std;
int main() {
  for (double i = 2; ; i += 0.0000001) {
    if (pow(i, i) >= 10.0) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}

