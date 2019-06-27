#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
bool cmp(const double &a, const double &b) {
  return a > b;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<double> v;
  while (n--) {
    double score, mins = inf, maxs = -1, sum = 0;
    for (int i = 0; i < m; i++) {
      cin >> score;
      mins = min(mins, score);
      maxs = max(maxs, score);
      sum += score;
    }
    v.push_back(sum - mins - maxs);
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = k - 1; i >= 0; i--) {
    printf("%.3lf", v[i] / (m - 2));
    if (i > 0) printf(" ");
  } 
  return 0;
}

