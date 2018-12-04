#include<iostream>
using namespace std;
const int maxn = 100;
int a[maxn];
int n, k;
void dfs(int index, int num, int times) {
  if (times == n) return;
  int next = (index - k + n) % n;
  int tmp = a[next];
  a[next] = num;
  dfs(next, tmp, times + 1);
}
int main() {
  while (cin >> n >> k) {
    for (int i = 0; i < n; i++)  a[i] = i + 1;
    k %= n;
    dfs(0, a[0], 0);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}

