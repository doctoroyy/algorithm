#include<iostream>
#include<cstdio>
using namespace std;
int main() {
  double h, w;
  cin >> w >> h;
  double res = w / (h * h);
  printf("%.1lf\n", w / (h * h));
  if (res > 25) {
    cout << "PANG\n";
  } else {
    cout << "Hai Xing\n";
  }
  return 0;
}

