/*
曼哈顿距离 + 
推论："|x-a1| + |x-a2| + |x-a3| + ... + |x-an|有最小值
当且仅当 x等于a1,a2, ..., an的中位数" 
*/
#include<iostream>
#include<algorithm>
using namespace std; 
const int maxn = 100 + 10;
int main() {
  int runs, n;
  int x[maxn], y[maxn];
  cin >> runs;
  while (runs--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    sort(x, x + n);
    sort(y, y + n);
    int minStep = 0;
    for (int i = 0; i < n / 2; i++) {
      minStep += x[n - i - 1] - x[i] + y[n - i - 1] - y[i]; 
    }
    cout << minStep << endl; 
  }
  return 0;
}

