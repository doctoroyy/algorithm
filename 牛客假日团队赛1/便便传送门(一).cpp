#include<iostream>
using namespace std;
const int maxn = 110, inf = 0x3f3f3f;
int a, b, x, y, min_steps = inf;
int main() {
  ios::sync_with_stdio(false);
  cin >> a >> b >> x >> y;
  int s1 = abs(a - b);
  min_steps = min(min_steps, s1);
  int s2 = abs(a - x) + abs(y - b);
  min_steps = min(min_steps, s2);
  int s3 = abs(a - y) + abs(x - b);
  min_steps = min(min_steps, s3);
  cout << min_steps << endl;
  return 0;
}
