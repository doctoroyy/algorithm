#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int num[10];
void parseArr(int n) {
  int i = 0;
  while (n) {
    num[i++] = n % 10;
    n /= 10;
  }
  while (i < 6) {
    num[i++] = 0;
  }
}

bool isStandard() {
  for (int i = 0; i < 6; i++) {
    if (i + 2 < 6 && num[i] == num[i+1] && num[i+1] == num[i+2]) {
      return false;
    }
    
    if (i + 1 < 6 && abs(num[i] - num[i+1]) > 4) {
      return false;
    }
    
    if (num[i] > 6) {
      return false;
    }
  }
  return true;
}

int main() {
  int x, y, t;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    for (int i = x; i <= y; i++) {
      parseArr(i);
      if (isStandard()) {
        printf("%06d\n", i);
      }
    }
    cout << endl;
  }
}
