#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn = 1010;
double distance(double x1, double y1, double x2, double y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main() {
//  cout << distance(0, 1, 1, -1);
  double posX[1010], posY[1010];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> posX[i] >> posY[i];
  }
  int index, cnt, flag = 0, k;
  double temp;
  double dis;
  for (int i = 0; i < n; i++) {
    cnt = 0, dis = 0, k = 0;;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      temp = 
      dis = distance(posX[i], posY[i], posX[j], posY[j]);
      if (dis != temp && temp != 0) cnt++;
    }

    if (cnt == 0) {
      index = i;
      flag = 1;
      break;
    }
  }
  if (!flag) cout << "-1";
  else cout << index + 1;
  cout << endl;
  return 0;
}
