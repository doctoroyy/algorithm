/*
ÉîËÑ¸Ä½ø£º 
*/ 
#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 20 + 10;
int mallon[maxn];
int n, weight, minimum;
void dfs(int index, int sum) {
  if (sum >= weight / 2 && index != n) return; 
  if (index == n) {
//    cout << "sum : " << sum << endl;
    if (abs(weight - 2 * sum) <  minimum) minimum = abs(weight - 2 * sum);
    return;
  }
  dfs(index + 1, sum + mallon[index]);
  dfs(index + 1, sum);
}
int main() {
  while (cin >> n) {
    weight = 0;
    for (int i = 0; i < n; i++) {
      cin >> mallon[i];
      weight += mallon[i];
    }
    minimum = weight;
    dfs(0, 0);
    cout << minimum << endl;
  }
  return 0;
}

