#include<iostream>
#include<cstdio>
using namespace std;
double dis(double x1, double y1, double x2, double y2) {
  return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main() {
  double x0, y0, r, x1, y1, y2;
  cin >> x0 >> y0 >> r >> x1 >> y1 >> y2;
  double res = dis(x0, y0, x1, y1);
  printf("%.0lf", res - r * r); 
  return 0;
}

