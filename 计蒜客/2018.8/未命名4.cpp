#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1000005;
int main() {
  double money;
  int n;
  scanf("%lf%d",&money,&n);
  
  double x, ans, a, b, Min;
  scanf("%lf%lf",&a,&b);
  Min = a;
  ans = (b-a)*(money/a);
  for (int i = 2; i < n; i++) {
    scanf("%lf",&x);
    if ((x - Min)*(money/Min) > ans) {
      ans = (x - Min)*(money/Min);
    }
    if (x < Min) {
      Min = x;
    } else {
      if ((x - Min)*(money/Min) > ans) {
        ans = (x - Min)*(money/Min);
      }
    }
  } 
  printf("%.2lf",ans);
  
}
