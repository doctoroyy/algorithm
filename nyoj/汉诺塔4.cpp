#include<iostream>
#include<stack>
#include<cmath> 
using namespace std;
bool SquareNumber(int num) {
  if (num == 1) return true;
  for (int i = 2; i <= sqrt(num); i++) {
    if (i*i == num) return true;
  }
  return false;
}
int main() {
  int a[55];
  stack <int> tower[55];
  for (int n = 1; n < 55; n++) {
    int i = 0, no = 1;
    tower[0].push(0);
    while (i < n) {
      int flag = 0;
      //遍历所有已经使用的柱子 
      for (int j = 0; j <= i; j++) {
        if (SquareNumber(tower[j].top() + no)) {
          tower[j].push(no);
          no++;
          flag = 1;
          break;
        }
      }
      //使用新柱子 
      if (!flag) {
        tower[++i].push(no);
        no++;
      }
    }
    a[n] = no - 2;
  }
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << a[n] << endl;
  }
}
